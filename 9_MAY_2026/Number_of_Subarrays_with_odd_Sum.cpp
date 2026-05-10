#include<bits/stdc++.h>
using namespace std;
int numOfSubarrays(vector<int>& arr) {
    //oddParity = 1 | evenParity = 1
    //[1, 3, 5]
    //[]
    long long MOD = 1000000007;
    int oddParity = 0;
    int evenParity = 1;
    int n = arr.size();
    int prefixSum = 0; 
    long long cnt = 0;
    for(int i=0; i<n; i++){
        prefixSum+=arr[i];
        int currentParity = prefixSum%2==0;
        if(currentParity){
            //EVEN
            cnt+=oddParity;
            evenParity++;
        }else{
            //ODD
            cnt+=evenParity;
            oddParity++;
        }
    }
    return cnt%MOD;
}   
int main(){
    vector<int> arr = {1, 3, 5};
    int ans = numOfSubarrays(arr);
    cout<<ans<<endl;
}

// //class Solution {
// public:
// int numOfSubarrays(vector<int>& arr) {
//     long long oddCount = 0, prefixSum = 0;
//     for(int a : arr) {
//         prefixSum += a;
//         oddCount += prefixSum % 2;
//     }
//     oddCount += (arr.size() - oddCount) * oddCount;
//     return oddCount % 1'000'000'007;
// }
// };
