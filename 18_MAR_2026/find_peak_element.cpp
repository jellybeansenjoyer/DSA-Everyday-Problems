#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> nums = {3,4,5,1,2};
    // vector<int> nums = {1,2,1,3,5,6,4};
    // vector<int> nums = {99,2,3,4,54,6,7,8,9,10,9,100000,7,6,5,11,3,2,32};
    // vector<int> nums = {1,10,13,7,6,5,4,2,1,0};
    vector<int> nums = {5,1,2};
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MIN;
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0],nums[1]);
    while(low<=high){
        int mid = low+(high-low)/2;
        ans = max(ans,nums[mid]);
        if(mid+1<nums.size()&&nums[mid+1]>=nums[mid]){
            low=mid+1;
        }else if(mid-1>=0&&nums[mid-1]>=nums[mid]){
            high =mid-1;
        }else{
            break;
        }
    }
    cout<<ans<<" ";

}
//LEETCODE SOLUTION
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//     int low = 0;
//     int high = nums.size()-1;
//     int ans = INT_MIN;
//     if(nums.size()==1) return 0;
//     // if(nums.size()==2) return max(nums[0],nums[1]);
//     while(low<=high){
//         int mid = low+(high-low)/2;
//         if(mid+1<nums.size()&&nums[mid+1]>=nums[mid]){
//             low=mid+1;
//         }else if(mid-1>=0&&nums[mid-1]>=nums[mid]){
//             high =mid-1;
//         }else{
//             return mid;
//         }
//     }
//     return -1;
//     }
// };