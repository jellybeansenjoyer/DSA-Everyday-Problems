#include<bits/stdc++.h>
using namespace std;
vector<int> smallerNumbersThanCurrentBF(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(nums[j]<nums[i]){
                    ans[i]++;
                }
            }
        }
    }
    return ans;
}
vector<int> smallerNumbersThanCurrent(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n,0);
    vector<int> pre(102,0);
    unordered_map<int,int> mp;

    for(auto i: nums){
        mp[i]++;
    }
    for(int i=0;i<=102;i++){
        pre[i+1]+= (pre[i]+mp[i]);
    }
   
    for(int i=0;i<n;i++){
        nums[i] = pre[nums[i]];
    }
    return nums;
}
int main(){
    vector<int> nums = {6,5,4,8};
    vector<int> ans = smallerNumbersThanCurrent(nums);
    
    for(auto i: ans){
        cout<<i<<endl;
    }
    cout<<endl;
}