#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex counterMutex;
int sharedCounter = 0;

void incrementCounter(int threadId) {
    unique_lock<mutex> lock(counterMutex);

    cout << "Thread " << threadId << " enters critical section." << endl;

    for (int i = 0; i < 1000000; ++i) {
        sharedCounter++;
    }

    cout << "Thread " << threadId << " leaves critical section." << endl;
}

int main() {
    const int numThreads = 2;
    thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(incrementCounter, i + 1);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    cout << "Final counter value: " << sharedCounter << endl;

    return 0;
}
