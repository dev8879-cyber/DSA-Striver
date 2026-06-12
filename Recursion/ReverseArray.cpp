#include<iostream>
using namespace std;

void Rev(int a[], int l, int r)
{
    if(l >= r)
    {
        return;
    }

    swap(a[l], a[r]);

    Rev(a, l + 1, r - 1);
}

int main()
{
    int a[] = {1,2,4,2,54,3,7};

    int n = sizeof(a) / sizeof(a[0]);

    int l = 0;
    int r = n - 1;

    Rev(a, l, r);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}