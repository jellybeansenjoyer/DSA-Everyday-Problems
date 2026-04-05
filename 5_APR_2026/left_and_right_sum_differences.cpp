#include<bits/stdc++.h>
using namespace std;
vector<int> leftRightDifference(vector<int> &nums){
    int n = nums.size();
    for(int i=1; i<n; i++){
        nums[i]+=nums[i-1];
    }
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int preSum;
        if(i>0){
            preSum=nums[i-1];
        }else{
            preSum=0;
        }
        int postSum = nums[n-1] - nums[i];
        ans[i] = abs(postSum - preSum);
    }
    return ans;
}
int main(){
    vector<int> nums = {1};
    vector<int> ans = leftRightDifference(nums);
    for(auto i: ans){
        cout<<i<<" , ";
    }
    
}