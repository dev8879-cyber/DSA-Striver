#include<iostream>
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

    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]+=1;
    }

    int x;
    cout<<"Enter element to find its freq:";
    cin>>x;
    cout<<"The freq. is:"<<hash[x]<<endl;
}