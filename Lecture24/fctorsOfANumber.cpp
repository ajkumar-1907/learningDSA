#include <iostream>
using namespace std;

// Function to print all factors of a number
void factors(int num) {
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int num = 40;
    factors(num);
    return 0;
}
