// #include <iostream>
// using namespace std ;

// int main(){

//     string s = "AABABBA";
//     int maxLength = 0 ;
//     int k = 2 ;

//     for(int i = 0 ; i < s.length() ; i++){
//         int hash[26];
//         fill(hash , hash+26 , 0);
//         int maxfreq = 0 ;
//         for (int j = i ; j < s.length() ; j++){
//            hash[s[j]-'A']++ ;
//            maxfreq = max(maxfreq , (hash[s[j]-'A']));

//            int replacementCount = (j-i+1) - maxfreq ;

//            if (replacementCount <= k){
//               maxLength = max(maxLength , j-i+1);
//            }
//            else{
//             break ;
//            }
//         }
//     }
//     cout << maxLength ;
// }


// optimal ---------------------------------------

#include <iostream>
using namespace std ;

int main(){

    string s = "AABABBA";
    int maxLength = 0 ;
    int k = 2 ;
    int i = 0 ;
    int j = 0 ;

    int hash[26];
    fill(hash , hash+26 , 0);
    int maxfreq = 0 ;
    int maxReplacementCount = 0 ;

    while (j < s.length()){
       hash[s[j] - 'A']++ ;
       maxfreq = max(maxfreq , (hash[s[j]-'A']));

       maxReplacementCount = (j-i+1) - maxfreq ;

       if (maxReplacementCount <= k){
         maxLength = max(maxLength , j-i+1);
         j++ ;
       }
       else{
          
       }
    }
}