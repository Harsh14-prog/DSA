#include <iostream>
using namespace std;

bool isSet(int n, int i)
{

    // by left shift ---
    // if ((n & (1 << i)) != 0)
    // {
    //     return true; // set bit i.e 1
    // }
    // else
    // {
    //     return false;
    // }


    // by right shift -----
    if (((n >> i)&1) != 0){
        return true ;
    }
    else{
        return false ;
    }
}

int main()
{

    int n = 13;
    int i = 2;

    bool ans = isSet(n, i);
    cout << ans ;
}