#include<bits/stdc++.h>
using namespace std;
bool canHeat(vector<int>& houses,vector<int>& heaters,int radius){
    int n = houses.size();
    int m = heaters.size();
    int j = 0;
    for(int i=0;i<n && j<m;i++){
        int house_point = houses[i];
        int lower_bound = heaters[j] - radius;
        int upper_bound = heaters[j] + radius;
        if(house_point<lower_bound){
            
            return false;
        }    
        while(j<m && !(house_point<=(heaters[j] + radius)&&house_point>=(heaters[j] - radius))){
            j++;
        }
    }
    if(j>=m){
        return false;
    }
return true;
}
int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low = 0;
        int high = houses[houses.size()-1] - houses[0];
        for(auto i: heaters){
            int l = houses[0];
            int r = houses[houses.size()-1];
            high = max(high,max(abs(l-i),abs(r-i)));
        }
        cout<<"high:"<<high<<endl;
        int ans=INT_MAX;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canHeat(houses,heaters,mid)){
                // cout<<"mid:"<<mid<<endl;
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
int main(){
    vector<int> houses = {1,2,3,4}, heaters = {2000000};
    int k = 1;
    //{-4,8}
    // cout<<"jj:"<<canHeat(houses,heaters,k)<<endl;
    int ans = findRadius(houses,heaters);
    cout<<ans<<endl;
}