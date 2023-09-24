#include <bits/stdc++.h> 
using namespace std; 

void insertAtBottom(stack<long long> &s, int x){
  //base case
  if (s.empty()){
    s.push(x);
    return;
  }
  //rec case
  int data = s.top();
  s.pop();
  insertAtBottom(s,x);
  s.push(data);
}


void reverseStackRec(stack<long long> &s){
  //base case
  if (s.empty()) return ;

  //otherwise
  //pop out the top element and insert it at the bottom of "reversed smaller stack"
  int x = s.top();
  s.pop();
  //rec reverse the smaller stack
  reverseStackRec(s);
  insertAtBottom(s,x);
}

int main(){

  long long int n;
  cin>>n;

  stack<long long > s;

  for(int i = 0; i < n; i++){
      int m;
      cin>>m;
      s.push(m);
  }
  

  reverseStackRec(s);

   while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }

  return 0;
}