#include <iostream>
#include <climits>
using namespace std ;

int findMin(int arr[] , int i , int n){
   int mini = INT_MAX ;
   int miniIndex = -1 ;
   for (int j = i ; j < n ; j++){
     
        if (arr[j] < mini){
           mini = arr[j];
           miniIndex = j ;
        }
    } 
    return miniIndex ;
}

void sort(int arr[] , int n){

    for (int i = 0 ; i < n ; i++){
        int index = findMin(arr , i , n);
        swap(arr[index] , arr[i]);
    }
}

int main () {

    int arr[] = {13 , 46 , 24 , 52 , 20 , 9};
    int n = 6 ;

    sort(arr , n);

    cout << "sorted array is : " << endl ;
    for (auto ele : arr){
        cout << ele << " " ;
    }
}