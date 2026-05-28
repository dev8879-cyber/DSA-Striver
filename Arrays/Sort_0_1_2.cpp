#include<iostream>
using namespace std;
int main(){
    vector<int>vec={2,1,0,2,1,2,0,0};
    int n=vec.size();
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(vec[mid]==0){
            swap(vec[mid],vec[low]);
            mid++;
            low++;
        }
        else if(vec[mid]==1){
            mid++;
        }
        else{
            swap(vec[mid],vec[high]);
            high--;
        }
    }
    for(auto it : vec){
        cout<<it<<" ";
    }
}