#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int pos=0;
        long long diff = LLONG_MAX;
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]<diff){
                diff=a[i+1]-a[i];
                pos=i;
            }
        }
        cout<<a[pos]<<" ";
        for(int i=0;i<pos;i++){
            cout<<a[i]<<" ";
        }
        for(int i=pos+2;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[pos+1]<<endl;;
    }
    return 0;
} 