#include<bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> mp;
    mp[0]=-1;
    int prefixSum = 0;
    int n = nums.size();
    int maxm = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==0){
            prefixSum--;
        }else{
            prefixSum++;
        }
        if(mp.count(prefixSum)){
            int index = mp[prefixSum];
            maxm = max(maxm,i-index);
        }else{
            mp[prefixSum] = i;
        }
    }
    return maxm;
}
int main(){
    vector<int> nums = {0,1};
    int ans = findMaxLength(nums);
    cout<<ans<<endl;
}