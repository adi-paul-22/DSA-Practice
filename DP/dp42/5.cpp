#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n,1);
    vector<int> hash(n,1);
    for(int i =0;i<=n-1;i++){ hash[i] = i;
        // initialising with current index
        for(int prev = 0;prev <=i-1;prev++){
            if(arr[prev]<arr[i] && 1+dp[prev] >  dp[i]){
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
    }
    
    int ans = -1;
    int lastIndex = -1;
    for(int i=0;i<n;i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the 
             // initialisation value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    cout<<"The subsequence elements are ";
    
    for(int i =0;i<temp.size();i++){
        cout<<temp[i] <<" ";
    }
    cout<<endl;
    return ans;
}

int main(){
    int arr[]={10,9,2,5,3,7,101,18};
     int n = sizeof(arr)/sizeof(arr[0]);
     
     n=longestIncreasingSubsequence(arr,n);
    
    
}