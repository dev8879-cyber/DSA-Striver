#include<iostream>
using namespace std;
int Cnt_Set_bits(int n){
    int cnt=0;
    while(n>1){
        cnt+=(n&1);
        n=(n>>1);
    }
    if(n==1) cnt+=1;
    return cnt;
}
int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int cnt;
    cnt=Cnt_Set_bits(n);
    cout<<"The number of set bits are:"<<cnt<<endl;
    int cnt2=0;
    while(n!=0){
        n=(n&(n-1));
        cnt2++;
    }
    cout<<"The number of set bits by another method is:"<<cnt2;
}