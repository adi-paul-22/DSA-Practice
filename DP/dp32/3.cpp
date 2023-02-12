#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int subsequenceCounting(string s1,string s2,int n , int m){
    vector<int> prev(m+1,0);
    prev[0] = 1;
    for(int i=1;i<n+1;i++){
        for(int j =1;j<m+1;j++){
            if(s1[i-1] == s2[j-1])
                prev[j] = (prev[j-1] + prev[j])%mod;
            else 
                prev[j] = prev[j];
                
    }
}

return prev[m];
}

int main(){
    
    string s1 = "babgbag";
    string s2 = "bag";
    
    cout<<"The count of Distinct Subsequences is "
    <<subsequenceCounting(s1,s2,s1.size(),s2.size());
}