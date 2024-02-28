#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
using ull = unsigned long long;

mutex mtx;

ull fact(int n) {
    ull result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

ull* calculateFibonacci(int n) {
    ull* fibSeq = new ull[n];
    fibSeq[0] = 0;
    fibSeq[1] = 1;
    for (int i = 2; i < n; ++i) {
        fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
    }
    return fibSeq;
}

void Factorial(int n) {
    lock_guard<mutex> lock(mtx);
    cout << "Factorial of " << n << ": " << fact(n) << endl;
}

void fibonacci(int n) {
    ull* fibSeq = calculateFibonacci(n);
    
    lock_guard<mutex> lock(mtx);
    cout << "Fibonacci Sequence up to " << n << " terms: ";
    for (int i = 0; i < n; ++i) {
        cout << fibSeq[i] << "\t";
    }
    cout << endl;

    delete[] fibSeq;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    thread factorialThread(Factorial, num);
    thread fibboThread(fibonacci, num);
    
    factorialThread.join();
    fibboThread.join();

    return 0;
}
