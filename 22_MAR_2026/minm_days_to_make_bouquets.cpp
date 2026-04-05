#include<bits/stdc++.h>
using namespace std;
int bouquestInDays(vector<int> &bloomDay,int mid,int k){
    int bouquets=0,cnt=0;
    int j=0;
    while(j<bloomDay.size()){
        if(mid>=bloomDay[j]){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt>=k){
            bouquets++;
            cnt=0;
        }
        j++;
    }
    return bouquets;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(),bloomDay.end());
    int high = *max_element(bloomDay.begin(),bloomDay.end());
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        // cout<<"mid:"<<mid<<endl;
        if(bouquestInDays(bloomDay,mid,k)<m){
            low = mid + 1;
        }else{
            ans = min(mid,ans);
            high = mid - 1;
        }
    }    
    if(ans==INT_MAX) return -1;
    return ans;
}

int main(){
    vector<int> v = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    // int ans = bouquestInDays(v,1,2);
    int ans = minDays(v,m,k);
    cout<<ans;
}