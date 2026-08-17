#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]-1]=i+1;
    }
    for(int elem:b){
        cout<<elem<<" ";
    }
}