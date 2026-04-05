#include<bits/stdc++.h>
using namespace std;
    int nthRoot(int n, int m) {
        // Code here
        int p = m; 
        int low = 0;
        int high = n;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            long long sqr = (long long)pow(mid,p);
            if(sqr>n){
                high = mid-1;
            }else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
int main(){
    cout<<nthRoot(3,3);
}
// LEETCODE
    // int nthRoot(int n, int m) {
    //     // Code here
    //     int p = m; 
    //     int low = 0;
    //     int high = n;
    //     int ans = 0;
    //     while(low<=high){
    //         int mid = (low+high)/2;
    //         long long sqr = (long long)pow(mid,p);
    //         if(sqr>n){
    //             high = mid-1;
    //         }else{
    //             ans=mid;
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }

//GFG
// class Solution {
//   public:
//     int nthRoot(int n, int m) {
//         // Code here
//         int p = n; 
//         int low = 0;
//         int high = m;
//         int ans = -1;
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             long long sqr = (long long)pow(mid,p);
//             if(sqr>m){
//                 high = mid-1;
//             }else if(sqr<m){
//                 low=mid+1;
//             }else{
//                ans=mid; 
//                break;
//             }
//         }
//         return ans;
//     }
// };