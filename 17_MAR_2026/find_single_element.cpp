#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,1,2,2,4,5,5};
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        // cout<<"mid:"<<mid<<endl;
        // cout<<"low:"<<low<<endl;
        // cout<<"high:"<<high<<endl;
        if(mid-1>=low && nums[mid]==nums[mid-1]){
            if((mid-low+1)%2==0){
                low=mid+1;
            }else{
                high=mid;
            }
        }else if(mid+1<=high && nums[mid]==nums[mid+1]){
            if((high-mid+1)%2==0){
                high=mid-1;
            }else{
                low=mid;
            }
        }else{
            ans=nums[mid];
            break;
        }
    }
    cout<<ans<<endl;
}