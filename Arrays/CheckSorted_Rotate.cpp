#include<iostream>
using namespace std;

int main() {
    int a[] = {2,3,5,1};
    int n = sizeof(a)/sizeof(a[0]);

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] > a[(i+1)%n])
            count++;
    }

    if(count > 1)
        cout << "False";
    else
        cout << "True";

    return 0;
}