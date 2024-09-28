#include <stdio.h>
#include <pthread.h>

#define SIZE 1000000
#define NUM_THREADS 4
//#define NUM_THREADS 3
//#define NUM_THREADS 2
//#define NUM_THREADS 1

long long int arr[SIZE];
long long int partialSums[NUM_THREADS] = {0}; // Array to store partial sums for each thread

// Entry function for each thread
void* sumPart(void* arg) {
    // Divide the work for each thread based on their id and let them compute partial sums
    int thread_id = *(int*)arg;
    int start = thread_id * (SIZE / NUM_THREADS);  // Define range start 
    int end = (thread_id + 1) * (SIZE / NUM_THREADS);  // Define range end
    for (int i = start; i < end; i++) {
       partialSums[thread_id] += arr[i];
    }
}

int main() {
    // Initialize the array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads to compute partial sums
        for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sumPart, &thread_ids[i]);
    }

    // Wait for all threads to finish
     for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Combine the partial sums from all threads
     long long int totalSum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        printf ("partialSum[%d]:", i);
        printf ("%lli\n", partialSums[i]);
        totalSum += partialSums[i];
    }

    printf("Total Sum: %lli\n", totalSum);

    return 0;
}
