#include<iostream>
using namespace std;

void prt(int n, int m)
{
    if(m <= 1)
    {
        cout << n;
        return;
    }

    cout << n << endl;

    prt(n, m - 1);
}

int main()
{
    int n;

    cout << "Enter number:";
    cin >> n;

    cout << "Enter no. of times:";
    
    int m;
    cin >> m;

    prt(n, m);
}