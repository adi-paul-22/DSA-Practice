#include<bits/stdc++.h>
using namespace std;
 
int minimumElementsUtil(vector<int>& arr,int ind, int t,vector<vector<int>> &dp){
    if(ind == 0) {
        if(t%arr[0] == 0) return t/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][t]!= -1) return dp[ind][t];
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,t,dp);
    
    int taken = 1e9;
    if(arr[ind]<=t)
        taken = 1+ minimumElementsUtil(arr,ind,t-arr[ind],dp);
    
    return dp[ind][t] = min(taken,notTaken);
}

int minimumElements(vector<int>& arr,int t){
    int n = arr.size();
    
    vector<vector<int>> dp(n,vector<int>(t+1,-1));
    int ans = minimumElementsUtil(arr,n-1,t,dp);
    
    if(ans>=1e9) return -1;
    return ans;
}
int main(){
    vector<int> arr = {1,2,3};
    int t = 7;
    
    cout<<"Minimum no. of coins is "<<minimumElements(arr,t);
}