#include<bits/stdc++.h>
using namespace std;
bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> arr(51,0);
    for(auto range: ranges){
        int start = range[0];
        int end = range[1];
        arr[start]+=1;
        if(end+1<arr.size() && end+1>=0)
            arr[end+1]-=1;
    }
    int sum =0;
    for(int i=0;i<=50;i++){
        sum+=arr[i];
        if(i>=left && i<=right && sum<=0){
            return false;
        }
    }
    return true;
}  
int main(){
    vector<vector<int>> ranges = {{1,2},{3,4},{5,6}};
    int left = 2;
    int right = 5;
    bool ans = isCovered(ranges,left,right);
    cout<<ans<<endl;
}