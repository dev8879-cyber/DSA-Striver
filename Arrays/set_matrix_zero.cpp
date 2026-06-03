#include <iostream>
#include <vector>

using namespace std;

void mark_row(vector<vector<int>>& matrix, int row) {
    int m = matrix[0].size();

    for (int j = 0; j < m; j++) {
        if (matrix[row][j] != 0) {
            matrix[row][j] = -1;
        }
    }
}

void mark_col(vector<vector<int>>& matrix, int col) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][col] != 0) {
            matrix[i][col] = -1;
        }
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Original Matrix:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Mark rows and columns
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == 0){
                mark_row(matrix, i);
                mark_col(matrix, j);
            }

        }
    }

    // Convert -1 to 0
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }

        }
    }

    cout << "\nFinal Matrix:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}