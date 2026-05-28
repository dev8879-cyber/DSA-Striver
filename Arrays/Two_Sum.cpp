#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int a[] = {3,2,4};
    int target = 6;

    int n = sizeof(a)/sizeof(a[0]);

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        int need = target - a[i];

        if(mp.find(need) != mp.end())
        {
            cout<<"Indices are "
                <<mp[need]<<" and "<<i;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout<<"No pair found";
}