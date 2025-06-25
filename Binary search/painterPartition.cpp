#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std ;


bool isValid (int mid , vector <int>&boards , int m , int n){
    int boardPaintedtime = 0 ;
    int painterCount = 1 ;

    for (int i = 0 ; i < n ; i++){

        if (boards[i] > mid){
            return false ;
        }
      
        if (boardPaintedtime + boards[i] <= mid){
            boardPaintedtime = boardPaintedtime + boards[i];
        }
        else{
            // change painter as maxAllowd time mid crossed for painter 1
            painterCount ++ ;
            boardPaintedtime = boards[i];
        }
    }
    return painterCount > m ? false : true ;
}


int timetoPaint(vector<int> &boards, int n, int m) {

    // worst cases can be all boards are painted by 1 painter
    // or each board is painted by single-single painter
    int s = *max_element(boards.begin() , boards.end());  // jri 1-1 painter ne 1-1 board paint kela total time tr jya painter la max time lagel tevdch asnare na
    int e = accumulate(boards.begin() , boards.end() , 0);
    int ans = -1 ;

     if (n < m) return -1 ;

    // we will have ans betn this range , we will eliminate invalid part from this
    while (s <= e){

        int mid = (s + e)/2 ;
        // now we will check this mid i.e time is valid or not

        if (isValid(mid , boards , m , n)){
          ans = mid ;
          e = mid - 1 ;   // min pahije , so go to left
        }
        else {
            // bhetlela mid i.e time is invalid bez ya time vr m painter madhe board
            // paint hot nahiye , > m painter lagtat so we have to increase time 
             // inorder to divide betwn m painter
             // time i.e mid kami aslyane m painter madhe divide hit nahiye
            s = mid + 1 ;
        }
    }
    return ans;
    
}

int main() {
    vector<int> boards = {40, 30, 10, 20};
    int n = boards.size();
    int m = 2;

    int ans = timetoPaint(boards, n, m);
    cout << "Minimum time to paint all boards: " << ans << "\n";

    return 0;
}