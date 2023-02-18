#include<bits/stdc++.h>
using namespace std;

int stockProfit(vector<int> &arr, int fee){
    int n=arr.size();
    vector<int> cur(2,0), ahead(2,0);
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            if(buy==0){
                cur[buy] = max(0+ahead[0], -arr[ind] + 
                ahead[1]);
            }
            if(buy ==1){
                cur[buy] = max(0 + ahead[1], -fee + 
                arr[ind] + ahead[0]);
            }
        }
        ahead = cur;
    }
    return cur[0];
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<"The max profit that can be generated "<<stockProfit(
        prices,fee);
}