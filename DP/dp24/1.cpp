#include<bits/stdc++.h>
using namespace std;
int cutRodUtil(vector<int>& price, int ind, int n , vector<vector<int>> &dp){
    if(ind == 0) return n*price[0];
    
    if(dp[ind][n] != - 1) return dp[ind][n];
    
    int notTaken = 0 + cutRodUtil(price,ind-1,n,dp);
    int taken = INT_MIN;
    
    int rodLength = ind + 1;
    if(rodLength<=n)
        taken = price[ind] + cutRodUtil(price,ind,n - rodLength,dp);
    
    return dp[ind][n] = max(notTaken,taken);
}
int cutRod(vector<int>& price, int n){
   vector<vector<int>> dp(n,vector<int> (n+1,-1));
   return cutRodUtil(price,n-1,n,dp);
}

int main(){
    vector<int> price = {2,5,7,8,10};
    
    int n = price.size();
    
    cout<<"Maximum price is "<<cutRod(price,n);
}