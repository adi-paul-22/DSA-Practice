#include<bits/stdc++.h>
using namespace std;
int unboundedKnapack(int n, int w, vector<int>& val, vector<int>& wt){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    // base condition
    for(int i = wt[0];i<=w;i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind = 1; ind<n;ind++){
        for(int cap = 0; cap<=w;cap++){
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind]<=cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(taken,notTaken);
        }
    }
    return dp[n-1][w];
}

int main(){
    vector<int> wt = {2,4,6};
    vector<int> val = {5,11,13};
    int w = 10;
    
    int n = wt.size();
    
    cout<<"The maximum value of items, thief can steal is "<<unboundedKnapack(
        n,w,val,wt);
}
