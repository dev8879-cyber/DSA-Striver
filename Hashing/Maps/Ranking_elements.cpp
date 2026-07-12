#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;

    // Sort the copied array
    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;
    int r = 1;

    // Assign ranks to unique elements
    for (int x : temp) {
        if (rank.find(x) == rank.end()) {
            rank[x] = r++;
        }
    }

    // Replace each element with its rank
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rank[arr[i]];
    }

    return arr;
}

int main() {

    vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};

    vector<int> ans = arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}