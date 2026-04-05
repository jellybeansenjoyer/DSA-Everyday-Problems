#include<bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n,0);
        unordered_map<long long,int> mp;
        prefixSum[0] = nums[0];
        long long ans = INT_MIN;
        for(int i=1;i<n;i++){
            prefixSum[i]+=(prefixSum[i-1]+nums[i]);
        }
        for(int i=0;i<n;i++){
            long long v1 = nums[i] - k;
            long long v2 = nums[i] + k;
            if(mp.find(v1)!=mp.end()){
                int i1 = mp[v1];
                if(i1-1>=0){
                    ans = max(ans,prefixSum[i]-prefixSum[i1-1]);
                }else{
                    ans = max(ans,prefixSum[i]);
                }
            }else if(mp.find(v2)!=mp.end()){
                int i2 = mp[v2];
                if(i2-1>=0){
                    ans = max(ans,prefixSum[i]-prefixSum[i2-1]);
                }else{
                    ans = max(ans,prefixSum[i]);
                }
            }
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]] = i; 
            }
        }
        return ans;
}
int main(){
    vector<int> nums = {-1,3,2,4,5};
    //{1,2,3,4,5,6}
    //{1,3,6,10,15,21}
    int k = 3;
    long long ans = maximumSubarraySum(nums,k);
    cout<<ans<<endl;
}
