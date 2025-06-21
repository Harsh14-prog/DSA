#include <iostream>
using namespace std;

double preciseSqrt(int n, int precision = 3)
{
    int s = 0, e = n;
    long long mid;
    int ans = 0;

    // Step 1: Binary Search for Integer Part
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        long long sq = 1LL * mid * mid;

        if (sq == n)
            return mid;
        else if (sq < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    // Step 2: Decimal Expansion
    double root = ans;
    double step = 0.1;

    for (int i = 0; i < precision; i++)
    {   // We are always checking one step ahead, and only adding step when 
        //we’re still below the true sqrt.
        while ((root + step) * (root + step) <= n)
        {
            root += step;
        }
        step /= 10;
    }
    return root; 
}

int main()
{
    int n = 28;
    double result = preciseSqrt(n, 3); // 3 digits after decimal
    cout << fixed;
    cout.precision(3);
    cout << result << endl; // Output: 5.291
    return 0;
}
