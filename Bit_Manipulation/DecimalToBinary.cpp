#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string Convert_To_Binary(int n){

    string res="";

    while(n>0){

        if(n%2!=0)
            res+='1';
        else
            res+='0';

        n=n/2;
    }

    reverse(res.begin(),res.end());

    return res;
}

int main(){

    int n;

    cout<<"Enter decimal number: ";
    cin>>n;

    string s;

    s=Convert_To_Binary(n);

    cout<<"Binary form: "<<s;

    return 0;
}