#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int>& price, int n){
   vector<vector<int>> dp(n,vector<int> (n+1,0));
   
   for(int i =0;i<=n;i++){
       dp[0][i] = i*price[0];
   }
   
   for(int ind =1;ind<n;ind++){
       for(int length = 0;length<=n;length++){
           int notTaken = 0 + dp[ind-1][length];
           
           int taken = INT_MIN;
           int rodLength  = ind +1;
           if(rodLength<=length)
            taken = price[ind] + dp[ind][length - rodLength];
            
            dp[ind][length] = max(notTaken,taken);
       }
   }
   return dp[n-1][n];
}

int main(){
    vector<int> price = {2,5,7,8,10};
    
    int n = price.size();
    
    cout<<"Maximum price is "<<cutRod(price,n);
}