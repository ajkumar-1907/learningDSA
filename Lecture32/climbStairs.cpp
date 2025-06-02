#include<iostream>
using namespace std;

int countDistinctWayToClimbStair(long long nStairs) {
    // Base cases
    if(nStairs < 0)
        return 0;
    
    if(nStairs == 0)
        return 1;
    
    // Recursive calls
    int ans = countDistinctWayToClimbStair(nStairs - 1) 
            + countDistinctWayToClimbStair(nStairs - 2);
    
    return ans;
}

int main() {
    long long stairs;
    cout << "Enter number of stairs: ";
    cin >> stairs;

    int ways = countDistinctWayToClimbStair(stairs);
    cout << "Number of distinct ways to climb " << stairs << " stairs: " << ways << endl;

    return 0;
}
