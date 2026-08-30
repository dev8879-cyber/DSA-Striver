#include<iostream>
using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int sum=0;
    for(int i=0;i<w;i++){
        sum+=(i+1)*k;
    }
    int req;
    if(sum>n){
        req=sum-n;
    }
    else{
        req=0;
    }
    cout<<req;
    return 0;
    
}