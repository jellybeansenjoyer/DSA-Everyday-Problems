#include<bits/stdc++.h>
using namespace std;
int numFriendRequestsBF(vector<int>& ages) {
    sort(ages.begin(),ages.end());
   int n = ages.size();
   int ans = 0;
   for(int j=n-1;j>=0;j--){
        int limit = ages[j]/2 + 7;
        int i = j - 1;

        while(i>=0 && ages[i]>limit){
            if(ages[i]==ages[j]){
                ans+=2;
            }else{
                ans++;
            }
            i--;
        }
   }
   return ans;
}
int numFriendRequests(vector<int>& ages) {
    vector<int> cnt(121,0);
    vector<int> pre(122,0);
    for(auto i: ages){
        cnt[i]++;
    }

    for(int i=0;i<121;i++){
        pre[i+1]=pre[i]+cnt[i];
    }
    int valid_req = 0;
    for(int i=15;i<cnt.size();i++){
        if(cnt[i]!=0 ){
        int lower_bound = floor(i*0.5+7);
        int count = pre[i+1]-pre[lower_bound+1] -1;
        valid_req += count*cnt[i];
        }
    }
    return valid_req;
}
int main()
{
    vector<int> age = {16,12};
    int ans = numFriendRequests(age);
    cout<<ans<<endl;
}