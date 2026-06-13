#include<iostream>
using namespace std;

int lower_bound(int a[],int target,int n){
    int l=0;
    int h=n-1;
    int ans=n;
    while(l<=h){
        int mid=(l+h)/2;
        if(a[mid]>=target){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int a[]={1,2,3,4,2,4,9,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    int target=4;
    cout<<lower_bound(a,target,n);
}