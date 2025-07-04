#include <iostream>
#include <stack>
using namespace std ;

int main () {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12 ;

    int l = 0 ;
    int r = n-1 ;
    int lmax = 0 ;
    int rmax = 0 ;
    int totalwaterTrapped = 0 ;

 while (l < r){
     if (height[l] <= height[r]){
        if (lmax >= height[l]){
          totalwaterTrapped = totalwaterTrapped + (lmax - height[l]) ;
        }
        else{
            lmax = height[l];
        }
        l++ ;
    }
    else{
        if (rmax >= height[r]){
            totalwaterTrapped = totalwaterTrapped + rmax - height[r];
        }
        else{
            rmax = height[r];
        }
        r-- ;
    }
 }
 cout << totalwaterTrapped ;

}

