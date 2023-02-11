#include<bits/stdc++.h>
using namespace std;

int minimumElements(vector<int>& arr,int t){
    int n = arr.size();
    
    vector<vector<int>> dp(n,vector<int>(t+1,0));
    
    for(int i= 0;i<=t;i++){
        if(i%arr[0] == 0) dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1;ind<n;ind++){
        for(int target = 0;target<=t;target++){
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target) 
                take = 1+dp[ind][target - arr[ind]];
            
            dp[ind][target] = min(notTake,take);
        }
    }
    int ans = dp[n-1][t];
    if(ans >= 1e9) return -1;
    
    return ans;
}
int main(){
    vector<int> arr = {1,2,3};
    int t = 7;
    
    cout<<"Minimum no. of coins is "<<minimumElements(arr,t);
}