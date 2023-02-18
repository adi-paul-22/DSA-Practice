#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int> arr, int ind, int buy, int n,
vector<vector<int>> &dp){
    if(ind>=n) return 0; // base case
    
    if(dp[ind][buy] != -1) return dp[ind][buy];
    
    int profit;
    
    if(buy==0){
        profit = max( 0 + getAns(arr,ind+1,0,n,dp), -arr[ind] +
        getAns(arr,ind+1,1,n,dp));
    }
    
    if(buy==1){
        profit = max( 0 + getAns(arr,ind+1,1,n,dp) ,arr[ind] +
        getAns(arr,ind+2,0,n,dp));
    }
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    
    int ans = getAns(arr,0,0,n,dp);
    return ans;
}

int main(){
    vector<int> prices = {4,9,0,4,10};
    cout<<"The max profit that can be generated is "<<
    stockProfit(prices);
}