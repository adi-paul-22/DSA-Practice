#include<bits/stdc++.h>
using namespace std;

int minSSdiff(vector<int>&arr, int n){
    int sum = 0;
    
    for(int i:arr) sum+=i;
    
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0]<=sum) dp[0][sum] = true;
    
    for(int ind = 1;ind<n;ind++){
        for(int target = 1;target<=sum;target++){
            bool notTaken = dp[ind-1][target];
            
            bool taken = false;
            if(arr[ind]<= target)
                taken = dp[ind -1][target-arr[ind]];
                
            dp[ind][target] = taken || notTaken;
        }
    }
    
    int mini = 1e9;
    for(int i =0;i<=sum;i++){
        if(dp[n-1][i] == true){
            int diff = abs(i -(sum-i));
            mini =  min(mini,diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {1,2,3,3,4};
    
    int n = arr.size();
    cout<<"Minimum difference is: "<<minSSdiff(arr,n);
}