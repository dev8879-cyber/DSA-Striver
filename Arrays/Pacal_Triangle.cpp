#include <iostream>
#include <vector>
using namespace std;

int main() {

    int numRows;
    cin >> numRows;

    vector<vector<int>> ans;

    for(int i = 0; i < numRows; i++) {

        vector<int> row(i + 1, 1);

        for(int j = 1; j < i; j++) {
            row[j] = ans[i-1][j-1] + ans[i-1][j];
        }

        ans.push_back(row);
    }

    // Printing Pascal Triangle
    for(auto row : ans) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}