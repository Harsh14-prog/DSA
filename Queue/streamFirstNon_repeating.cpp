#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main () {

    string s = "aabc";
    
    // we want till ith index what is 1st non-repeating char
    // so will use queue in order to track prev char
    unordered_map <char , int> map ;

    queue <char> q ;
    string ans = "" ;

    for (int i = 0 ; i < s.length() ; i++){
       map[s[i]]++ ;
       q.push(s[i]);

       while (!q.empty() && map[q.front()] > 1){
          q.pop();
       }

       if (q.empty()){
         ans += '#';
       }

       else{
        ans += q.front();
       }
    }

    cout << ans ;
}