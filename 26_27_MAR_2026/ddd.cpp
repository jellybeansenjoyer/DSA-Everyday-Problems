#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int stationsRequired(vector<int> &stations, long double maxDist) {
    int cnt = 0; // Changed to long long
    int n = stations.size();
    
    for(int i = 0; i < n - 1; i++) {
        int dist = (stations[i+1] - stations[i]);
        
        // Changed to long long to prevent overflow when maxDist is tiny
        long long stationsNeeded = dist / maxDist; 
        
        if(abs((stations[i+1] - stations[i]) == (stationsNeeded * maxDist)) ) {
            stationsNeeded--;
        }
        
        cnt += stationsNeeded;
    }
    return cnt;
}

double minMaxDistOpt(vector<int> &stations, int K) {
    long double low = 0.0;
    long double high = 0.0;
    int n = stations.size();
    
    for(int i = 0; i < n - 1; i++) {
        high = max((long double)(stations[i+1] - stations[i]), high);
    }
    
    long double diff = 1e-7; // Tightened precision bound
    long double ans = high;  // Safely initialized
    
    while(high - low > diff) {
        long double mid = low + (high - low) / 2.0;
        int stationsReq = stationsRequired(stations, mid);
        
        if(stationsReq > K) {
            low = mid;
        } else {
            ans = mid;
            high = mid;
        }
    }
    return (double)ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    double ans = minMaxDistOpt(arr, k);
    cout << ans << endl;
    return 0;
}