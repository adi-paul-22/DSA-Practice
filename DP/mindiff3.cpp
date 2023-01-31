#include<bits/stdc++.h>
using namespace std;

int minsubsetdiff(vector<int> &arr, int n){
    int sum=0;
    for(int i : arr) sum+=i;
    
    vector<bool> prev(sum+1,false);
    prev[0] = true;
    
    if(arr[0]<=sum){
        prev[arr[0]] = true;
    }
    
    for(int ind = 1;ind<n;ind++){
        vector<bool> cur(sum+1,false);
        
        cur[0] = true;
        for(int target = 1;target<=sum;target++){
            bool notTaken = prev[target];
            
            bool taken = false;
            if(arr[ind]<=target)
            taken = prev[target - arr[ind]];
            
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    
    int mini = 1e9;
    for(int i=0;i<=sum;i++){
        if(prev[i] == true){
            int diff = abs(i - (sum-i));
            mini = min(mini,diff);
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    cout<<"Minimum difference : "<<minsubsetdiff(arr,n);
    
}