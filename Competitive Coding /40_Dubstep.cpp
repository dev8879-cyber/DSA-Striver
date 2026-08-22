#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    string ans;
    bool space = false;
    for(int i=0;i<s.length();){
        if(s.substr(i,3)=="WUB"){
            i+=3;
            space =true;
        }
        else{
            if(space && !ans.empty()){
                ans+=' ';
            }
            ans+=s[i];
            i++;
            space =false;
        }
    }
    cout<<ans;
    return 0;
}