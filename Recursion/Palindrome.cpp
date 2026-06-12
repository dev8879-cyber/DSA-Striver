#include<iostream>
using namespace std;
bool isPalin(string s,int l, int r){
    // char c;
    if(s[l]==s[r]){
        return true;
    }
    else{
        return false;
    }
    isPalin(s,l+1,l-1);
}
int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;
    int n=s.length();
    int l=0;
    int r=n-1;
    cout<<isPalin(s,l,r);
}