#include <iostream>
#include <string>
using namespace std;

long long nb, ns, nc;
long long pb, ps, pc;
long long r;

long long needB = 0;
long long needS = 0;
long long needC = 0;

bool canMake(long long x)
{
    long long totalB = x * needB;
    long long totalS = x * needS;
    long long totalC = x * needC;

    long long buyB = max(0LL, totalB - nb);
    long long buyS = max(0LL, totalS - ns);
    long long buyC = max(0LL, totalC - nc);

    long long cost = buyB * pb
                   + buyS * ps
                   + buyC * pc;

    return cost <= r;
}

int main()
{
    string recipe;
    cin >> recipe;

    for(char ch : recipe)
    {
        if(ch == 'B')
            needB++;
        else if(ch == 'S')
            needS++;
        else
            needC++;
    }

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    long long low = 0;
    long long high = 10000000000000LL;
    long long ans = 0;

    while(low <= high)
    {
        long long mid = low + (high - low) / 2;

        if(canMake(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}