#include<bits/stdc++.h>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity) {
    int endp = 1001;
    int n = trips.size();
    vector<int> kilometers(endp,0);
    for(auto trip : trips){
        int passengers = trip[0];
        int from = trip[1];
        int to = trip[2];
        kilometers[from]+=passengers;
        if(to<endp){
            kilometers[to]-=passengers;
        }
    }
    int sum=0;
    for(int i=0;i<endp;i++){
        sum+=kilometers[i];
        if(sum>capacity){
            return false;
        }
    }
    return true;
}