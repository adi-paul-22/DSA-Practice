#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val,int n,int w){
    vector<int> prev(w+1,0);
    // base condition
    for(int i=wt[0];i<=w;i++) prev[i] = val[0];
    
    for(int ind = 1;ind<n;ind++){
        for(int cap = w;cap>=0;cap--){
            int notTaken = 0 + prev[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap-wt[ind]];
                
            prev[cap] = max(taken,notTaken);
            
        }
    }
    return prev[w];
}

int main(){
    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    
    int w = 5;
    int n = wt.size();
    
    cout<<"The maximum value of items the thief can steal is "<<
    knapsack(wt,val,n,w);
}