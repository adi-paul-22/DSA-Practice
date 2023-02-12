
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
  vector<bool> prev(m+1, false), cur(m+1,false);
  prev[0] = true;
 
  for (int i = 1; i <= n; i++) {
      cur[0] = isAllStars(s1, i);
    for (int j = 1; j <= m; j++) {

      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (s1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];

}
int main(){
    
    string s1 = "ab*cd";
    string s2 = "abcecd";
    
    if(wildcardMatching(s1,s2)){
        cout<<"s1 and s2 match";
        
    }
    else cout<<"s1 and s2 do not match";
}