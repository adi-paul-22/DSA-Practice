#include<bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int> &wt,vector<int> &val,int ind, int w,
vector<vector<int>> &dp){
    if(ind == 0 ) return ((int)(w/wt[0])) * val[0];
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,w,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= w)
        taken = val[ind] + knapsackUtil(wt,val,ind,w-wt[ind],dp);
        
    return dp[ind][w] = max(taken,notTaken);
}

int unboundedKnapack(int n, int w, vector<int>& val, vector<int>& wt){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return knapsackUtil(wt,val,n-1,w,dp);
}

int main(){
    vector<int> wt = {2,4,6};
    vector<int> val = {5,11,13};
    int w = 10;
    
    int n = wt.size();
    
    cout<<"The maximum value of items, thief can steal is "<<unboundedKnapack(
        n,w,val,wt);
}
