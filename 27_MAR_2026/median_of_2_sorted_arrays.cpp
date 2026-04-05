#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArraysBF(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            merged.push_back(nums1[i]);
            i++;
        }else{
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while(i<n1){
        merged.push_back(nums1[i]);
        i++;
    }
    while(j<n2){
        merged.push_back(nums2[j]);
        j++;
    }
    if((n1+n2)%2==0){
        int n = n1+n2;
        int indx = n/2;
        int indx2 = (n-1)/2;
        return (double)(merged[indx]+merged[indx2])/2.0000;
    }else{
        int n = n1+n2;
        int indx = n/2;
        return (double)merged[indx];
    }
}

double findMedianSortedArraysBTR(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1+n2;
    int a1=-1,a2=-1;
    int x1 = n/2,x2 = (n-1)/2;
    int i=0,j=0,cnt=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            //go into the first array
            if(cnt==x1){
                a1 = nums1[i];
            }else if(cnt==x2){
                a2 = nums1[i];
            }
            i++;
        }else{
            //go into the second array
            if(cnt==x1){
                a1 = nums2[j];
            }else if(cnt==x2){
                a2 = nums2[j];
            }
            j++;
        }
        cnt++;
    }

    while(i<n1){
        //second must have ended
        if(cnt==x1){
            a1 = nums1[i];
        }else if(cnt==x2){
            a2 = nums1[i];
        }
        i++;
        cnt++;
    }

    while(j<n2){
        //first might have ended
         if(cnt==x1){
            a1 = nums2[j];
        }else if(cnt==x2){
            a2 = nums2[j];
        }
        j++;
        cnt++;
    }
    if(n%2==0){
        cout<<a1<<" "<<a2<<endl;
        double ans = (a1+a2)/2.000;
        // cout<<ans<<endl;
        return ans;
    }else{
        return a1;
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
}
int main(){
    vector<int>nums1 = {1,5,7,9,10,16}, nums2 = {2,3,6,11,15,20};
    //{1,2,3,5,6,7,9,10,11,15,16,20}
    //{0,1,2,3,4,5,6,7, 8, 9, 10,11}
    double median = findMedianSortedArraysBTR(nums1,nums2);
    cout<<median<<endl;
    return 0;
}