#include<bits/stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<int>& shifts) {
    int n = shifts.size();
    vector<long long> ans(n,0);
    long long sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=shifts[i];
        ans[i]=sum;
        // cout<<sum<<",";
    }
    for(int i=0;i<s.length();i++){
        int x = s[i]-'a';
        int y = ((long long)(x+ans[i]))%26;
        cout<<y<<endl;
        s[i] = y+'a';
    }
    return s;
}
