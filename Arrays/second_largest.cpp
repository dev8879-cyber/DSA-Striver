#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element no. "<<i+1<<":";
        cin>>a[i];
    }
    int l=a[0];
    for(int elem: a){
        if(elem>l){
            l=elem;
        }
    }
    cout<<"The largest element is:"<<l<<endl;
    int s=a[0];
    for(int elem:a){
        if(elem>s && elem<l){
            s=elem;
        }
    }
    if(s==l){
        cout<<"No second max_elem is there!!";
    }
    else{
        cout<<"The Second largest element is:"<<s;
    }
}