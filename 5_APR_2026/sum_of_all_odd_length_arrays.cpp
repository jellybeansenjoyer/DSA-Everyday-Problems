#include<bits/stdc++.h>
using namespace std;
int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    //1,4,2,5,3
    //1,5,7,12,15
    int sum=0;
    int k=1;
    while(k<=n){
        for(int i=k-1;i<n;i++){
            int indx = i-k;
            int left;
            if(i-k>=0){
                left = arr[indx];
            }else{
                left = 0;
            }
            sum+=(arr[i]-left);
            // cout<<"i:"<<i<<"---"<<"i-k:"<<(i-k)<<"---"<<"i-k:"<<(i-k)<<"---"<<(arr[i]-left)<<"+="<<sum<<endl;
        }
        k+=2;
    }
    return sum;
}
int main()
{
    vector<int> nums = {10,11,12};
    int ans = sumOddLengthSubarrays(nums);
    cout<<ans<<endl;
    return 0;
}