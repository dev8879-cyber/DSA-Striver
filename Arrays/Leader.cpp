#include <iostream>
using namespace std;
int main()
{
    int a[] = {28, 18, 19, 8, 14, 11, 6, 7, 4};
    int n = sizeof(a) / sizeof(a[0]);
    // Brute force:
    // int i=0, j=0;
    // for (i = 0; i < (n - 1); i++)
    // {
    //     for ( j = i + 1; j < n; j++)
    //     {
    //         if (a[i] < a[j])
    //         {
    //             break;
    //         }
    //     }
    //     if (j == (n))
    //     {
    //         cout << a[i] << " is the leader"<<endl;
    //     }
    // }

    // Optimised:
    int L=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>L){
            L=a[i];
            cout<<a[i]<<",";
        }
    }
}