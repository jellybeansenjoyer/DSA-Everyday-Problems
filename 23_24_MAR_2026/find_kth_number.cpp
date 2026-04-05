#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int j=0;
    for(int i=1;;i++){
        if(j<arr.size() && arr[j]==i){
            j++;
        }else{
            k--;
            if(k==0)
            return i;
        }
    }
    return 0;
}
int main(){
    vector<int> arr = {1,2,3,4};
    int k = 2;
    cout<<findKthPositive(arr,k);
}