#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    if((n & (n-1))==0){
        cout<<"The number is having power of 2!";
    }
    else{
        cout<<"Not power of 2!!";
    }
}