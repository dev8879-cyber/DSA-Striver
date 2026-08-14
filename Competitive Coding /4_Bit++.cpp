#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int X = 0;

    while(n--) {

        string s;
        cin >> s;

        if(s[1] == '+')
            X++;
        else
            X--;
    }

    cout << X;

    return 0;
}
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int X=0;
//     for(int i=0;i<n;i++){
//         string s;
//         cin>>s;
//         if(s[1]=='+'){
//             X++;
//         }
//         else{
//             X--;
//         }
//     }
//     cout<<X;
// }