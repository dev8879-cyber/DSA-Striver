#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    stack<int> st;
    st.push(-1); // Base boundary

    int max_len = 0;
    int count = 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i); // Update boundary
            } else {
                int current_len = i - st.top();
                if (current_len > max_len) {
                    max_len = current_len;
                    count = 1;
                } else if (current_len == max_len) {
                    count++;
                }
            }
        }
    }

    if (max_len == 0) {
        cout << "0 1\n";
    } else {
        cout << max_len << " " << count << "\n";
    }

    return 0;
}