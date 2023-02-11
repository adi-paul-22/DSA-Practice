#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChangeUtil(vector<int> &arr, int ind, int t, 
vector<vector<long>> &dp){
    if(ind==0) return(t%arr[0] == 0);
    
    if(dp[ind][t] != -1) return dp[ind][t];
    
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,t,dp);
    
    long taken = 0;
    if(arr[ind] <= t) 
        taken = countWaysToMakeChangeUtil(arr,ind,t - arr[ind],dp);
        
    return dp[ind][t] = taken +  notTaken;
}

long countWaysToMakeChange(vector<int>& arr, int n , int t){
    vector<vector<long>> dp(n,vector<long>(t+1,-1));
    return countWaysToMakeChangeUtil(arr,n-1,t,dp);
}

int main(){
    vector<int> arr = {1,2,3};
    int target = 4;
    int n = arr.size();
    
    cout<<"The total no. of ways is "<<countWaysToMakeChange(
        arr,n,target);
}