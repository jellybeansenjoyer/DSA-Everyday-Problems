#include<bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    mp[0]=1;
    
    int n = nums.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        int remainder = sum%k;
        if(remainder<0){
            remainder+=k;
        }
        mp[remainder]++;
    }
    int ans = 0;
    for(auto val: mp){
        int v = val.second;
        ans+=(v*(v-1))/2;
    }
    return ans;
}

int main(){
    vector<int> nums = {5};
    int k = 9;
    int ans = subarraysDivByK(nums,k);
    cout<<ans<<endl;
}

/*class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=k;
            if(sum<0) sum+=k; 
            if(mp.find(sum)!=mp.end()){
                cnt+=mp[sum];
            }
            mp[sum]++;
        }
        return cnt;
    }
};*/