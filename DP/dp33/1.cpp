#include<bits/stdc++.h>
using namespace std;

int editDistanceUtil(string &s1,string& s2, int i, int j, vector<vector<
int>> &dp){
    if(i<0) return j+1;
    
    if(j<0) return i+1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i-1] == s2[j-1])
        return dp[i][j] = 0 + editDistanceUtil(s1,s2,i-1,j-1,dp);
    else return dp[i][j] = 1 + min(editDistanceUtil(s1,s2,i-1,j,dp),
    min(editDistanceUtil(s1,s2,i,j-1,dp),editDistanceUtil(s1,s2,i-1,j-1,dp)));
    
}

int editDistance(string& s1, string &s2){
    
    int n= s1.size();
    int m  = s2.size();
    
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return editDistanceUtil(s1,s2,n-1,m-1,dp);
}

int main(){
    
    string s1 ="horse";
    string s2 = "ros";
    
    cout<<"The minimum no. of operations : "<<editDistance(s1,s2);
}