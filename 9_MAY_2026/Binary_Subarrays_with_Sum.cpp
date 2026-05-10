#include<bits/stdc++.h>
using namespace std;
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int prefixSum = 0;
    int n = nums.size();
    unordered_map<int,int> mp;
    mp[0]=1;
    int cnt = 0;
    for(int i=0; i<n; i++){
        prefixSum+=nums[i];
        int target = prefixSum-goal;
        if(mp.count(target)){
            cnt+=mp[target];
        }
        mp[prefixSum]++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    int ans = numSubarraysWithSum(nums,goal);
    cout<<ans<<endl;
}

// class Solution {
// public:
//     int solve(vector<int>& nums, int k) {
//         if (k < 0)
//             return 0;
//         int n = nums.size();
//         int l = 0;
//         int curr = 0;
//         int cnt = 0;
//         for (int r = 0; r < n; r++) {
//             curr += nums[r];
//             while (curr > k) {
//                 curr -= nums[l];
//                 l++;
//             }

//             cnt += (r - l + 1);
//         }
//         return cnt;
//     }

//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int a = solve(nums, goal);
//         int b = solve(nums, goal - 1);
//         return a - b;
//     }
// };
