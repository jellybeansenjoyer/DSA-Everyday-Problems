#include<bits/stdc++.h>
using namespace std;
int maximumBeautyBF (vector<int>& nums, int k) {
    long long minm = INT_MAX,maxm = INT_MIN;
    for(auto i: nums)
        minm = min((long long)i-k,minm);

    if(minm<=0) minm = 0;

    for(auto i: nums){
        maxm = max(maxm,(long long)i+k);
    }
    vector<long long> prefix(maxm+1,0);
    for(auto i: nums){
        for(long long j=i-k;j<=(long long)i+k;j++){
            if(j>=0)
            prefix[j]++;
        }
    }
    long long ans = 0;
    for(int i=0;i<prefix.size();i++){
        ans = max(ans,prefix[i]);
    }
    return ans;
}
int main(){
    vector<int> v = {1,1,1,1};
    int k = 10;
    int ans = maximumBeauty(v,k);
    cout<<ans<<endl;
    return 0;
}