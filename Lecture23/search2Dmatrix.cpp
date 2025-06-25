#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / col][mid % col];

        if (element == target) {
            return true;
        }
        else if (element < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    if (searchMatrix(matrix, target)) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
