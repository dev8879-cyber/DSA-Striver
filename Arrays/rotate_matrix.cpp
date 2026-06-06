#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateMatrix(vector<vector<int>>& matrix){

    int n = matrix.size();

    // Step 1: Transpose the matrix
    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse every row
    for(int i = 0; i < n; i++){

        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix){

    int n = matrix.size();

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main(){

    vector<vector<int>> matrix = {

        {1,2,3},
        {4,5,6},
        {7,8,9}

    };

    cout << "Original Matrix:\n";

    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "\nRotated Matrix:\n";

    printMatrix(matrix);

    return 0;
}