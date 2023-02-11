#include<bits/stdc++.h>
using namespace std;

int minimumElements(vector<int>& arr,int t){
    int n = arr.size();
    
    vector<int> prev(t+1,0);
    
    for(int i= 0;i<=t;i++){
        if(i%arr[0] == 0) prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1;ind<n;ind++){
        vector<int> cur(t+1,0);
        for(int target = 0;target<=t;target++){
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target) 
                take = 1+cur[target - arr[ind]];
            
            cur[target] = min(notTake,take);
        }
        prev = cur;
    }
    int ans = prev[t];
    if(ans >= 1e9) return -1;
    
    return ans;
}
int main(){
    vector<int> arr = {1,2,3};
    int t = 7;
    
    cout<<"Minimum no. of coins is "<<minimumElements(arr,t);
}