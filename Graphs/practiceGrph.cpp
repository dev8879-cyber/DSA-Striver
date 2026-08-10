#include<iostream>
using namespace std;
int orangesRotting(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    int fresh=0;
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
            else if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    int time=0;
    int del_row[]={-1,0,1,0};
    int del_col[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        time=max(t,time);
        for(int i=0;i<4;i++){
            int nrow=row+del_row[i];
            int ncol=col+del_col[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                grid[nrow][ncol]=2;
                fresh--;
                q.push({{nrow,ncol},t+1});
            }
        }
    }
}
int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum time: " << orangesRotting(grid) << endl;

    return 0;
}