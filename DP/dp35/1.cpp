#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &stocks){
    int maxProfit = 0;
    int mini = stocks[0];
    
    for(int i= 1;i<stocks.size();i++){
        int curProfit = stocks[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,stocks[i]);
    }
    
    return maxProfit;
}

int main(){
    vector<int> arr = {7,1,3,5,6,4};
    cout<<"Max Profit : "<<maximumProfit(arr);
}