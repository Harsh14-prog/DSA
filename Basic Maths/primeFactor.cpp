#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false; // so we got 2 factors here which devides n hence stop
    }
    return true;
}

int main()
{

    int n = 780;

    for (int i = 2; i*i <= n; i++) // to dry run do i <= root of n
    {
        while (n % i == 0)
        {
            if (isPrime(i))
            {
                cout << i << endl;
                 n = n/i ;
            }

        }
       
    }
    if (n > 1){
        cout << n ;
    }

}