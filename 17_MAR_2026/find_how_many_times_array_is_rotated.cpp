#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {3,4,5,1,2};
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    int index=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[low]<=nums[mid]){
            if(nums[low]<ans){
                ans = nums[low];
                index = low;
            }
            low=mid+1;
        }else{
             if(nums[mid]<ans){
                ans = nums[mid];
                index = mid;
            }
            high=mid-1;
        }
    }
    cout<<index<<" ";
}