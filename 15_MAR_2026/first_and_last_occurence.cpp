#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> arr = {2,4,6,8,8,8,11,13};
    // vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    vector<int> arr = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int low = 0;
    int high = arr.size()-1;
    int target = 7;
    pair<int,int> p = {-1,-1};
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=target){
            if(target==arr[mid])
                p.first = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }
    low = 0;
    high = arr.size() - 1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]<=target){
            low = mid+1;
            if(target==arr[mid])
                p.second = mid;
        }else{
            high = mid-1;
        }
    }

    cout<<p.first<<" "<<p.second<<endl;
}