// 1.. sorted rotated-->>> a[i]>a[(i+1)%n]

// 2.. Unordered set-> ssen.find(elem)!=seen.end()

// 3.. Kadane's Algo: Uses three pointers:Start, ansSt, ansEd.Start->where sum>0 and assign it to ansSt. The loop runs from i=ansSt=Start to i=ansEd until sum remains greater than 0. 
// for(int i=0;i<n;i++){
//     if(sum==0){
//         start=i;
//     }
//     sum+=a[i];
//     if(sum>maxi){
//         maxi=sum;
//         ansSt=start;
//         ansEd=i;
//     }
//     if(sum<0){
//         sum=0;
//     }
// }

// 4.. Largest elem: if(a[i]>a[i+1]) lasrgest=a[i]

// 5..Leader: Loop backwards. L=a[n-1]. if(a[i]>L), L=a[i] -->print(L)

// 6.. Longest Consecutive. 