#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = INT_MAX;

        while(low <= high) {

            // If already sorted
            if(nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half sorted
            if(nums[low] <= nums[mid]) {

                ans = min(ans, nums[low]);

                low = mid + 1;
            }

            // Right half sorted
            else {

                ans = min(ans, nums[mid]);

                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum element: "
         << obj.findMin(nums);

    return 0;
}