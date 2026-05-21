#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    n=(n&(n-1));
    cout<<"The number after removing the last set bit:"<<n;
}