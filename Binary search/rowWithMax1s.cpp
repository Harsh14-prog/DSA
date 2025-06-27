#include <iostream>
#include <vector>
#include <climits>
using namespace std ;

int findRowMethod1(vector <vector <int>> &mat){

    int row = mat.size();
    int col = mat[0].size();
    int maxi = INT_MIN ;
    int rowindex = -1 ;

    for (int i = 0 ; i < row ; i++){
        int count = 0 ;
        for (int j = 0 ; j < col ; j++){
           if (mat[i][j] == 1){
            count++ ;
           }
        }
        if (count > maxi){
            maxi = count ;
            rowindex = i ;
        }
    }
    return rowindex ; 
}

int find1sCount(vector <int> &arr){
    int n = arr.size();
    int l = 0 ;
    int h = n-1 ;
    int ans = arr.size() ;  // if 1's count in row is 0 then it should return 0

    while (l <= h){
        int mid = (l + h)/2 ;
        if (arr[mid] == 1){
            ans = mid ;
            h = mid - 1 ;
        }
        else {
            // means mid is on 0
            l = mid + 1 ;
        }

    }  
    return (n - ans);  // if ans = size remains from upward it will return 0
}

int findRowMethod2(vector <vector <int>> &mat){
    // to make method-1 efficient we have to remove inside loop to see around o(n)
    // with 1 outer loop we can traverse on each row only , so we will make fun
    // inside which we will send each row from loop , that fun will do B.S on that
    // row like it was doing it on 1d array
    int row = mat.size();
    int maxi = INT_MIN ;
    int index = -1 ;

    for (int i = 0 ; i < row ; i++){
        int Count =  find1sCount(mat[i]);
        if (Count > maxi){
            maxi = Count ;
            index = i ;
        }
    }
    return index ;
}

int main () {
  
    vector <vector <int>> mat = {{1,0,1,1,1},
                                 {1,1,1,0,0},
                                 {0,0,0,0,1},
                                 {1,1,1,1,0}};

    int row = findRowMethod1(mat);
    cout << row << endl ;

    int ans = findRowMethod2(mat);
    cout << ans ;
}