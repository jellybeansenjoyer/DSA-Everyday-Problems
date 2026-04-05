// #include<bits/stdc++.h>
// using namespace std;
// bool gasStationsWithMaxDistance(vector<int> &stations,double mid,int k){
//     int n = stations.size();
//     for(int j=0;j<n-1;j++){
//         int dist = stations[j+1] - stations[j];
//         if(dist>mid){
//             int needStations = dist/mid;
//             if(needStations<=k){
//                 k=k-needStations;
//             }else{
//                 return false;
//             }
//         }
//     }
//      return true;
// }
// double minMaxDist(vector<int> &stations, int K) {
//     long double high=stations[1]-stations[0];
//     double low = 0.0;
//     for(int i=0;i<stations.size()-1;i++){
//         if((stations[i+1]-stations[i])>high){
//             high = (long double)stations[i+1]-stations[i];
//         }
//     }
//     double ans = INT_MAX;
//     double long diff = 1e-6;
//     while(high - low > diff){
//         double mid = (low + high)/(2.0);
//         if(gasStationsWithMaxDistance(stations,mid,K)){
//             if(ans<mid){
//                 ans = mid;
//             }
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<int> stations = {1, 2, 3, 4, 5};
//     int k = 2;
//     cout<<minMaxDist(stations,k)<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
//bruteForce Approach
double minMaxDistBF(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        vector<int> howMany(n-1,0);
        for(int j=0;j<K;j++){
            int maxValue = -1,maxIndex = -1;
            for(int i=0;i<n-1;i++){
                long double diff = (stations[i+1]-stations[i]);
                long double val = diff/(long double)(howMany[i]+1);
                if(val>maxValue){
                    maxValue = val;
                    maxIndex = i;
                }
            }
            howMany[maxIndex]++;
        }
        //DEBUG 
        for(int i=0;i<n-1;i++){
            cout<<howMany[i]<<",";
        }
        cout<<endl;
        long double ans = -1;
        for(int i=0;i<n-1;i++){
            long double diff = (stations[i+1] - stations[i]);
            long double val = diff/((long double)howMany[i]+1);
            // if(howMany[i]!=1){
            //     val = ;
            // }else{
            //     val = diff;
            // }
            if(val>ans){
                ans = val;
            }
        }
        return ans;
        
    }
double minMaxDistBTR(vector<int> &stations, int K) {
    //maxHeap
    priority_queue<pair<long double,int>> pq;
    int n = stations.size();
    for(int i=0;i<n-1;i++){
        pq.push({stations[i+1]-stations[i],i});        
    }
    vector<int> howMany(n-1,0);
    for(int i=0;i<K;i++){
        auto top_element = pq.top();
        pq.pop();
        int indx = top_element.second;
        long double initDist = (stations[indx+1]-stations[indx]);
        howMany[indx]++;
        long double newDist = initDist/((long double)howMany[indx]+1);
        pq.push({newDist,indx});
    }
    auto top_element = pq.top();
    int indx = top_element.second;
    long double dist = (stations[indx+1]-stations[indx]);
    long double ans = dist/((long double)howMany[indx]+1);
    return ans;
}

int stationsRequired(vector<int> &stations,long double maxDist){
    int cnt = 0;
    int n = stations.size();
    for(int i=0;i<n-1;i++){
        int dist = (stations[i+1]-stations[i]);
        int stationsNeeded = dist/(maxDist);
        if(abs((stations[i+1]-stations[i]) - (stationsNeeded*maxDist)) <= 1e-9){
            stationsNeeded--;
        }
        cnt+=stationsNeeded;
    }
    // cout<<"cnt:"<<cnt<<endl;
    return cnt;
}
double minMaxDistOpt(vector<int> &stations, int K) {
    long double low = 0.0;
    long double high=0.0;
    int n = stations.size();
    for(int i=0;i<n-1;i++){
        high = max((long double)(stations[i+1]-stations[i]),high);
    }
    // cout<<"high:"<<high<<endl;
    long double diff = 1e-7;
    long double ans = high;
    while(high-low>diff){
        long double mid = (low + high)/(2.0);
        int stationsReq = stationsRequired(stations,mid);
        if(stationsReq>K){
            low = mid;
        }else{
            ans = mid;
            high = mid;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k=2;
    double ans = minMaxDistOpt(arr,k);
    cout<<ans<<endl;
}