#include<iostream>
using namespace std;
bool ls(int a[], int size, int target){
    for(int i=0;i<size;i++){
        if(a[i]==target){
            return true;
        }
    }
    return false;
}
int main(){
    int a[]={102,4,100,1,101,3,2,1,1};
    int n=9;
    int lon=1;
    for(int i=0;i<n;i++){
        int x=a[i];
        int cnt=1;
        while(ls(a,n,x+1)==true){
            x=x+1;
            cnt++;
        }
        lon=max(lon,cnt);
    }
    cout<<"Longest sequence is:"<<lon;
}