#include<iostream>
#include<set>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<int>col;
    col.insert(a);
    col.insert(b);
    col.insert(c);
    col.insert(d);
    cout<<4-col.size();
    return 0;
}