// ThreadTimingSandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
std::condition_variable clockTick;

//condition tracking


void barber(int &currentTime) {
	//wait for clockTick
	//if barber chair !empty
	//decrement customer hair counter

	//else if chair empty && customers waiting
	//pop customer from queue
	//update time waiting total, customers served counter

	//else nap until customers waiting
	//wait for wakeup (condition variable) wakeUp.wait(chairLock,)(clockTick is ignored until we wakeUp)

	//go back to clock tick
	while (currentTime > 0) {
		std::cout << "Barber: " << currentTime << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //wait for buffers to clear.
	}
	return;
}

void customer(int &currentTime) {
	//wait for clockTick
	//random to see if customer arrives
	//if room, create new and give seat
	//otherwise leave, increment missed counter

	//if customer waiting && barber asleep, trigger wakeUp condition variable
	//go back to wait for clockTick
	while (&currentTime > 0) {
		std::cout << "Customer: " << &currentTime << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //wait for buffers to clear.
	}
	return;
}
void clockManager(int &currentTime) {
	while (currentTime > 0) {
		currentTime = currentTime - 1;
		std::cout << "Clock: " << currentTime << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(7000)); //wait for buffers to clear.
	}
	return;
}

void threadDriver(int &currentTime) {
	std::thread threads[3];
	threads[0] = std::thread(&barber, &currentTime);
	threads[1] = std::thread(&customer, &currentTime);
	threads[2] = std::thread(&clockManager, &currentTime);

	for (int i = 0; i < 3; i++) {
		threads[i].join();
		std::cout << "Thread " << i << " joined." << std::endl;
	}
	std::cout << "Done." << std::endl;
}

int main()
{
	int currentTime = 100;
	threadDriver(currentTime);
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
