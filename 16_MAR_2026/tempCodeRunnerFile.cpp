#include<bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> arr =    {7,8,9,1,2,3,4,5,6};
    vector<int> arr = {33, 42, 72, 99};
    int low = 0;
    int high = arr.size()-1;
    int target = 42;
    while(low<=high){
        int mid = low + (high-low)/2;
        //in range of the first half
        if(target == arr[mid]) {cout<<mid<<endl; return 0;}
        if(arr[low]<=arr[mid]){
            if(!(target<=arr[low] && target>=arr[mid])
            low = mid + 1;
            else 
            high = mid - 1;
        }else if(arr[mid]<=arr[high]){
            if(!(target<=arr[mid] && target>=arr[high]))
            high = mid - 1;
            else 
            low = mid + 1;
        }
    }
    cout<<-1<<endl;
    return 0;
}