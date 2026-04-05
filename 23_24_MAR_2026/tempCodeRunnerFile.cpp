#include<bits/stdc++.h>
using namespace std;
int studentsWithPages(vector<int> &arr,int pages){
    int students = 1;
    int sum = 0;
    for(int j=0;j<arr.size();j++){
        if(sum+arr[j]<=pages){
            sum = sum + arr[j];
        }else{
            students++;
            sum = arr[j];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int k) {
    // code here
    //maximum_element;
    sort(arr.begin(),arr.end());
    int low = *max_element(arr.begin(),arr.end());
    int high =0;
    //sum of elementes
    for(int i=0;i<arr.size();i++){
        high+=arr[i];
    }
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high - low)/2;
        int students = studentsWithPages(arr,mid);
        if(students>k){          
            low = mid + 1;
        }else{
             if(students==k){
                cout<<"mid:"<<mid<<endl;
                ans = min(ans,mid);
            }
            high = mid - 1;
        }
    }
    if(ans==INT_MAX) return -1;
    return ans;
}
int main(){
    vector<int> arr = {15, 10, 19 ,10 ,5 ,18, 7};
    int k = 5;
    int ans = studentsWithPages(arr,20);
    // int ans = findPages(arr,k);
    cout<<ans<<endl;
    return 0;
}