#include<bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind,int target , vector<int> &arr,
vector<vector<int>> &dp){
    if(target == 0 ) return 0;
    
    if(ind == 0) return arr[0] == target;
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target) taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);

    
    return dp[ind][taken] = notTaken || taken;
}

bool canPartition(int n, vector<int> &arr){
    int sum = 0;
    for(int i : arr){
        sum+=i;
    }
    if(sum%2 == 1) return false;
    else{ sum/=2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return subsetSumUtil(n-1,sum,arr,dp);
    }
}

int main(){
    vector<int> arr = {2,3,4,3,4,5};
    int n = arr.size();
    
    if(canPartition(n,arr)){
        cout<<"Two subsets";
    }
    else cout<<"not two subsets";
    }
