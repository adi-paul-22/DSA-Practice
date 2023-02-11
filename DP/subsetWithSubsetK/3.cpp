//count subsets with sum k
//space optimizaztion method 3

#include<bits/stdc++.h>

using namespace std;



int findways(vector<int> &num, int k){
    int n= num.size();
    
    vector<int> prev(k+1,0);
    prev[0] = 1;
    if(num[0]<=k) prev[num[0]] = 1;
    
    for(int ind = 1; ind<n;ind++){
        vector<int> cur(k+1,0);
        cur[0] = 1;
        for(int target = 1;target<=k;target++){
            int notTaken = prev[target];
            
            int taken = 0;
            if(num[ind]<=target)
            taken = prev[target - num[ind]];
            
            cur[target] = taken + notTaken;
        }
        prev = cur;
    }
    
    return prev[k];
}


int main(){
    vector<int> arr = {1,2,3,2};
    int k = 3;
    
    cout<<"No. of subsets are : "<<findways(arr,k);
}