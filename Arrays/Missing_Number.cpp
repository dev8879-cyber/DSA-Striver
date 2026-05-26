#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,5,6};
    int n=6;
    int sum=0;
    for(int ele : a){
        sum+=ele;
    }
    int Summ=((n)*(n+1))/2;
    int mis_ele=Summ-sum;
    cout<<"The missing element is:"<<mis_ele;
}