#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int wordLadderLength(string startWord, string targetWord,
                     vector<string>& wordList) {

    queue<pair<string, int>> q;

    q.push({startWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());

    // We don't need to visit startWord again
    st.erase(startWord);

    while (!q.empty()) {

        string word = q.front().first;
        int steps = q.front().second;

        q.pop();

        // Target reached
        if (word == targetWord) {
            return steps;
        }

        // Change every character
        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                // Check if transformed word exists
                if (st.find(word) != st.end()) {

                    st.erase(word);

                    q.push({word, steps + 1});
                }
            }

            // Restore original character
            word[i] = original;
        }
    }

    return 0;
}

int main() {

    string startWord = "der";
    string targetWord = "dfs";

    vector<string> wordList = {
        "des",
        "der",
        "dfr",
        "dgt",
        "dfs"
    };

    cout << wordLadderLength(startWord, targetWord, wordList);

    return 0;
}