#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int ele1 = 0, ele2 = 1; 
    int count1 = 0, count2 = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (count1 == 0 && nums[i] != ele2) {
            ele1 = nums[i];
            count1 = 1;
        } 
        else if (count2 == 0 && nums[i] != ele1) {
            ele2 = nums[i];
            count2 = 1;
        } 
        else if (nums[i] == ele1) {
            count1++;
        } 
        else if (nums[i] == ele2) {
            count2++;
        } 
        else {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == ele1) count1++;
        else if (nums[i] == ele2) count2++;
    }

    vector<int> ans;
    if (count1 > nums.size() / 3) ans.push_back(ele1);
    if (count2 > nums.size() / 3) ans.push_back(ele2);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 2, 1, 1, 3};
    vector<int> result = majorityElement(nums);

    cout << "Majority Elements (> n/3 times): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

}
