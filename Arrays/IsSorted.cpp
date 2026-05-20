#include<iostream>
using namespace std;
 int main(){
    int n;
    cout<<"Enter Array Size:";
    cin>>n;
    int i=0;
    int a[n];
    int flag=0;
    for(int elem:a){
        cout<<"Enter element "<<i<<":";
        cin>>elem;
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Array is sorted in ascending order!";
    }
    else{
        cout<<"Array is not sorted!";
    }
 }