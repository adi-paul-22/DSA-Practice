#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int> arr, int ind, int buy, int n, int fee,
vector<vector<int>> &dp){
    if(ind>=n) return 0; // base case
    
    if(dp[ind][buy] != -1) return dp[ind][buy];
    
    int profit;
    
    if(buy==0){
        profit = max( 0 + getAns(arr,ind+1,0,n,fee,dp), -arr[ind] +
        getAns(arr,ind+1,1,n,fee,dp));
    }
    
    if(buy==1){
        profit = max( 0 + getAns(arr,ind+1,1,n,fee,dp) ,-fee + arr[ind] +
        getAns(arr,ind+1,0,n,fee,dp));
    }
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &arr, int fee){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    
    int ans = getAns(arr,0,0,n,fee,dp);
    return ans;
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<"The max profit that can be generated "<<stockProfit(
        prices,fee);
}