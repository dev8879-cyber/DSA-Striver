#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double x;
    double per=0;
    for(int i=0;i<n;i++){
        cin>>x;
        per+=(x/n);
    }
    cout<<per;
    return 0;

}