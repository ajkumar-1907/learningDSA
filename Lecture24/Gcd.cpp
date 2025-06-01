#include <iostream>
using namespace std;

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int a = 4;
    int b = 9;

    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;

    return 0;
}
