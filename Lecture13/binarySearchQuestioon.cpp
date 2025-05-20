#include <iostream>
#include <vector>

using namespace std;

int firstOcc(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1; // look left for first occurrence
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {
    int s = 0, e = n - 1;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1; // look right for last occurrence
        }
        else if (key > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    return { firstOcc(arr, n, k), lastOcc(arr, n, k) };
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    int key = 3;
    int n = arr.size();

    pair<int, int> result = firstAndLastPosition(arr, n, key);

    cout << "First Occurrence: " << result.first << endl;
    cout << "Last Occurrence: " << result.second << endl;

    return 0;
}
