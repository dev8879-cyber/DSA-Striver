#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int ind = -1;

    // Step 1: Find breakpoint
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }

    // Step 2: If no breakpoint exists
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find next greater element from right
    for(int i=n-1; i>ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 4: Reverse the suffix
    reverse(nums.begin()+ind+1, nums.end());
}

int main(){

    vector<int> nums = {1,2,3};

    nextPermutation(nums);

    cout << "Next Permutation: ";

    for(auto x : nums){
        cout << x << " ";
    }

    return 0;
}