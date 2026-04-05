#include<bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int>& gain) {
        int ans = 0,sum=0;
        int n = gain.size();
        for(int i=0;i<n;i++){
            sum+=gain[i];
            ans=max(sum,ans);
        }
        return ans;
}
int main(){
    vector<int> nums = {-5,1,5,0,-7};
    int ans = largestAltitude(nums);
    cout<<ans<<endl;
    return 0;
}
