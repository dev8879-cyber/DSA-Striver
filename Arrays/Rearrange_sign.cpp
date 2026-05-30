#include <iostream>
using namespace std;
int main()
{
    vector<int> vec = {3, 1, -2, -5, 2, -4};

    int n = vec.size();

    vector<int> vp;
    vector<int> vn;

    for (int x : vec)
    {
        if (x > 0)
            vp.push_back(x);
        else
            vn.push_back(x);
    }

    int p = 0, neg = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            vec[i] = vp[p++];
        else
            vec[i] = vn[neg++];
    }

    for (int x : vec)
        cout << x << " ";
}