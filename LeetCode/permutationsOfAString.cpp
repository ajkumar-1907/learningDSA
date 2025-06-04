#include<iostream>
#include<vector>

using namespace std;


void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
    //base case
    if(index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);

        // Backtrack
        swap(nums[index], nums[j]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4 ,5, 6, 7};
    vector<vector<int>> ans;

    solve(nums, ans, 0);

    // Print all permutations
    for(const auto& permutation : ans) {
        for(int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Print total number of permutations
    cout << "\nTotal number of permutations: " << ans.size() << endl;

    return 0;
}
