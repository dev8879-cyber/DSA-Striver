#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter Array Size:";
    cin>>n;
    int a[n];
    int i=0;
    for(int elem : a){
        cout<<"Enter element "<<i+1<<" :";
        cin>>a[i];
        i++;
    }

    //Input:
    map<int, int>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    for(auto it : mpp){
        cout<<it.first<<"-->"<<it.second<<endl;
    }

    int q;
    cout<<"Enter No. of queries:";
    cin>>q;
    while(q--){
        int x;
        cout<<"Enter no.:";
        cin>>x;
        cout<<"The freq. is:"<<mpp[x]<<endl;
    }
}