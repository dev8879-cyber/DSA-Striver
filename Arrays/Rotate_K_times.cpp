#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);

    int k=3;

    k=k%n;

    reverse(a,a+n);

    reverse(a,a+k);

    reverse(a+k,a+n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to rotate array left by K positions
// void leftRotate(vector<int> &A, int K) {
//     int n = A.size();
//     K = K % n;  // Handle K >= n

//     int min = n;
//     int i = 0;

//     while (min > 0) {
//         int temp = A[i];
//         int j = i;

//         while ((j + K) % n != i) {
//             A[j] = A[(j + K) % n];
//             j = (j + K) % n;

//             if (j < min)
//                 min = j;
//         }

//         A[(n + i - K) % n] = temp;
//         i = min;
//     }
// }

// int main() {
//     int n, K;

//     cout << "Enter size of array: ";
//     cin >> n;

//     vector<int> A(n);

//     cout << "Enter array elements:\n";
//     for (int i = 0; i < n; i++)
//         cin >> A[i];

//     cout << "Enter K: ";
//     cin >> K;

//     leftRotate(A, K);

//     cout << "Array after left rotation:\n";
//     for (int x : A)
//         cout << x << " ";

//     cout << endl;

//     return 0;
// }