#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int ind1 = 1;ind1<=n;ind1++){
        for(int ind2 = 1;ind2<=m;ind2++){
            if(s1[ind1-1] == s2[ind2-1]) 
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev = cur;
    }
    return prev[m];
}
int canYouMake(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int k = lcs(s1,s2);
    return n-k + m - k;
}

int main(){
    string s1 = "abcd";
    string s2 = "anc";
    cout<<"Minimum operations to convert str1 to str2 : "<<canYouMake(s1,s2);
    
}