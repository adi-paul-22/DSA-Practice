#include<bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target , vector<int> &arr, vector<vector<int>> &dp){
    if(target== 0) return dp[ind][target];
    
    if(ind==0) return dp[ind][target] = arr[0] == target;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<= target) 
        taken = subsetSumUtil(ind-1,target - arr[ind],arr,dp);
        
    return dp[ind][target] = taken || notTaken;
}

int minSubsetSumDifference(vector<int> &arr, int n){
    int sum = 0;
    
    for(int i=0;i<n;i++) sum+=arr[i];
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    
    for(int i=0;i<n;i++) dp[i][0] = true;
    
    if(arr[0]<=sum) dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n;ind++){
        for(int target = 1; target <=sum;target++){
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
            if(arr[ind]<= target) 
                taken = dp[ind-1][target-arr[ind]];
                
            dp[ind][target] = taken || notTaken;
        }
    }   
        
    int mini = 1e9;
    for(int i=0;i<sum;i++){
        if(dp[n-1][i] == true){
            int diff = abs(i - (sum-i));
            mini = min(mini,diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {8,6,5};
    int n = arr.size();
    
    cout<<"Minimum differnce is : "<<minSubsetSumDifference(arr,n);
}