#include<bits/stdc++.h>
using namespace std;;

int maxProfit(vector<int>& prices,int n, int k){
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,
    vector<int>(k+1,0)));
    int profit;
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            for(int cap = 1;cap<=k;cap++){
                if(buy == 0 ) {
                    dp[ind][buy][cap]= max( 0 + dp[ind+1][0][cap],
                    -prices[ind] + dp[ind+1][1][cap]);
                }
                
                if(buy == 1){
                    dp[ind][buy][cap] = max(0 + dp[ind+1][1][cap],
                    prices[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    return dp[0][0][k];
}

int main(){
    
    vector<int> prices= {3,3,5,0,0,3,1,4};
    int n = prices.size();
    int k = 3;
    cout<<"The maximum proft that can be generated is "<<maxProfit(
        prices,n,k);
        
}