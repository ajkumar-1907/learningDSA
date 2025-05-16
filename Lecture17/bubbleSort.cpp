#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n)
{
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {2, 5, 6, 17, 9, 10, 3, 69, 8};
    int n = arr.size();

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
