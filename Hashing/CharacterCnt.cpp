#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"Enter valid string:";
    cin>>str;

    int hash[256]={0};
    for(int i=0;i<str.size();i++){
        hash[str[i]]++;
    }

    int q;
    cout<<"Enter no. of queries:";
    cin>>q;
    while(q--){
        char c;
        cout<<"Enter character:";
        cin>>c;
        cout<<"The freq. count is:"<<hash[c]<<endl;
    }
}