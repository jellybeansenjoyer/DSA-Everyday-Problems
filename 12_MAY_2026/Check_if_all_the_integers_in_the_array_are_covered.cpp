#include<bits/stdc++.h>
using namespace std;
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    sort(ranges.begin(),ranges.end(),[](vector<int>& a, vector<int>& b){        
        return a[0] < b[0]; 
    });


    int cnt=0;
    int n = ranges.size();
    int i = left;
    while(cnt<n && i<=right){

        int l = ranges[cnt][0];
        int r = ranges[cnt][1];
        // cout<<l<<" "<<r<<endl;
        if(i>=l && i<=r){
            i++;
        }else{
            cnt++;
        }
    }
    
    return i>right;
}   
int main(){
    vector<vector<int>> ranges = {{1,2},{3,4},{5,6}};
    int left = 2;
    int right = 5;
    bool ans = isCovered(ranges,left,right);
    cout<<ans<<endl;
}