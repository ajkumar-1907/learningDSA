#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n - 1; i++)  // For every index i
    {
        int minIndex = i;  // Assume current index i is the smallest
        
        // Compare with all next elements
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;  // Found smaller element, update minIndex
            }
        }

        // Swap if minIndex changed (found smaller element)
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main()
{
    vector<int> arr = {6, 2, 8, 4, 10};
    int n = arr.size();

    selectionSort(arr, n);

    // Print sorted array
    cout << "Sorted array: ";
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
