// EvilBarbershop.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Codey Sivley Programming Project 3: Barbershop of Evilllllllll
// CS415 OpSys Spring 2022
// For Dr. Lewis

//Assignment requirements:
//mutex barberReady
//mutex waitChairsCanBeAccessed
//condition variable readyCustomers
//variable seatsAvailable
//outputs:
//random runtime between 100 and 1000 intervals
//print num customers groomed
//print num customers left

#include <iostream> 
#include <random>
#include <thread>
#include <string>
#include <sstream>
#include <deque>
#include <chrono>
#include <fstream>
#include <mutex>


//Some Global Vars for tweaking
const int MIN_CUT_TIME = 5;
const int MAX_CUT_TIME = 30;
const int CHAIRS = 5;

//What is a customer?
class Customer {
private:
	int minsWaiting; //how long the customer has been waiting
	int cutMins; //how long the customer needs to finish his haircut, randomly generated
public:
	//getters
	int getWait() { return minsWaiting; }
	int getCutMins() { return cutMins; }
	//mutators
	void waitAMinute() { ++minsWaiting; }
	void cutting() { --cutMins; }

	//constructor
	Customer(int randVal) {
		minsWaiting = 0;
		cutMins = randVal;
	}
	//no destructor or copy constructor since we're not getting silly with pointers.
};

//control flow
//random selection for length of day
//start up the day: barber is asleep
//customer flow start
//each step, gen if a customer arrives
//

//the clock
void workday(int mins) {
	//setup randos
	std::random_device rd{}; //init random seed
	std::mt19937 gen{ rd() }; //mersenne twister from seed
	std::poisson_distribution<> pD(3.0);
	std::normal_distribution<> nD(5.0, 3.0);
	std::uniform_int_distribution<int> uD(1, 10);

	//each tick
	//customer thread
	//barber thread
	//
}

void Barber() {

}

//input sim
void simulateInput(int rate)
{
	std::random_device rd{}; //init random seed
	std::mt19937 gen{ rd() }; //mersenne twister from seed
	std::poisson_distribution<> pD(rate);
	std::normal_distribution<> nD(5.0, 3.0);
	std::uniform_int_distribution<int> uD(1, 10);
	auto startClock = std::chrono::steady_clock::now();
	auto currentClock = std::chrono::steady_clock::now();
	std::chrono::duration<double> delta = currentClock - startClock;
	while (delta.count() < RUNTIME) //instead of infinite loop, runs for user set runtime
	{
	int numberEvents = pD(gen);
	if (numberEvents > 0)
	{
	for (int i = 0; i < numberEvents; ++i)
	{
	std::stringstream sampleStream;
	int deviceNumber = uD(gen);
	float sample = nD(gen);
	count++;
	{//mutex lock
	std::lock_guard<std::mutex> writeLock(writeMTX);
   sampleStream << count << " " << deviceNumber << " " <<
   sample;
   //std::cout << sampleStream.str() << std::endl; //for debugging
   inputQueue.push_front(sampleStream.str()); //critical section, write to queue
   }//mutex unlock
   }
   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }
   currentClock = std::chrono::steady_clock::now();
   delta = currentClock - startClock; //update time passed
	}
		//send exit to processData by stuffing buffer with 999s
	for (int i = 0; i < 11; ++i)
	{
		std::stringstream sampleStream;
		{//mutex lock
			std::lock_guard<std::mutex> writeLock(writeMTX);
			sampleStream << count << " " << 999 << " " << 999;
			inputQueue.push_front(sampleStream.str()); //critical section, write to queue
		}//mutex unlock
	}
}
//for processData, referenced: https://en.cppreference.com/w/cpp/thread/scoped_lock
// and changed project C++ standard from C++14 to C++17
void processData(int devNum) {
	std::ofstream dataStream; //no need to read, just output
	bool keepProcessing = true;
	std::string fileName = "device" + std::to_string(devNum) + ".txt";
	int count;
	int device;
	float value;
	dataStream.open(fileName);
	while (keepProcessing) {
		{ //scope lock
			std::scoped_lock bothLocks{ readMTX, writeMTX }; //lock outside, locking inside causes race condition on back()
				if (!inputQueue.empty()) {
					std::string sample = inputQueue.back();
					std::stringstream sampleStringStream(sample);
					sampleStringStream >> count >> device >> value;
					if (device != 999) {
						if (devNum == device) {
							inputQueue.pop_back();
							dataStream << sample << std::endl;
						}
					}
					else {
						std::cout << "Device " << devNum << " has seen exit message." << std::endl;
						keepProcessing = false;
					}
				}
		}//end scope lock to check for updates.
	}
	dataStream.close();
}
void multithreadDriver() {

	std::thread threads[11]; //1 simulate input, 10 readers
	threads[0] = std::thread(&simulateInput, RATE);
	for (int i = 1; i < 11; ++i) {
		threads[i] = std::thread(&processData, i);
	}
	threads[0].join(); //input thread ends
	std::cout << "Input thread ended." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000)); //wait for buffers to clear.
		std::cout << "Attempt close buffers." << std::endl;
	for (int i = 1; i < 11; ++i) {
		threads[i].join();
		std::cout << "Thread " << i << " closed." << std::endl;
	}
}
int main()
{
	std::cout << "Multithread start: " << std::endl;
	multithreadDriver();
	std::cout << "Multithread end." << std::endl;
	return 0;
}
