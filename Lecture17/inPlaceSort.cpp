//An in-place sorting algorithm is a sorting method that uses a constant 
//or minimal extra space—usually O(1) or O(log n)—besides the input
//array itself.

//In in-place sorting, the sorting happens by modifying the original array
//directly without using additional data structures
//like another array, list, etc.

//Bubble Sort is an in-place sort:
//Because it directly swaps elements inside the given array, it doesn't create or need an extra array.

#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swapping inside the same array
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    bubbleSort(arr, arr.size());

    cout << "In-place sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
