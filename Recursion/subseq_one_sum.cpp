#include<iostream>
using namespace std;

bool prtS(int ind,vector<int>&ds,int s,int a[],int sum,int n){
    if(ind==n){
        if(s==sum){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else return false;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    if(prtS(ind+1,ds,s,a,sum,n)==true) return true;
    s-=a[ind];
    ds.pop_back();
    if(prtS(ind+1,ds,s,a,sum,n)==true) return true;
    return false;
}

int main(){
    int a[]={1,2,1};
    vector<int>ds;
    int n=3;
    int sum=2;
    cout<<prtS(0,ds,0,a,sum,n);
}