#include<bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int>& nums, int k) {
    int prefixSum=0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    int cnt =0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]%2!=0){
            prefixSum+=1;
        }
        int target = prefixSum - k;
        if(mp.count(target))
        {
            cnt+=mp[target];
        }
        mp[prefixSum]++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int ans = numberOfSubarrays(nums,k);
    cout<<ans<<endl;
}

// int findKSubArrays(vector<int>& nums, int k){
//     if(k<0){
//         return 0;
//     }
//     int l=0,r=0,cnt=0,res=0;
//     int n=nums.size();
//     while(r<n){
//         cnt+=nums[r]%2==1;
//         while(cnt>k){
//             if(nums[l]%2==1){
//                 cnt--;
//             }
//             l++;
//         }
//         res+=r-l+1;
//         r++;
//     }
//     return res;
// }
// int numberOfSubarrays(vector<int>& nums, int k) {
//     int ans=findKSubArrays(nums,k)-findKSubArrays(nums,k-1);
//     return ans;
// }
