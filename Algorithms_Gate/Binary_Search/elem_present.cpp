#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){

        int mid = low + (high - low)/2;

        // Element found
        if(nums[mid] == target){
            return mid;
        }

        // Search in right half
        else if(nums[mid] < target){
            low = mid + 1;
        }

        // Search in left half
        else{
            high = mid - 1;
        }
    }

    // Element not found
    return -1;
}

int main(){

    vector<int> nums = {-1,0,3,5,9,12};

    int target = 9;

    int ans = binarySearch(nums, target);

    if(ans != -1){
        cout << "Element found at index: " << ans << endl;
    }
    else{
        cout << "Element not found" << endl;
    }

    return 0;
}