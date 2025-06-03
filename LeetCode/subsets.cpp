#include <iostream>
#include <vector>

using namespace std;


void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
    // Base case
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude current element
    solve(nums, output, index + 1, ans);

    // Include current element
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}



vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main() {
    vector<int> nums;
    int n, element;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> element;
        nums.push_back(element);
    }

    vector<vector<int>> result = subsets(nums);

    cout << "\nAll subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}
