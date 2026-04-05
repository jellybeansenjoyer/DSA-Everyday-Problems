#include<bits/stdc++.h>
using namespace std;
int findHrs(vector<int> &piles,int k){
    int hrs = 0;
    for(auto element: piles){
        hrs+=ceil((double)element/k);
    }
    return hrs;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(),piles.end());
    int ans = 0;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(findHrs(piles,mid)>h){
            low = mid + 1;
        }else{
            ans = mid;
            high = mid -1;
        }
    }
    // return high;
    // cout<<low<<endl;  
    return ans;      
}
int main()
{
    // vector<int> v = {3,6,7,11};
    // vector<int> v = {30,11,23,4,20};
    vector<int> v = {44,22,33,11,1};
    // cout<<findHrs(v,4);
    // cout<<ceil((double)3/3);   
    cout<<minEatingSpeed(v,5)<<endl;
    return 0;
}