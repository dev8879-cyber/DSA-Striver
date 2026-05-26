#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int a[] = {1, 2, 6, 43, 2, 6, 9};

    int n = sizeof(a) / sizeof(a[0]);

    unordered_set<int> seen;

    for(int i = 0; i < n; i++)
    {
        if(seen.find(a[i]) != seen.end())
        {
            cout << "First repeating element is: " << a[i];
            return 0;
        }

        seen.insert(a[i]);
    }

    cout << "No repeating element found";

    return 0;
}