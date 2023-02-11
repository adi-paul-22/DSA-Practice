#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int>& arr, int n , int t){
    vector<long> prev(t+1,0);
    // initialise base condition
    for(int i= 0;i<=t;i++){
        if(i%arr[0] == 0) prev[i] = 1;
    }
    
    for(int ind = 1;ind<n;ind++){
        vector<long> cur(t+1,0);
        for(int target = 0;target<=t;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = cur[target - arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    return prev[t];
}

int main(){
    vector<int> arr = {1,2,3};
    int target = 4;
    int n = arr.size();
    
    cout<<"The total no. of ways is "<<countWaysToMakeChange(
        arr,n,target);
}