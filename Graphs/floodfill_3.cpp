#include<iostream>
using namespace std;
void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis,int del_row[],int del_col[]){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+del_col[i];
        int ncol=col+del_col[i];
        if(nrow>=0 && ncol<m && nrow>=0 && nrow<n && (grid[nrow][ncol])=='1' && !vis[nrow][ncol]){
            vis[nrow][ncol]=1;
            dfs(nrow,ncol,grid,vis,del_row,del_col);
        }
    }
    
}
int main(){
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    cout << "Enter the grid (0/1):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int islands = 0;

    int del_row[]={-1,0,1,0};
    int del_col[]={0,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                dfs(i,j,grid,vis,del_row,del_col);
                islands++;
            }
        }
    }

}