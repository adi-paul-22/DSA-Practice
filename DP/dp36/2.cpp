#include<bits/stdc++.h>
using namespace std;
long getMax(long *arr,int n){
    vector<vector<long>> dp(n+1, vector<long> (2,-1));
    
    // base condition
    dp[n][0] = dp[n][1] =0;
    
    long profit ;
    
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            if(buy==0) // we can buy the stock
                profit = max(0+dp[ind+1][0], -arr[ind] + dp[ind+1][1]); // 1 kyuki if we are holding
            if(buy == 1) // we can sell the stock
                profit = max(0+dp[ind+1][1], arr[ind] + dp[ind+1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}

int main(){
int n =6;
  long Arr[n] = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<getMax(Arr, n);
}