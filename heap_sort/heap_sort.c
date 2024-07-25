#include "firmware/firmware.h"

#define ARRAY_SIZE 10000

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with root at given index
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Generate an array of 10,000 integers (for simplicity, we use a simple pattern)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = ARRAY_SIZE - i;
    }

    // Display the first 10 elements of the original array for brevity
    print_str("Original array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        print_dec(arr[i]);
	print_chr(' ');
    }
    print_chr('\n');

    // Sort the array using heap sort
    heapSort(arr, ARRAY_SIZE);

    // Display the first 10 elements of the sorted array for brevity
    print_str("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        print_dec(arr[i]);
    }
    print_chr('\n');

    return 0;
}

