#include<iostream>
using namespace std;

void prtS(int ind,vector<int>&ds,int a[],int n){
    if(ind==n){
        for(auto it:ds){
            cout<<it<<" ";
            
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ds.push_back(a[ind]);
    prtS(ind+1,ds,a,n);
    ds.pop_back();
    prtS(ind+1,ds,a,n);
}

int main(){
    int a[]={3,1,2};
    int n=3;
    vector<int>ds;
    prtS(0,ds,a,n);

}