#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 26;
    int p = 3; 
    int low = 1;
    int high = 25;
    int ans = 1;
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
    cout<<ans<<" ";
}

//LEETCODE
// class Solution {
// public:
//     int mySqrt(int x) {
//     if(x==0) return x;
//     int n =x ;
//     int low = 1;
//     int high = n;
//     int ans = 1;
//     while(low<=high){
//         int mid =low +(high-low)/2;
//         long long sqr = (long long)mid*mid;
//         if(sqr>n){
//             high = mid-1;
//         }else{
//             ans=mid;
//             low=mid+1;
//         }
//     }
//     return ans;
//     }
// };