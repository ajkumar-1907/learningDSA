//checking if arrayy is Sorted and Rotated

#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int>& nums){

    int count = 0;
    int n = nums.size();

    for(int i = 1; i<n; i++){
        if(nums[i-1] > nums[i]){
            count++;
        }
    }

    if(nums[n-1] > nums[0])
        count++;

    return count<=1;
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};   // True: Sorted and rotated
    vector<int> nums2 = {2, 1, 3, 4};      // False
    vector<int> nums3 = {1, 2, 3, 4, 5};   // True: Sorted (not rotated, but still valid)

    cout << "Array 1 is sorted and rotated: " << (check(nums1) ? "Yes" : "No") << endl;
    cout << "Array 2 is sorted and rotated: " << (check(nums2) ? "Yes" : "No") << endl;
    cout << "Array 3 is sorted and rotated: " << (check(nums3) ? "Yes" : "No") << endl;

    return 0;
}