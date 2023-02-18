#include<bits/stdc++.h>
using namespace std;

int stockProfit(vector<int> &arr, int fee){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            if(buy==0){
                dp[ind][buy] = max(0+dp[ind+1][0], -arr[ind] + 
                dp[ind+1][1]);
            }
            if(buy ==1){
                dp[ind][buy] = max(0 + dp[ind+1][1], -fee + 
                arr[ind] + dp[ind+1][0]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<"The max profit that can be generated "<<stockProfit(
        prices,fee);
}