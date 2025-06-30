#include <iostream>
using namespace std;

double power(int x, int n) {
    double ans = 1.0;
    long long exp = abs(n); // support large abs(n)
    double base = x;        // preserve original x

    while (exp != 0) {
        if (exp % 2 != 0) {
            ans = ans *  base;
            exp = exp - 1;
        } else {
            base = base *  base;
            exp /= 2;
        }
    }

    if (n < 0) {
        return 1.0 / ans;   
    }

    return ans;
}

int main() {
    int x = 2;
    int n = 5;

    double ans = power(x, n);
    cout << ans << endl;  

}
