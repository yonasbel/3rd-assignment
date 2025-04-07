#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid; // Element found
        if (arr[mid] < target) left = mid + 1; // Search right half
        else right = mid - 1; // Search left half
    }
    return -1; // Element not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1; // Base condition

    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) return mid; // Element found
    if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, right, target); // Search right half
    else return binarySearchRecursive(arr, left, mid - 1, target); // Search left half
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    // Iterative Binary Search
    int iterativeResult = binarySearchIterative(arr, size, target);
    if (iterativeResult != -1)
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    else
        cout << "Iterative: Element not found" << endl;

    // Recursive Binary Search
    int recursiveResult = binarySearchRecursive(arr, 0, size - 1, target);
    if (recursiveResult != -1)
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    else
        cout << "Recursive: Element not found" << endl;

    return 0;
}