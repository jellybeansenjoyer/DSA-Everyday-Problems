#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MIN;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[low]<=nums[mid]){
            ans = max(ans,nums[mid]);
            low=mid+1;
        }else{
            ans=max(ans,nums[high]);
            high=mid-1;
        }
    }
    cout<<ans<<" ";
}