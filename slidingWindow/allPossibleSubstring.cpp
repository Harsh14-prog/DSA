// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <climits>
// using namespace std;

// int main()
// {

//     string str = "cadbzabcd";
//     vector<string> st;
//     int count = 0;
//     int maxLength = INT_MIN;

//     for (int i = 0; i < str.length(); i++)
//     {
//         string ans;
//         // unordered_map<char, bool> map;
//         bool charSeen[256] = {false};
//         for (int j = i; j < str.length(); j++)
//         {

//             if (charSeen[str[j]] == true)
//             {
//                 break;
//             }
//             else
//             {
//                 ans = ans + str[j];
//                 st.push_back(ans);
//                 count++;
//                 maxLength = max(maxLength, (int)ans.length());  // length = j-i+1
//                 charSeen[str[j]] = true;
//             }
//         }
//     }

//     for (auto str : st)
//     {
//         cout << str << " ";
//     }

//     cout << endl;
//     cout << "total count of possible substrings with unique characters is : " << count << endl;
//     cout << "longest substring with unique characters is of length : " << maxLength << endl;
// }


//   sliding window , two pointer approch

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{

    string str = "cadbzabcd";
    int l = 0 ;
    int h = 0 ;
    int maxLength = INT_MIN;

    int hash[256];
    fill(hash , hash+256 , -1);
 
    while (h < str.length()){

        if (hash[str[h]] != -1 && hash[str[h]] >= l){
            l = hash[str[h]] + 1 ; 
        }
        // do not do else here , as we map either we got prev duplicate or not
        // as "h" is always moving by 1 step in any condition so don't put this in else block
         hash[str[h]] = h ;
         int len = h-l+1 ;
         maxLength = max(maxLength , len);
         h++ ; 

        
    }
    cout << maxLength ;
}