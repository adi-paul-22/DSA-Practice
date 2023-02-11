
#include <bits/stdc++.h>

using namespace std;
bool canPartition(int n, vector<int> &arr){
    int sum=0;
    for(int i : arr) sum+=i;
    
    if(sum%2==1) return false;
    
    else{
        int k = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        
        for(int ind = 0;ind<n;ind++){
            dp[ind][0] = true;
        }
        
        if(arr[0]<=k) dp[0][arr[0]] = true;
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=k;target++){
                bool notTaken = dp[ind-1][target];
                
                bool taken = false;
                if(arr[ind]<=target) 
                taken = dp[ind-1][target - arr[ind]];
                
                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n-1][k];
    }
}
int main() {

  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(n,arr))
    cout<<"two equal subsets";
  else 
    cout<<" cannot be partitioned into two subsets";
}
