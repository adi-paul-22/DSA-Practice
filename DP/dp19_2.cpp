#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val,int n,int w){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    // base condition
    for(int i=wt[0];i<=w;i++) dp[0][i] = val[0];
    
    for(int ind = 1;ind<n;ind++){
        for(int cap = 0;cap<=w;cap++){
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap-wt[ind]];
                
            dp[ind][cap] = max(taken,notTaken);
            
        }
    }
    return dp[n-1][w];
}

int main(){
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    
    int w = 5;
    int n = wt.size();
    
    cout<<"The maximum value of items the thief can steal is "<<
    knapsack(wt,val,n,w);
}