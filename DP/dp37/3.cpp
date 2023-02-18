#include<bits/stdc++.h>
using namespace std;;

int maxProfit(vector<int>& prices,int n){
    vector<vector<int>> ahead(2,vector<int>(3,0));
    vector<vector<int>> cur(2,vector<int>(3,0));
for(int ind = n-1;ind>=0;ind--){
    for(int buy = 0;buy<=1;buy++){
        for(int cap = 1;cap<=2;cap++){
            if( buy == 0 ){
                cur[buy][cap] = max(0+ahead[0][cap],
                -prices[ind] + ahead[1][cap]);
            }
            if(buy == 1){
                cur[buy][cap] = max(0 + ahead[1][cap],
                prices[ind] + ahead[0][cap-1]); // cap - 1 because 
                // using existing transaction value from the previous one
            }
        }
        ahead = cur;
    }
}
return ahead[0][2];
}

int main(){
    
    vector<int> prices= {3,3,5,0,0,3,1,4};
    int n = prices.size();
    
    cout<<"The maximum proft that can be generated is "<<maxProfit(
        prices,n);
        
}