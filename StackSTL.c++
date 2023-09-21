#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace


void transfer(stack<int> &s1, stack<int> &s2, int n){
  for(int i=0; i<n; i++){
    s2.push(s1.top());
    s1.pop();
  }
}

void reverseStack(stack<int> &s1){
  //helper stack
  stack<int> s2;
  int n = s1.size();
  for(int i=0; i<n; i++){
    //pick the element at top & insert it at the bottom
    int x = s1.top();
    s1.pop();

    //transfer n-i-1 elements from stack s1 into s2
    transfer(s1, s2, n-i-1);
    //insert the element x in s1 
    s1.push(x);

    //transfer n-i-1 elements from s1 to s1
    transfer(s2,s1,n-i-1);
  }
}

void insertAtBottom(stack<int> &s, int x){
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

void reverseStackRec(stack<int> &s){
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

  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }

  

  reverseStack(s);

  

  return 0;
}