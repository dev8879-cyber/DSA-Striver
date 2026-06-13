#include<iostream>
using namespace std;

int first(int a[], int n, int target){

    int l = 0;
    int h = n - 1;

    int fir = -1;

    while(l <= h){

        int mid = (l + h) / 2;

        if(a[mid] == target){
            fir = mid;
            h = mid - 1;
        }

        else if(a[mid] > target){
            h = mid - 1;
        }

        else{
            l = mid + 1;
        }
    }

    return fir;
}

int last(int a[], int n, int target){

    int l = 0;
    int h = n - 1;

    int las = -1;

    while(l <= h){

        int mid = (l + h) / 2;

        if(a[mid] == target){
            las = mid;
            l = mid + 1;
        }

        else if(a[mid] > target){
            h = mid - 1;
        }

        else{
            l = mid + 1;
        }
    }

    return las;
}

int main(){

    int a[] = {1,2,3,3,3,5,5,7,8};

    int n = sizeof(a) / sizeof(a[0]);

    int target = 3;

    int fir = first(a, n, target);

    if(fir == -1){
        cout << "{-1,-1}";
        return 0;
    }

    int las = last(a, n, target);

    cout << "{" << fir << "," << las << "}";

    return 0;
}