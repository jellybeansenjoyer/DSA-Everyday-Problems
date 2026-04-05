#include<bits/stdc++.h>
using namespace std;
bool studentsWithPages(vector<int> &arr,int pages,int students){
    students--;
    int n = arr.size();
    int sum = 0;
    for(int j=0;j<arr.size();j++){
        if(sum+arr[j]<=pages&&n-j>students){
            sum = sum + arr[j];
        }else{
            // cout<<"came:"<<sum<<endl;
            students--;
            sum = arr[j];
        }
    }
    // cout<<"students:"<<students<<endl;
    if(students==0) return true;
    return false;
}
int findPages(vector<int> &arr, int k) {
    // code here
    //maximum_element;
    // sort(arr.begin(),arr.end());
    int low = *max_element(arr.begin(),arr.end());
    int high =0;
    //sum of elementes
    for(int i=0;i<arr.size();i++){
        high+=arr[i];
    }
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(studentsWithPages(arr,mid,k)){   
            ans = min(ans,mid);       
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if(ans==INT_MAX) return -1;
    return ans;
}
int main(){
    // vector<int> arr = {15, 10, 19 ,10 ,5 ,18, 7};
    vector<int> arr = {15,17,20};
    int k = 5;
    // bool ans = studentsWithPages(arr,25,k); 
    int ans = findPages(arr,k);
    cout<<ans<<endl;
    return 0;
}