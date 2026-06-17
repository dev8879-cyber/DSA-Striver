#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int rotationCount(vector<int>& arr) {

        int n = arr.size();

        int low = 0;
        int high = n - 1;

        int ans = INT_MAX;
        int index = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // If search space already sorted
            if(arr[low] <= arr[high]) {

                if(arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }

                break;
            }

            // Left half sorted
            if(arr[low] <= arr[mid]) {

                if(arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }

                low = mid + 1;
            }

            // Right half sorted
            else {

                if(arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }

                high = mid - 1;
            }
        }

        return index;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {4,5,6,7,0,1,2};

    cout << "Array rotated "
         << obj.rotationCount(arr)
         << " times";

    return 0;
}