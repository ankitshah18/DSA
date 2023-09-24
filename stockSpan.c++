#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace


vector<long long> stockSpan(vector<long long> &prices){

  int n = prices.size();

  stack<int> s; //indices of the day
  s.push(0);
  vector<long long> span(n);

  span[0] = 1;

  //loop for rest of the days -> O(N) -> Push and Pop each element only once
  for(int i=1; i<n; i++){
    
    int currentPrice = prices[i];
    //topmost element which is higher than the current price
    while(!s.empty() and prices[s.top()]<=currentPrice){
      s.pop();
    }

    if(!s.empty()){
      int prev_highest = s.top();
      span[i] = i - prev_highest;
    }
    else{
      span[i] = i+1;
    }
    
    //push this element into the stack
    s.push(i);

  }
  return span;


}


int main(){
  int n;
  cin>>n;

  vector<long long> prices(n,0);
  for(int i = 0; i < n; i++){
    cin>>prices[i];
  }
  
  vector<long long> res = stockSpan(prices);

  for(int i = 0; i<res.size(); i++){
    cout<<res[i]<<" ";
  }
  cout<<"END";

  return 0;
}