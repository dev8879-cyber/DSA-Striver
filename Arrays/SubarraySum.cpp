#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSpan(vector<int>& A, vector<int>& B) {
    int n = A.size();

    unordered_map<int, int> firstIndex;
    int prefix = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        prefix += (A[i] - B[i]);

        if (prefix == 0)
            ans = i + 1;

        if (firstIndex.find(prefix) != firstIndex.end()) {
            ans = max(ans, i - firstIndex[prefix]);
        } else {
            firstIndex[prefix] = i;
        }
    }

    return ans;
}

int main() {
    vector<int> A = {1, 0, 1, 0, 0};
    vector<int> B = {0, 1, 1, 0, 0};

    cout << longestSpan(A, B) << endl;

    return 0;
}