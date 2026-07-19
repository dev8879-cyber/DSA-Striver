#include<iostream>
using namespace std;
int solve(int ind,vector<int>& arr){
    int prev1=arr[0];
    int prev2=0;
    for(int i=1;i<ind;i++){
        int pick=arr[i];
        if(ind>1){
            pick+=prev1;
        }
        int not_pick=prev2;
        int curi=max(pick,not_pick);
        prev2=prev1;
        prev1=curi;
    }
    return prev1;
}
int houseRobber(vector<int>& nums){
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int>temp1;
    vector<int>temp2;
    for(int i = 0; i < n; i++)
    {
        if(i != 0)
            temp1.push_back(nums[i]);

        if(i != n - 1)
            temp2.push_back(nums[i]);
    }
    int l=solve(n-1,temp1);
    int r=solve(n-1,temp2);
    return max(l,r);
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << houseRobber(nums);

    return 0;
}