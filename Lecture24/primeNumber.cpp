#include <iostream>
using namespace std;

// Function to check if a number is prime
string isPrime(int num) {
    if (num == 0)
        return "Neither Prime Nor Composite";
    if (num < 0)
        return "Not Prime";
    if (num == 1)
        return "Not Prime";
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return "Not Prime";
    }
    return "Prime";
}

int main() {
    int num;
    
    cout << "Enter Any Number: ";
    cin >> num;

    cout << num << " is " << isPrime(num) << endl;

    return 0;
}
