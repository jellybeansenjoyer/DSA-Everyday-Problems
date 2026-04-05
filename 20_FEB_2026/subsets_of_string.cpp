#include<bits/stdc++.h>
using namespace std;
void printSubsets(string word,int i,int n,string k){
    if(i>=n){ cout<<k<<endl; return;}

        //notPick
        printSubsets(word,i+1,n,k);
        //pick
        printSubsets(word,i+1,n,k+""+word[i]);
    
}
int main(){
    printSubsets("abc",0,3,""); 
    
}

//         (0,'')------------------------------------------------------
//         |                                                           |
//         |                                                           |
//         |                                                           |
//         |                                                           |      
//         |                                                           |
//         |                                                           |
//      (1,'')----------                                               (1,'a')
//      |.              \                                               |.              \    
//      |                \                                                  |           \     
//      (2,'')             (2,'b')\                                         (2,'a')             (2,'ab')\    
//     |    \                  |.  \->(3,'bc') -> 'bc'                     |    \                  |.  \->(3,'abc') -> 'abc'    
//     |     \                 |                                           |     \                 |
// (3,'')->'' (3,'c')->'c'     (3,'b') ->'b'                           (3,'a')->'a' (3,'ac')->'ac'     (3,'ab') ->'ab' 


// TOP SOLUTION:
//  vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>result={{}};
//         for(int num : nums){
//             int size=result.size();
//             for(int i=0;i<size;i++){
//                 vector<int> temp= result[i];
//                 temp.push_back(num);
//                 result.push_back(temp);
//             }
//         }
//         return result;
//     }



//LEETCODE PROBLEM SELF SOLUTIONN
// class Solution {
// public:
//     void solve(vector<vector<int>> &ans,int i,vector<int> bucket,vector<int> &nums){
//         if(i>=nums.size()){
//             ans.push_back(bucket);
//             return;
//         }

//         //notpick
//         solve(ans,i+1,bucket,nums);
//         //pick
//         bucket.push_back(nums[i]);
//         solve(ans,i+1,bucket,nums);
        
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> bucket;
//         int n = nums.size();
//         solve(ans,0,bucket,nums);
//         return ans;
//     }
// };