#include<iostream>
using namespace std;
int main(){
    int a[]={-2,-3,4,-1,-2,1,5,-3};
    int n=sizeof(a)/sizeof(a[0]);
    int maxi=INT_MIN;

    // Brute force:
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum=0;
    //         for(int k=i;k<j;k++){
    //             sum+=a[k];
    //         }
    //         maxi=max(sum,maxi);
    //     }
    // }
    // cout<<"The maximum subarray array sum is:"<<maxi;

    // better:
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=a[j];
    //     }
    //     maxi=max(sum,maxi);
    // }
    // cout<<"The maximum subarray array sum is:"<<maxi;

    // Optimised:
    int sum=0;
    int start=0;
    int ansSt=-1;
    int ansEd=-1;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=a[i];
        if(sum>maxi){
            maxi=sum;
            ansSt=start;
            ansEd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<"The maximum subarray sum is:"<<maxi<<endl;
    cout<<"Subarray:["<<ansSt<<","<<ansEd<<"]";
}