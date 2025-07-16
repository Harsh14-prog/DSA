#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// finding slighly greater number for next permutation
void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int breakPoint = -1;

    // Step 1: Find the first index from end where nums[i] < nums[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            breakPoint = i;
            break;
        }
    }

    // Step 2: If no such index found, reverse the entire array
    // bez it is already last combination i.e last permutation in such case 
    // return 1st permutation , so reverse this number
    if (breakPoint == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the element just greater than nums[breakPoint]
    int index = n - 1;
    while (nums[index] <= nums[breakPoint]) {
        index--;
    }

    // Step 4: Swap and reverse the suffix
    swap(nums[index], nums[breakPoint]);

    // The suffix (right part after swapping) is already in descending order, 
    //so reversing it gives us the smallest possible next suffix — which 
    //is exactly what we want.
    reverse(nums.begin() + breakPoint + 1, nums.end());
}

int main() {
    vector<int> nums = {2,1,5,4,3,0,0}; 

    nextPermutation(nums);

    for (int num : nums)
        cout << num << " ";
    cout << endl;
}
