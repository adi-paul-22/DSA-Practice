#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int countUtil(string s1,string s2,int ind1, int ind2,vector<vector<int>> 
&dp){
    if(ind2<0) return 1;  // string match
    
    if(ind1<0) return 0;  // exploration string over
    
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    
    if(s1[ind1] == s2[ind2]) {
        int matchCounted = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int noCount = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (matchCounted + noCount) % mod;
    }
    else 
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
}

int subsequenceCounting(string &t,string &s,int lt , int ls){
    vector<vector<int>> dp(lt+1, vector<int> (ls+1,-1));
    
    return countUtil(t,s,lt-1,ls-1,dp);
}

int main(){
    
    string s1 = "babgbag";
    string s2 = "bag";
    
    cout<<"The count of Distinct Subsequences is "
    <<subsequenceCounting(s1,s2,s1.size(),s2.size());
}