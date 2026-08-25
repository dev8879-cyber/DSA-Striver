#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int>mp;
    for(int i=0;i<n;i++){
        string team;
        cin>>team;
        mp[team]++;
    }
    string winner;
    int maxGoals=0;
    for(auto i:mp){
        if(i.second>maxGoals){
            maxGoals=i.second;
            winner=i.first;
        }
    }
    cout<<winner;
    return 0;
}