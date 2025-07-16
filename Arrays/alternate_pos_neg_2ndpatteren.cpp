#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, 1, -2, -5, 2, -4, -7};  
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> posArr, negArr;

    // Step 1: Separate into positive and negative arrays
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            posArr.push_back(arr[i]);
        else
            negArr.push_back(arr[i]);
    }

    vector<int> ans; 
    int i = 0;
    int j = 0;

    // Step 2: Alternate between pos and neg like original logic
    while (i < posArr.size() && j < negArr.size()) {
        ans.push_back(posArr[i++]);
        ans.push_back(negArr[j++]);
    }

    // Step 3: Append leftovers from either array
    while (i < posArr.size()) ans.push_back(posArr[i++]);
    while (j < negArr.size()) ans.push_back(negArr[j++]);

    
    for (int ele : ans)
        cout << ele << " ";
    
    return 0;
}
