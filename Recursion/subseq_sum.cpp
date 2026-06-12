#include<iostream>
using namespace std;

void prtS(int ind, vector<int>& ds,int s,int a[],int n,int sum){
    if(ind==n){
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }
        ds.push_back(a[ind]);
        s+=a[ind];
        prtS(ind+1,ds,s,a,n,sum);//Pick
        s-=a[ind];
        ds.pop_back();
        prtS(ind+1,ds,s,a,n,sum);// Not Pick
    }
}

int main(){
    int a[]={1,2,1};
    int n=3;
    vector<int>ds;
    int sum=2;
    prtS(0,ds,0,a,n,sum);
}