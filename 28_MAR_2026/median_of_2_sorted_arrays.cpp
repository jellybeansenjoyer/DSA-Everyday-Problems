#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1>n2) return findMedianSortedArrays(nums2,nums1);
    int left = (n1+n2+1)/2;
    int low=0,high = n1;
    while(low<=high){
        int mid1 = low + (high-low)/2;
        int mid2 = left - mid1;
        int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
        if(mid1>=0 && mid1<n1){
            r1 = nums1[mid1];
        }
        if(mid2>=0 && mid2<n2){
            r2 = nums2[mid2];
        }
        if(mid1-1>=0 && mid1-1<n1){
            l1 = nums1[mid1-1];
        }
        if(mid2-1>=0&&mid2-1<n2){
            l2 =nums2[mid2-1];
        }

        if(l2>r1){
            low = mid1+1;
        }else if (l1>r2)
        {
            high = mid1-1;
        }else{
            if((n1+n2)%2==0){
            int minm = min(r1,r2);
            int maxm = max(l1,l2);
            return (double)(minm+maxm)/2.0;
            }
            else{
                int maxm = max(l1,l2);
                return (double)(maxm);
            }
        }
    }
    return 0.0;
}
int main(){
    vector<int> nums1 = {1,3} , nums2 = {2,5};
    double ans = findMedianSortedArrays(nums1,nums2);
    cout<<ans<<endl;

}