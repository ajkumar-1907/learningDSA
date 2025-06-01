#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate square root using Newton-Raphson method
double sqrt(double n) {
    double x = n;
    double root;

    while (true) {
        root = 0.5 * (x + (n / x));
        if (fabs(root - x) < 0.5)
            break;
        x = root;
    }

    return root;
}

int main() {
    double num = 40;

    cout << "Square Root of " << num << " is: " << sqrt(num) << endl;

    return 0;
}
