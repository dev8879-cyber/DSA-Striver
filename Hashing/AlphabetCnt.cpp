#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter valid string: ";
    cin >> s;

    int hash[26] = {0};

    // Store frequencies
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--)
    {
        char c;
        cout << "Enter character: ";
        cin >> c;

        cout << "Frequency is: " << hash[c - 'a'] << endl;
    }

    return 0;
}