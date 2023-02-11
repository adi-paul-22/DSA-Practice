#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int>& arr, int n , int t){
    vector<vector<long>> dp(n,vector<long>(t+1,0));
    // initialise base condition
    for(int i= 0;i<=t;i++){
        if(i%arr[0] == 0) dp[0][i] = 1;
    }
    
    for(int ind = 1;ind<n;ind++){
        for(int target = 0;target<=t;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target - arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    return dp[n-1][t];
}

int main(){
    vector<int> arr = {1,2,3};
    int target = 4;
    int n = arr.size();
    
    cout<<"The total no. of ways is "<<countWaysToMakeChange(
        arr,n,target);
}