#include <iostream>
#include <iomanip>
using namespace std;


double sqrtWithPrecision(int num, int precision = 4) {
    int start = 0, end = num;
    double ans = 0.0;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid * 1LL * mid == num) {
            return mid;
        }
        if (mid * 1LL * mid < num) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    double increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while ((ans + increment) * (ans + increment) <= num) {
            ans += increment;
        }
        increment /= 10;
    }

    return ans;
}

int main() {
    int num;
    cout << "Enter Any Number: ";
    cin >> num;

    double result = sqrtWithPrecision(num, 4);
    cout << fixed << setprecision(4);
    cout << "Square Root of " << num << " is: " << result << endl;

    return 0;
}
