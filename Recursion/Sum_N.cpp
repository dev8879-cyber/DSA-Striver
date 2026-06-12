#include<iostream>
using namespace std;
int fun(int n){
    int sum;
    if(n==1){
        return n;
    }
    sum=n+fun(n-1);
    return sum;
}
int main(){
    int n;
    cout<<"Enter number";
    cin>>n;
    cout<<fun(n);
}