#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {6, 0, 8, 1, 3};
    int n = 5;

    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[i] >= st.top())
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }

    for (auto ele : nge)
    {
        cout << ele << endl;
    }
}