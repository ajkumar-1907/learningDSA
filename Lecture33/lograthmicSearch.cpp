#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search (logarithmic search)
int logarithmicSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1; // Target not found
}

int main() {
    vector<int> sortedArray = {3, 8, 15, 21, 27, 34, 42, 56, 67};
    int target = 34;

    int result = logarithmicSearch(sortedArray, target);

    if (result != -1)
        cout << "Element " << target << " found at index: " << result << endl;
    else
        cout << "Element " << target << " not found in array." << endl;

    return 0;
}
