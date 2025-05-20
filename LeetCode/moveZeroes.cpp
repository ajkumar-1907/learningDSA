#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums){

    int i = 0;

    for(int j=0; j<nums.size(); j++){

        if( nums[j] != 0 ){
            swap(nums[j], nums[i]);
            i++;
        }
    }
};

void print(const vector<int>& nums){
    for(int num : nums){
        cout<<num<<" ";

    }cout<<endl;
}

int main(){

    vector<int> nums = {0, 1, 7, 6, 0, 8, 0};

    cout<<"Before moving zeroes : ";
    print(nums);

    moveZeroes(nums);

    cout<<"After moving Zeroes : ";
    print(nums);

    return 0;
}