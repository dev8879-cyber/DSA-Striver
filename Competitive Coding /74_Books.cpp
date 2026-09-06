#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left = 0;
    int sum = 0;
    int ans = 0;

    for(int right = 0; right < n; right++)
    {
        sum += a[right];

        while(sum > t && left <= right)
        {
            sum -= a[left];
            left++;
        }

        int books = right - left + 1;

        if(books > ans)
        {
            ans = books;
        }
    }

    cout << ans;

    return 0;
}