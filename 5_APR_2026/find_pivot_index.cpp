#include<bits/stdc++.h>
using namespace std;
/*Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index 
is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
*/
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i=1; i<n; i++){
        nums[i]+=nums[i-1];
    }
    for(int i=0; i<n; i++){
        int leftSum;
        int rightSum;
        if(i-1>=0)
            leftSum = nums[i-1];
        else{
            leftSum = 0;
        }
        rightSum = nums[n-1] - nums[i];
        if(leftSum==rightSum) return i;
    }
    return -1;

}

int main(){
    
    vector<int> nums = {2,1,-1};
    int ans = pivotIndex(nums);
    cout<<ans<<endl;
}