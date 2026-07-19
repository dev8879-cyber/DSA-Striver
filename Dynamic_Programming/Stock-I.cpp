#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>s(n);
    for(int elem : s){
        cin>>elem;
    }
    int mini=s[0];
    int profit=0;
    for(int i=1;i<n;i++){
        int cost = s[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,s[i]);
    }
    return profit;
}