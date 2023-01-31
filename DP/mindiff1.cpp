#include<bits/stdc++.h>
using namespace std;
int subsetSumUtil(int ind, int target, vector<int>&arr,
vector<vector<int>> &dp){
    if(target == 0) return dp[ind][target] = true;
    
    if(ind==0){return dp[ind][target] = arr[0] == target;}
    
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }
    
    bool notTaken = subsetSumUtil(ind-1,target, arr,dp);
    
    bool taken = false;
    if(arr[ind] <= target) taken = subsetSumUtil(ind-1,target - arr[ind],
    arr,dp);
    
    return dp[ind][target] = notTaken || taken;
}
int minSSdiff(vector<int>&arr, int n){
    int sum = 0;
    
    for(int i:arr) sum+=i;
    
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    
    for(int i =0;i<=sum;i++){
        bool dummy = subsetSumUtil(n-1,i,arr,dp);
    }
    
    int mini = 1e9;
    for(int i =0;i<=sum;i++){
        if(dp[n-1][i] == true){
            int diff = abs(i -(sum-i));
            mini =  min(mini,diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {1,2,3,3,4};
    
    int n = arr.size();
    cout<<"Minimum difference is: "<<minSSdiff(arr,n);
}