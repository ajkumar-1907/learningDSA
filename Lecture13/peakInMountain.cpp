#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Peak lies to the right
            s = mid + 1;
        } else {
            // Peak lies to the left or at mid
            e = mid;
        }
    }

    return s;
}

int main() {
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2};
    int peak = peakIndexInMountainArray(mountain);
    cout << "Peak Index: " << peak << endl; //output: 3
    return 0;
}
