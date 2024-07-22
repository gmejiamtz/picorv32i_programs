#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Function to perform heap sort using std::priority_queue
void heapSort(std::vector<int>& arr) {
    // Create a max-heap using std::priority_queue
    std::priority_queue<int> maxHeap;

    // Insert all elements of the array into the heap
    for (int num : arr) {
        maxHeap.push(num);
    }

    // Extract elements from the heap in sorted order
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = maxHeap.top();
        maxHeap.pop();
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {5, 3, 17, 10, 84, 19, 6, 22, 9};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array using heap sort
    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

