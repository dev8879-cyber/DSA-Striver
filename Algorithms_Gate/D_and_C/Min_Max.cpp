#include<iostream>
#include<vector>
using namespace std;

pair<int,int> findMinMax(vector<int>& arr, int low, int high){

    // Base Case 1
    // Only one element
    if(low == high){
        return {arr[low], arr[low]};
    }

    // Base Case 2
    // Two elements
    if(high == low + 1){

        if(arr[low] < arr[high]){
            return {arr[low], arr[high]};
        }
        else{
            return {arr[high], arr[low]};
        }
    }

    // Divide
    int mid = (low + high) / 2;

    // Solve Left Half
    pair<int,int> leftAns = findMinMax(arr, low, mid);

    // Solve Right Half
    pair<int,int> rightAns = findMinMax(arr, mid + 1, high);

    // Combine
    int minimum = min(leftAns.first, rightAns.first);
    int maximum = max(leftAns.second, rightAns.second);

    return {minimum, maximum};
}

int main(){

    vector<int> arr = {7, 11, -1, 14, -6, 19, 12, 63, 8};

    int n = arr.size();

    pair<int,int> ans = findMinMax(arr, 0, n - 1);

    cout << "Minimum Element = " << ans.first << endl;
    cout << "Maximum Element = " << ans.second << endl;

    return 0;
}