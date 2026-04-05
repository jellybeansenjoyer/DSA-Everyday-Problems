#include<bits/stdc++.h>
using namespace std;
int hIndex(vector<int>& citations) {
    vector<int> freq(1001,0);
    for(auto i: citations){
        freq[i]++;
    }
    vector<int> pre(1003,0);
    for(int i=1002;i>=0;i--){
        pre[i] += (pre[i+1]+freq[i]);
    }
    int maxm=0;
    for(int i=0;i<1002;i++){
        if(pre[i]>=i)
        {
            maxm = max(maxm,i);
        }
    }
    return maxm;
}
int main(){
    vector<int> v = {3,0,6,1,5};    
    int hInd = hIndex(v);
    cout<<hInd<<endl;
}