#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(int i=1;i<nums.size(); i++){
        nums[i]+=nums[i-1];
    }
    int ans = 0;
    mp[0]=1;
    for(int i=0;i<nums.size();i++){
        int offset = nums[i]-k;
        mp[nums[i]]++;
        if(mp.find(offset)!=mp.end()){
            ans+=mp[offset];
        }
    }
    return ans;
}
int main(){
    vector<int> nums {1,1,3,2,5,5,10,5};
    int k = 5;
    int ans = subarraySum(nums,k);
    cout<<ans<<endl;
}