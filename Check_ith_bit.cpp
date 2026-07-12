#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number";
    cin>>n;
    cout<<"Enter the bit that is need to be cheched:";
    int i;
    cin>>i;
    n=(n>>i);
    n=(n&1);
    if(n==1){
        cout<<"Bit is already set!";
    }
    else{
        cout<<"Bit not set yet!";
    }
}