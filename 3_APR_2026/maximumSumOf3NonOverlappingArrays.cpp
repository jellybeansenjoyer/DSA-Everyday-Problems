#include<bits/stdc++.h>
using namespace std;
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    long long sum=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    vector<int> ans;
    ans.push_back(sum);
    for(int i=k,j=0;i<n;i++,j++){
        sum+=sum+nums[i];
        ans.push_back(sum-nums[j]);
    }
    for(auto i : ans)
     cout<<i<<" ";
    return {1,2};
}
int main(){
    vector<int> v = {1,2,1,2,6,7,5,1};
    int k = 2;
    maxSumOfThreeSubarrays(v,k);
     
}