#include<bits/stdc++.h>
using namespace std;
int canPlace(vector<int> &stalls,int val,int k){
    //Already placing one cow at i
    k--;
    for(int i=0,j=1;j<stalls.size();j++){
        int dist = stalls[j] - stalls[i];
        if(dist>=val){
            //I can place the cow;
            k--;
            //Update the Pointer to next Stall;
            i=j;
            if(k==0)
                return true;
        }
    }
    if(k>0)
    return false;
    else 
    return true;
}
int aggressiveCows(vector<int> &stalls, int k) {
    // code here
    //Step 1: Sort the Array
    sort(stalls.begin(),stalls.end());
    //Step 2: Initialization
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = 1;
    //Step 3: Binary Search
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canPlace(stalls,mid,k)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}
int main(){
    vector<int> stalls = {2, 12, 11, 3, 26, 7};
    int k = 5;
    int ans = aggressiveCows(stalls,k);
    cout<<ans<<endl;
}