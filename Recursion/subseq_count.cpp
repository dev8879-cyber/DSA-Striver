#include<iostream>
using namespace std;

int cntS(int ind,int s, int a[],int sum,int n){
    if(ind==n){
        if(s==sum) return 1;
        else return 0;
    }
    s+=a[ind];
    int l=cntS(ind+1,s,a,sum,n);
    s-=a[ind];
    int r=cntS(ind+1,s,a,sum,n);
    return l+r;
}

int main(){
    int a[]={1,2,1};
    int n=3;
    int sum=2;
    cout<<cntS(0,0,a,sum,n);
}