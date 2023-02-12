
#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & s1, int i){
  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (s1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & s1, string &s2) {
  int n = s1.size();
  int m = s2.size();
  vector<vector <bool >>dp(n + 1,vector<bool>(m, false));
  dp[0][0] = true;
  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }  // for any length of j is left , the string is not there so false
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(s1, i);
  }
  // if the second string is empty then we check all * in s1

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (s1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];

}
int main(){
    
    string s1 = "ab*cd";
    string s2 = "abcecd";
    
    if(wildcardMatching(s1,s2)){
        cout<<"s1 and s2 match";
        
    }
    else cout<<"s1 and s2 do not match";
}