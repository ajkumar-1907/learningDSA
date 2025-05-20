#include<iostream>

using namespace std;

int findUnique(int *arr, int size) {
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans ^= arr[i];
    }
    return ans;
}

int main(){

    int arr[] = {1, 2, 3, 2, 1};
    int size = 5;

    int unique = findUnique(arr, size);

    cout<<"Unique element is : "<<unique <<endl;

    return 0;
}
