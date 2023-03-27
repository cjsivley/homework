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

std::mutex clockMutex;
std::condition_variable clockTick;

std::mutex waitChairsCanBeAccessed;

std::mutex barberChair;
std::condition_variable wakeUp;

//global variables
int barberSeat = 0;
int maxSeats = 5;
int availableSeats = 5;
int customersWaiting = 0;
int missedCustomers = 0;
int counter = 10;

std::mutex m;
std::condition_variable cv;
std::string data;

void worker_thread()
{
    while (counter) {
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk);

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
    --counter;
    std::cout << "counter decremented in worker\n";
    }
}

int main()
{
    std::thread worker(worker_thread);
    while (counter) {
        data = "Example data";
        // send data to the worker thread
        {
            std::lock_guard<std::mutex> lk(m);
            std::cout << "main() signals data ready for processing\n";
        }
        cv.notify_one();

        // wait for the worker
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk);
        }
        std::cout << "Back in main(), data = " << data << '\n';
    }
    worker.join();
    std::cout << "Worker Joined.";
}