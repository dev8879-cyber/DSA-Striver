#include<iostream>
using namespace std;
void prt(int n){
    if(n<1){
        return;
    }
    cout<<n;
    prt(n-1);
    // cout<<n;
}
int main(){
    int n;
    cout<<"Enter number";
    cin>>n;
    prt(n);
}