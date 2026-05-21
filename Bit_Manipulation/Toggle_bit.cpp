#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int i;
    cout<<"Enter bit to be toggled:";
    cin>>i;
    n=(n^(1<<i));
    cout<<"The number after toggling the bit is:"<<n;
}