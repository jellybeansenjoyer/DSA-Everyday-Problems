#include<bits/stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int len = s.length();
    vector<int> operations(len,0);
    for(auto shift: shifts){
        int left = shift[0];
        int right = shift[1];
        int direction = shift[2];
        if(direction){
            if(right+1<len){
                operations[right+1]--;
            }
            operations[left]++;
        }else{
             if(right+1<len){
                operations[right+1]++;
            }
            operations[left]--;
        }
    }
    int sum = 0;
    for(int i=0;i<len;i++)
    {   
        sum+=operations[i];
        int val = (((s[i] - 'a') + sum%26 + 26) % 26);
        char a = val + 'a';
        s[i] = a;
    }
    return s;

}