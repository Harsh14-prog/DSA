#include <iostream>
using namespace std;

int main() {

    int a = 52;
    int b = 10;

    int originalA = a;   // store original values to calculate LCM later
    int originalB = b;

    int gcd = 1;

    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) {
        gcd = b;
    } else {
        gcd = a;
    }

    int lcm = (originalA * originalB) / gcd;

    cout << "GCD: " << gcd << endl;
    cout << "LCM: " << lcm << endl;

}
