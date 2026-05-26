#include<iostream>
using namespace std;
int main(){
    int a[]={2,3,5,3,5,3};
    int n=sizeof(a)/sizeof(a[0]);
    int last=a[0];
    for(int i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    a[n-1]=last;
    for(int ele : a){
        cout<<ele<<",";
    }
}