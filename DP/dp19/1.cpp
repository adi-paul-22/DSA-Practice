#include<bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int> &wt, vector<int>& val,int ind, int w,vector<vector<int>>& dp){
    if(ind==0) {
        if(wt[0]<= w) return val[0];
        else return 0;
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,w,dp);
    
    int taken = INT_MIN;
    if(wt[ind]<= w)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,w-wt[ind],dp);
        
    return dp[ind][w] = max(notTaken,taken);
}

int knapsack(vector<int> &wt, vector<int> &val,int n,int w){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return knapsackUtil(wt,val,n-1,w,dp);
}

int main(){
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    
    int w = 5;
    int n = wt.size();
    
    cout<<"The maximum value of items the thief can steal is "<<
    knapsack(wt,val,n,w);
}