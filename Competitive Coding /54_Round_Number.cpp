#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int place=1;
        int count=0;
        int temp=n;
        while(temp){
            int last=n%10;
            if(last!=0){
                count++;
            }
            temp=temp/10;
        }
        cout<<count<<endl;
        while(n){
            int last=n%10;
            if(last!=0){
                cout<<last*place;
            }
            n=n/10;
            place*=10;
        }
        cout<<endl;
    }
    return 0;
}