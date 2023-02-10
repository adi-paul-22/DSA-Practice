#include<bits/stdc++.h>
using namespace std;

int mod = (int) 1e9 + 7;
int findWays(vector<int> &num, int k){
    int n= num.size();
    
    vector<int> prev(k+1,0);
    
    if(num[0] == 0) prev[0] = 2; // case of pick and not pick
    
    else prev[0] = 1; // not pick
    
    if(num[0]!=0 && num[0]<=k) prev[num[0]] = 1; // case pick
    
    for(int ind= 1;ind<n;ind++){
        vector<int> cur(k+1,0);
        for(int target = 0; target<=k;target++){
            int notTaken = prev[target];
            
            int taken = 0;
            if(num[ind]<=target)
                taken = prev[target - num[ind]];
                
            cur[target] = (taken + notTaken) % mod;
        }
        prev = cur;
    }
    return prev[k];
}

int countPartitions(int d,vector<int> &arr){
    int  n = arr.size();
    int totSum = 0;
    for(int i =0;i<arr.size();i++) totSum += arr[i];
    
    //checking for edge cases
    
    if(totSum - d<0) return 0;
    if((totSum - d)%2 == 1) return 0;
    
    int s2 = (totSum-d)/2;
    
    return findWays(arr,s2);

}

int main(){
    vector<int> arr = {5,2,6,4};
    int d = 3;
    
    cout<<"No. of subsets found are "<<countPartitions(d,arr);
}
