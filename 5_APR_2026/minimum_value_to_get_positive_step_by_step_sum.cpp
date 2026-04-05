#include<bits/stdc++.h>
using namespace std;
int minStartValue(vector<int>& nums) {
        int ans = 0,sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans = min(ans,sum);
        }
        return abs(ans)+1;
}
int main(){
    vector<int> nums = {-5,1,5,0,-7};
    int ans = largestAltitude(nums);
    cout<<ans<<endl;
    return 0;
}
