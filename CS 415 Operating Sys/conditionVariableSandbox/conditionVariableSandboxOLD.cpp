// conditionVariableSandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <random>
#include <thread>
#include <string>
#include <sstream>
#include <deque>
#include <chrono>
#include <fstream>
#include <mutex>
#include <condition_variable>

//mutex stuff
std::mutex chairLock;
std::condition_variable wakeUp;

std::mutex clockMutex;
std::condition_variable clockTick;

//condition tracking

void barber(int currentTime) {
	std::unique_lock<std::mutex> clockLock(clockMutex);
	std::cout << "Barber: Waiting on clock." << std::endl;
	clockTick.wait(clockLock);
	std::cout << "Barber: clock triggered.\nwaiting on input" << std::endl;

	std::unique_lock<std::mutex> locker(chairLock);
	wakeUp.wait(locker);
	std::cout << "inside barber thread." << std::endl;
	//wait for clockTick
	//if barber chair !empty
	//decrement customer hair counter

	//else if chair empty && customers waiting
	//pop customer from queue
	//update time waiting total, customers served counter

	//else nap until customers waiting
	//wait for wakeup (condition variable) wakeUp.wait(chairLock,)(clockTick is ignored until we wakeUp)
	return;
}

void secondary() {
	std::unique_lock<std::mutex> clockLock2(clockMutex);
	std::cout << "Secondary: Waiting on clock." << std::endl;
	clockTick.wait(clockLock2);
	std::cout << "Secondary: clock triggered.\nSecondary: Done" << std::endl;

	return;
}
int main() {
	std::thread controller([&]() {
		int junk;
		std::cout << "Barber Thread start." << std::endl;
		std::thread barberThread(&barber, 99);
		std::thread secondaryThread(&secondary);
		std::cout << "Barber Thread waiting..." << std::endl;
		std::cout << "Secondary Thread waiting..." << std::endl;
		std::cin >> junk;
		clockTick.notify_all();
		secondaryThread.join();
		std::cout << "Secondary Thread done." << std::endl;
		std::cin >> junk;
		wakeUp.notify_all();
		barberThread.join();
		std::cout << "Barber Thread done." << std::endl;

		return 0;
		});
	controller.join();
	return 0;
	
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
