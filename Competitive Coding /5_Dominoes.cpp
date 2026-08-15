// #include<iostream>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     int a[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             a[i][j]=0;
//         }
//     }
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(a[i][j]==a[i][j+1]){
//                 a[i][j]=1;
//                 a[i][j+1]=1;
//                 cnt++;
//             }
//             else if(a[i][j]==a[i+1][j]){
//                 a[i][j]=1;
//                 a[i+1][j]=1;
//                 cnt++;
//             }
//         }
//     }
//     cout<<cnt;

// }
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt=(n*m)/2;
    cout<<cnt;
}