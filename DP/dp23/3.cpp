#include<bits/stdc++.h>
using namespace std;
int unboundedKnapack(int n, int w, vector<int>& val, vector<int>& wt){
    vector<int> cur(w+1,0);
    // base condition
    for(int i = wt[0];i<=w;i++){
        cur[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind = 1; ind<n;ind++){
        for(int cap = 0; cap<=w;cap++){
            int notTaken = 0 + cur[cap];
            
            int taken = INT_MIN;
            if(wt[ind]<=cap)
                taken = val[ind] + cur[cap - wt[ind]];
                
            cur[cap] = max(taken,notTaken);
        }
    }
    return cur[w];
}

int main(){
    vector<int> wt = {2,4,6};
    vector<int> val = {5,11,13};
    int w = 10;
    
    int n = wt.size();
    
    cout<<"The maximum value of items, thief can steal is "<<unboundedKnapack(
        n,w,val,wt);
}
