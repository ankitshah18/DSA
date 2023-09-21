#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace

int main(){
  list<int> l;

  //init
  list<int> l1{1,2,3,4,10,8,5};

  //different datatype
  list<string> l2{"apple","guava","mango","banana"};
  l2.push_back("pineapple");

  //sort l2.sort();
  l2.sort();

  //reverse
  l2.reverse();

  //pop_front
  cout<<l2.front()<<endl;
  l2.pop_front();

  //add to the front of the list
  l2.push_front("kiwi");
  cout<<l2.back()<<endl;
  l2.pop_back();


  l2.push_back("orange");
  l2.push_back("lemon");
  l2.push_back("guava");

  //Iterate over the list and print the data

  for(auto it=l2.begin(); it!=l2.end(); it++){
    cout<<(*it)<<" -> ";
  }

  cout<<endl;
  // for(string s : l2){
  //   cout<<s<<"->";
  // }

  //remove a fruit
  // string f;
  // cin>>f;
  // l2.remove(f);

  //  for(auto it=l2.begin(); it!=l2.end(); it++){
  //   cout<<(*it)<<" -> ";
  // }

  //erase one or more elements
  auto it = l2.begin();
  it++;
  it++;
  l2.erase(it);
  return 0;

   for(auto it=l2.begin(); it!=l2.end(); it++){
    cout<<(*it)<<" -> ";
  }
}