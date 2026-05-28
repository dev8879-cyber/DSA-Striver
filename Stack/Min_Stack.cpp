#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<pair<int,int>> st;

public:

    void push(int val)
    {
        if(st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        if(!st.empty())
            st.pop();
    }

    int top()
    {
        if(st.empty())
            return -1;

        return st.top().first;
    }

    int getMin()
    {
        if(st.empty())
            return -1;

        return st.top().second;
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MinStack ms;

    ms.push(5);
    ms.push(2);
    ms.push(7);
    ms.push(1);

    cout << "Top: " << ms.top() << endl;
    cout << "Minimum: " << ms.getMin() << endl;

    ms.pop();

    cout << "After pop:" << endl;
    cout << "Top: " << ms.top() << endl;
    cout << "Minimum: " << ms.getMin() << endl;

    return 0;
}