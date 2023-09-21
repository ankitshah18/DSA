#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace



bool isValidExp(char *s){
  
  stack<char> s1;

  for(int i=0; s[i]!='\0'; i++){
    char ch = s[i];
    if(ch == '('){
      s1.push(ch);
    }
    else if(ch == ')'){
      if(s1.empty() or s1.top()!='('){
        return false;
      }
      s1.pop();
    }
  }


  return s1.empty();
}

int main(){

  char s[100] = "((a+b) + (c-d+f)";
  if(isValidExp(s)){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }

  return 0;
}