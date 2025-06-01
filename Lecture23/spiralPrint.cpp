#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    if (row == 0) return ans;
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    // Index initialisation
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total) {
        // Traverse starting row
        for (int index = startingCol; count < total && index <= endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // Traverse ending column
        for (int index = startingRow; count < total && index <= endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse ending row
        for (int index = endingCol; count < total && index >= startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // Traverse starting column
        for (int index = endingRow; count < total && index >= startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
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

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
