#include<iostream>
#include<set>
using namespace std;
// int main(){
//     vector<int>vec={2,3,1,1,3,6,4,3};
//     set<int>st;
//     for(int ele:vec){
//         st.emplace(ele);
//     }
//     cout<< "The size is:"<<st.size();
// }
int main(){
    vector<int>vec={2,3,1,1,3,6,4,3};
    int n=vec.size();
    sort(vec.begin(), vec.end());
    int j=1;
    for(int i=1;i<n;i++){
        if(vec[i]!=vec[i-1]){
            vec[j]=vec[i];
            j++;
        }
    }
    cout<<"The final size is:"<<j;
}