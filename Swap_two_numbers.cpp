#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter two numbers:";
    cin>>n1>>n2;
    cout<<"Before swapping the numbers are n1="<<n1<<" and n2="<<n2<<endl;
    n1=n1^n2;
    n2=n1^n2;
    n1=n1^n2;
    cout<<"After Swapping the numbers are: n1="<<n1<<" and n2="<<n2;
}