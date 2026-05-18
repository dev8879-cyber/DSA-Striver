#include <iostream>
using namespace std;
int main() {
    int arr[] = {2,5,1,3,0};
    int largest = arr[0];
    for(int i = 1; i < 5; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "Largest Element: " << largest;

    return 0;
}