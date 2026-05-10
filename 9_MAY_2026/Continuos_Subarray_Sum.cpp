#include<bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    // x % k = (n*k) % k
    // [nums[right] - nums[left]] % k = (n*k) % k
    // [nums[right]] % k = nums[left] % k
        
    //Calculate the Subarray Sum
    int n = nums.size();
    for(int i=1; i<n; i++){
        nums[i]+=nums[i-1];
    }
    
    unordered_map<int,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        int right = nums[i];
        int remainder = right%k;
        if(mp.find(remainder)!=mp.end()){
            int index = mp[remainder];
            int length = i - index;
            if(length>=2) return true;
        }else{
            mp[remainder] = i;
        }
        
    }
    return false;
}

int main(){
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    bool ans = checkSubarraySum(nums,k);
    if(ans) cout<<"true"; else cout<<"false";
}

/*
High Optimization Code
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> m;

        // Base case: remainder 0 at index -1
        m[0] = -1;

        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefix = prefix + nums[i];

            int rem = prefix % k;

            // Handle negative remainder
            if (rem < 0) {
                rem = rem + k;
            }

            // If remainder seen before
            if (m.count(rem)) {

                int prevIndex = m[rem];

                // Ensure subarray size >= 2
                if (i - prevIndex >= 2) {
                    return true;
                }
            } 
            else {
                m[rem] = i;
            }
        }

        return false;
    }
};*/