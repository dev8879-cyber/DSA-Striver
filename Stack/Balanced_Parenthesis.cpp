#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<char> st;

    string s;
    cout << "Enter valid string: ";
    cin >> s;

    int n = s.length();

    for(int i = 0; i < n; i++)
    {
        // Opening brackets
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            // No opening bracket available
            if(st.empty())
            {
                cout << "Invalid";
                return 0;
            }

            char ch = st.top();
            st.pop();

            // Matching brackets
            if((s[i] == ')' && ch == '(') ||
               (s[i] == '}' && ch == '{') ||
               (s[i] == ']' && ch == '['))
            {
                continue;
            }
            else
            {
                cout << "Invalid";
                return 0;
            }
        }
    }

    // Check if any opening brackets remain
    if(st.empty())
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}