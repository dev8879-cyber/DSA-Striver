#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int flag=0;
    int cnt=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            cnt++;
            if(cnt==7){
                flag=1;
                break;
            }
        }
        else{
            cnt=1;
        }
        
    }
    if(flag==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}