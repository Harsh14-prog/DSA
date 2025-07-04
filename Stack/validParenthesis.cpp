#include <iostream>
#include <stack>
using namespace std ;

int main () {
    string s = "(()[]{}" ;
    int n = s.length();

    stack <int> st ;

    for (int i = 0 ; i < n ; i++){
        if (s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if (!st.empty() && st.top() == '[' && s[i] == ']'){
                st.pop();
            }
            else if (!st.empty() && st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else{
                return false ;
            }
        }
    }
    cout << st.empty();
}