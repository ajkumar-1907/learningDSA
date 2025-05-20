#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    
    //XOR all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}

int main(){

    vector<int> arr = {1, 3, 4, 2, 2};

    int duplicate = findDuplicate(arr);

    cout << "Duplicate element is : " << duplicate << endl;

    return 0;
}