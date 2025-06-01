#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;

    for (int col = 0; col < mCols; col++) {
        if (col & 1) {
            // Odd index -> Bottom to top
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // Even index -> Top to bottom
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int nRows = matrix.size();
    int mCols = matrix[0].size();

    vector<int> result = wavePrint(matrix, nRows, mCols);

    cout << "Wave Print (Column-wise Zigzag): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
