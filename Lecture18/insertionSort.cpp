#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {9, 5, 1, 4, 3};
    int n = arr.size();

    insertionSort(arr, n);

    cout << "Sorted array : ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
