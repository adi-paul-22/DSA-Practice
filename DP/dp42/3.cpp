#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> cur(n+1,0),ahead(n+1,0);
    for(int ind = n-1;ind>=0;ind--){
        for(int prev_index = ind-1;prev_index>= -1;prev_index--){
            int notTake = 0 + ahead[prev_index +1];
            
            int take = 0;
            if(prev_index == -1 || arr[ind] >arr[prev_index]){
                take  = 1+ahead[ind + 1];
            }
            
            cur[prev_index +1] = max(take,notTake);
        }
        ahead = cur;
    }
    return cur[0];
}

int main(){
    int arr[]={10,9,2,5,3,7,101,18};
     int n = sizeof(arr)/sizeof(arr[0]);
     
     cout<<"The length of the longest increasing subsequence is "<<
     longestIncreasingSubsequence(arr,n);
    
    
}