#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int>blocks;
        int count=0;
        for(char c:s){
            if(c=='1'){
                count++;
            }
            else{//111001101--3,2,1
                if(count>0){
                    blocks.push_back(count);
                    count=0;
                }
            }
        }
        //Adding last block:
        if(count>0){
            blocks.push_back(count);
        }
        sort(blocks.rbegin(),blocks.rend());
        int ans=0;
        for(int i=0;i<blocks.size();i+=2){
            ans+=blocks[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}