#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int>& price, int n){
   vector<int> cur(n+1,0);
   
   for(int i =0;i<=n;i++){
       cur[i] = i*price[0];
   }
   
   for(int ind =1;ind<n;ind++){
       for(int length = 0;length<=n;length++){
           int notTaken = 0 + cur[length];
           
           int taken = INT_MIN;
           int rodLength  = ind +1;
           if(rodLength<=length)
            taken = price[ind] + cur[length - rodLength];
            
            cur[length] = max(notTaken,taken);
       }
   }
   return cur[n];
}

int main(){
    vector<int> price = {2,5,7,8,10};
    
    int n = price.size();
    
    cout<<"Maximum price is "<<cutRod(price,n);
}