#include<bits/stdc++.h>
using namespace std;
int findMiddleIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i=1; i<n; i++){
        nums[i]+=nums[i-1];
    }        
    int ans = n;
    for(int i=0; i<n; i++){
        int preSum;
        int postSum;
        if(i-1>=0){
            preSum = nums[i-1];
        }else{
            preSum = 0;
        }
        postSum=nums[n-1]-nums[i];
        if(postSum==preSum){
            ans = min(i,ans);
        }
    }
    if(ans==n){
        return -1;
    }
    return ans;
}
int main(){
    vector<int> nums = {2,3,-1,8,4};
    int ans = findMiddleIndex(nums);
    cout<<ans<<endl;
}