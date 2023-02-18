#include<bits/stdc++.h>
using namespace std;

int stockProfit(vector<int> &arr){
    int n=arr.size();
   vector<int> ahead(2,0), ahead1(2,0),cur(2,0);
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            if(buy==0){
                cur[buy] = max(0+ahead[0],-arr[ind] +
                ahead[1]);
            }
            
            if(buy == 1){
                cur[buy] = max(0+ahead[1] , arr[ind]+
                ahead1[0]);
            }
            
        }
        ahead1 = ahead;
        ahead = cur;
    }
    
    return ahead[0];
}

int main(){
    vector<int> prices = {4,9,0,4,10};
    cout<<"The max profit that can be generated is "<<
    stockProfit(prices);
}