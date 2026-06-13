#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return mid;

            // Left sorted
            if(nums[low] <= nums[mid]) {

                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Right sorted
            else {

                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    int target = 0;

    cout << obj.search(nums, target);

    return 0;
}