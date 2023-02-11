#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0);
    
    int ans = 0;
    
    for(int i =1;i<=n;i++){
        vector<int> cur(m+1,0);
        for(int j = 1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                cur[j] =  val;
                ans = max(ans,val);
            }
            
        }
        prev = cur;
    }
    return ans;
}

int main(){
    string s1 = "abcjklp";
    string s2 = "acjkp";
    
    cout<<"Length of LC substring is "<<lcs(s1,s2);
}