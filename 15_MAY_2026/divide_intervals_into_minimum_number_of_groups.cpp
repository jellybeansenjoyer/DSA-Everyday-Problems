#include<bits/stdc++.h>
using namespace std;
int minGroups(vector<vector<int>>& intervals) {
    vector<long long> vec(1000001,0);
    for(auto interval : intervals){
        long long left = interval[0];
        long long right = interval[1];
        if(right+1<1000001){
            vec[right+1]--;
        }
        vec[left]++;
    }
    long long maxm = 0;
    long long sum=0;
    for(int i=0;i<1000001;i++){
        sum+=vec[i];
        maxm = max(maxm,sum);
    }
    return (int)maxm;
}   
int main(){
    vector<vector<int>> intervals = {{1,4},{2,5},{7,9}};
    int ans = minGroups(intervals);
    cout<<ans<<endl;
    return 0;
}