#include<bits/stdc++.h>
using namespace std;
int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> arr(2051,0);
    int n = arr.size();
    for(auto log : logs){
        int birth = log[0];
        int death = log[1];
        arr[birth]+=1;
        if(death>=0 && death<n){
            arr[death]-=1;
        }
    }
    int maxm = 0;
    int year = 1950;
    int population=0;
    for(int i=1950;i<n;i++){
        population+=arr[i];
        if(population>maxm){
            maxm = population;
            year = i;
        }
    }
    return year;
}