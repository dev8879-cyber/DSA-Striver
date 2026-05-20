#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Enter the bit number to be set";
    int i;
    cin>>i;
    n=(n|(1<<i));
    cout<<"The number after setting the bit is:"<<n;
}