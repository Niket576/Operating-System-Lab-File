#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

// Shared variables
atomic<int> flag[2] = {0, 0}; // Flag array to indicate the intention of entering the critical section
atomic<int> turn = 0; // Indicates whose turn it is to enter the critical section

const int NUM_THREADS = 2;
const int NUM_ITERATIONS = 5;

// Function executed by the threads
void dekker(int id) {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        // Entry section
        flag[id] = 1; // Signal intention to enter critical section
        while (flag[1 - id] == 1) { // Wait while the other thread is in the critical section
            if (turn != id) { // If it's not our turn, reset our flag
                flag[id] = 0;
                while (turn != id) {} // Wait until it's our turn
                flag[id] = 1; // Signal intention to enter critical section
            }
        }

        // Critical section
        cout << "Thread " << id << " is in the critical section." << endl;

        // Exit section
        turn = 1 - id; // Pass the turn to the other thread
        flag[id] = 0; // Reset our flag
        // Remainder section
    }
}

int main() {
    thread t[NUM_THREADS];
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        t[i] = thread(dekker, i);
    }
    
    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        t[i].join();
    }
    
    return 0;
}
