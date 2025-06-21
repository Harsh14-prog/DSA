#include <iostream>
using namespace std ;


int findPeak(int arr[] , int n){

    // iterate over each element , and check it's left and right for peak
    // we have to take seperate base cases for 1st and last ele
    // as 1st ele do not have left i-1 to compare as tyachya left la -infinity asnare
    // so we did not have to check it's left , for him right i+1 is > then 1st ele is peak
    // only right ele check jr less asel tr to fix peak asnare as left ele alrady small aahe
    // see condn for last ele logic

    // we are taking early exit from array as soon as we get 1st peak

    if (arr[0] > arr[1]){
        return arr[0];
    }

    if (arr[n-1] > arr[n-2]){
        return arr[n-1];
    }

    for (int i = 1 ; i < n-1 ; i++){
        if (arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            return arr[i];
        }
    }
    return -1 ;
}

int main (){
    int arr[] = {1,2,1,3,5,1,4};
    int n = 7 ;

    int ans = findPeak(arr , n);
    cout << ans ;
}