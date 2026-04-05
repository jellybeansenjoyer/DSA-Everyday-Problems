#include<bits/stdc++.h>
using namespace std;
int daysToShip(vector<int> &weights,int cap){
        int packages=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+sum<=cap){
                sum+=weights[i];
            }else{
                packages++;
                sum=weights[i];
            }
        }
        return packages;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int sum=0;
        for(auto ele: weights)
        {
            sum+=ele;
        }
        int high = sum;
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(daysToShip(weights,mid)>days){
                low=mid+1;
            }else{
                ans = mid;
                high=mid-1;
            }
        }
        return ans;
        
    }
    int main(){
        vector<int> weights = {1,2,3,1,1};
        int days = 4;
        // cout<<daysToShip(weights,2);
        cout<<shipWithinDays(weights,days);
    }