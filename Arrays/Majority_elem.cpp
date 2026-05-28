#include<iostream>
using namespace std;
int main(){
    int a[]={2,2,1,1,1,2,2};
    int n=sizeof(a)/sizeof(a[0]);

    // //Brute force:
    // int count=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(a[i]==a[j]){
    //             count++;
    //         }
    //     }
    //     if(count>(n/2)){
    //         cout<<"Element found:"<<a[i]<<endl;
    //         return 0;
    //     }
    // }

    // // Better:
    // unordered_map<int,int>mpp;
    // for(int i=0;i<n;i++){
    //     mpp[a[i]]++;
    // }
    // for(auto it:mpp){
    //     if(it.second>(n/2)){
    //         cout<<"Element found:"<<it.first;
    //     }
    // }

    // Moore's Voting Algo:
    int count=0;
    int ele;
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            ele=a[i];
        }
        else if(a[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==ele){
            cnt++;
        }
    }
    if(cnt>(n/2)){
        cout<<"Element found:"<<ele;
    }
}