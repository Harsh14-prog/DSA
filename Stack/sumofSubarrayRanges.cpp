#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, n);
    stack<int> s;
    s.push(n);

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() != n && nums[s.top()] >= nums[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() != -1 && nums[s.top()] > nums[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, n);
    stack<int> s;
    s.push(n);

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() != n && nums[s.top()] <= nums[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() != -1 && nums[s.top()] < nums[i])
            s.pop();
        if (!s.empty()) ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

long long sumOfSubarrayMins(const vector<int>& nums) {
    int n = nums.size();
    auto next = nextSmallerElement(nums);
    auto prev = prevSmallerElement(nums);
    int mod = 1e9 + 7;
    long long sum = 0 ;

    for (int i = 0 ; i < n ; i++){
      long long product = ((next[i] - i) %mod * (i - prev[i])%mod)%mod ;
      sum = (sum + (product * nums[i]) %mod )%mod ;
    }
    return sum ;
  
}

long long sumOfSubarrayMax(const vector<int>& nums) {
    int n = nums.size();
    auto next = nextGreaterElement(nums);
    auto prev = prevGreaterElement(nums);
    int mod = 1e9 + 7;
    long long sum = 0 ;

    for (int i = 0 ; i < n ; i++){
      long long product = ((next[i] - i) %mod * (i - prev[i])%mod)%mod ;
      sum = (sum + (product * nums[i]) %mod )%mod ;
    }
    return sum ;
}

long long subArrayRanges(const vector<int>& nums) {
    int mod = 1e9 + 7;
    long long maxSum = sumOfSubarrayMax(nums);
    long long minSum = sumOfSubarrayMins(nums);
    return (maxSum - minSum) % mod;
}


int main() {
    vector<int> nums = {1, 4, 3, 2};  

    long long result = subArrayRanges(nums);
    cout << "Sum of Subarray Ranges : " << result << endl;

    return 0;
}
