#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(int arr[], int n, int k)
{

    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {

        if (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}

int main()
{

    int arr[] = {1, 3, -1, -3, 5, 3, 7, 1, 6};
    int n = 9;
    int k = 3;

    vector<int> ans = slidingWindowMax(arr, n, k);

    for (auto it : ans)
    {
        cout << it << " ";
    }
}