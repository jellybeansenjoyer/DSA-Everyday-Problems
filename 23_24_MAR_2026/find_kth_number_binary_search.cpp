#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int missing = arr[mid] - (mid+1);
        // cout<<"mid:"<<mid<<endl;
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    // cout<<"high:"<<high<<endl;
    int number;
    if(high<0){
        number = 0;
    }
    else { 
        number = arr[high];
    }
    
    return number + (k-(number-(high+1)));
}
int main(){
    vector<int> arr = {1};
    int k = 7;
    cout<<findKthPositive(arr,k);
}