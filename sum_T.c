#include <stdio.h>
#include <pthread.h>

#define SIZE 1000000
#define NUM_THREADS 4

int arr[SIZE];
int partialSums[NUM_THREADS] = {0}; // Array to store partial sums for each thread

// Entry function for each thread
void* sumPart(void* arg) {
    // Divide the work for each thread based on their id and let them compute partial sums
        // -----> Write your code here
}

int main() {
    // Initialize the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int d = SIZE % NUM_THREADS; // divide the total size into how many threads is wanted. If SIZE doesn't cleanly divide by NUM_THREAD, then the last thread will do the extra work.

    // Create threads to compute partial sums
        // ------> Write your code here

    // Wait for all threads to finish
        // -------> Write your code here

    // Combine the partial sums from all threads
    int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        totalSum += partialSums[i];
    }

    printf("Total Sum: %d\n", totalSum);

    return 0;
}
