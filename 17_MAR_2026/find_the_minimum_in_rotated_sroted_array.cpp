#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {11,13,15,17};
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low=mid+1;
        }else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    cout<<ans<<" ";
}