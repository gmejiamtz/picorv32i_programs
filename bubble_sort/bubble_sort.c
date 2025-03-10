#include "firmware/firmware.h"

#define ARRAY_SIZE 4096
//array held in speacial mem section of ram
int arr[ARRAY_SIZE] __attribute__((section(".sorter_section")));

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Main function
void main() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = (ARRAY_SIZE - i);  // Reverse order for worst-case scenario
    }
    bubbleSort(arr, ARRAY_SIZE);
    //call the uart module here for all items in the 
}
