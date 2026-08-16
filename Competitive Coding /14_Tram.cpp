#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cur=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        int exit,enter;
        cin>>exit>>enter;
        cur=cur-exit+enter;
        maxi=max(maxi,cur);
    }
    cout<<maxi;
    return 0;
}