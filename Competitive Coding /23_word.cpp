#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n_uc=0;
    int n_lc=0;
    for(int c:s){
        if(c>=65 && c<=91){
            n_uc++;
        }
        else{
            n_lc++;
        }
    }
    if(n_uc>n_lc){
        for(int i=0;i<s.length();i++){
            s[i]=toupper(s[i]);
        }
    }
    else{
        for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
        }
    }
    cout<<s;
}