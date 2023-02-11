#include<bits/stdc++.h>
using namespace std;
int mod = (int)1e9+ 7;
int findWays(vector<int>&num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        
    }
    if(num[0] == 0) dp[0][0] = 2; // case of pick and not pick
    else dp[0][0] = 1;  // case of not pick
    
    if(num[0] != 0 && num[0]<=tar ) dp[0][num[0]] = 1;// case pick
    
    for(int ind=1;ind<n;ind++){
        for(int target = 0; target<=tar;target++){
            int notTaken = dp[ind-1][target];
            int taken = 0;
            if(num[ind]<=target)
                taken  =dp[ind-1][target - num[ind]];
                
            dp[ind][target] = (taken+ notTaken) %mod;
        }
    }
    return dp[n-1][tar];
    
}

int targetSum(int n , int target, vector<int> &arr){
    int sum = 0;
    for(int i:arr) sum+=i;
    // checking for edge cases
    if(sum-target<0) return 0;
    if((sum-target)%2 == 1) return 0;
    
    int s2 = (sum - target)/2;
    return findWays(arr,s2);
}

int main(){
    vector<int> arr = {1,2,3,1};
    int  target = 3;
    
    int n = arr.size();
    cout<<"The number of ways found is "<<
    targetSum(n,target,arr);
}