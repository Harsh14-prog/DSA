#include <iostream>
using namespace std;

int main() {
    int n = 13;
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;   // checked 1st factor
            if (i != n / i) count++;  // 2nd factor
        }
    }

    if (count > 2)
        cout << n << " is not a prime number.\n";
    else
        cout << n << " is a prime number.\n";

    return 0;
}
