#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace

//Implementation of stack data structure using vector

template<typename T>

class Stack{

  private:
    vector<T> v;
  public:
    void push(T data){
      v.push_back(data);
    }

    bool empty(){
      return v.size() == 0;
    }

    void pop(){
      if(!v.empty()){
        v.pop_back();
      }
    }

    T top(){
      return v[v.size()-1];
    }

};

int main(){

   Stack<char> s;
   
   for(int i=65; i<=70; i++){
    s.push(i);
   }
   //Try to print the content of the stack by popping each element
   while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
   }
  
  //  cout<<endl;

  //  Stack <int> s1;
  //   for(int i=65; i<=70; i++){
  //   s1.push(i+2);
  //  }

  //  while(!s1.empty()){
  //   cout<<s1.top()<<endl;
  //   s1.pop();
  //  }


  return 0;
}