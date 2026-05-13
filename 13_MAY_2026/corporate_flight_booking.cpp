#include<bits/stdc++.h>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int size = n;
    vector<int> ans(n,0);
    for(auto booking : bookings){
        int first = booking[0];
        int last = booking[1];
        int seats = booking[2];
        ans[first-1]+=seats;
        if(last<n){
            ans[last]-=seats;
        }
    }
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    return ans;
}
