#include<bits/stdc++.h>
using namespace std;;

int getAns(vector<int>& arr , int n,int ind , int buy , int cap
,vector<vector<vector<int>>> &dp){
    if(ind == n || cap ==0) return 0; // base case;
    
    if(dp[ind][buy][cap] != -1){
        return dp[ind][buy][cap];
        
    }
    
    int profit;
    
    if(buy ==0){
        profit = max(0+getAns(arr,n,ind+1,0,cap,dp), -arr[ind] +
        getAns(arr,n,ind+1,1,cap,dp));
    }
    
    if(buy == 1){
        profit = max(0+getAns(arr,n,ind+1,1,cap,dp), arr[ind] +
        getAns(arr,n,ind+1,0,cap-1,dp));
    }
    
    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector <int>& prices,int n, int k){
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,
    vector<int>(k+1,-1)));
    
    return getAns(prices,n,0,0,k,dp);
}

int main(){
    
    vector<int> prices= {3,3,5,0,0,3,1,4};
    int n = prices.size();
    int k = 3;
    cout<<"The maximum proft that can be generated is "<<maxProfit(
        prices,n,k);
        
}