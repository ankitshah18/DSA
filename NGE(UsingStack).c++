#include <bits/stdc++.h> 
using namespace std; 

// Function to print Next Greater Element for each element of the array
// void nextGreater(int arr[], int n) 
// { 
//     stack<int> s;
//     s.push(arr[0]);
//     for(int i=1;i<n;i++){
//         int current_element = arr[i];
//         if(s.empty()){
//             s.push(arr[i]);
//             continue;
//         }
//         while(!s.empty() and s.top()<arr[i]){
//             cout<<s.top()<<","<<arr[i]<<endl;
//             s.pop();
//         }
//         s.push(arr[i]);
//     }
//     while(!s.empty()){
//         cout<<s.top()<<","<<-1<<endl;
//         s.pop();
//     }

// } 

void nextGreater(int arr[], int n) {
  stack<int> stk;
  vector<int> vec;
        
  vec.push_back(-1);
  stk.push(arr[n-1]);
        
        for(int i = n-2; i >= 0; i--){
          while(!stk.empty() && stk.top() <= arr[i]){
            stk.pop();
          }

          int next = (stk.empty() ? -1 : stk.top());
          vec.push_back(next);
          stk.push(arr[i]);
        }
    reverse(vec.begin(), vec.end());
    for(int i = 0; i<n; i++){
      cout<<arr[i]<<","<<vec[i];
    }

}



// The Main Function
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n); 
    }
	
	return 0; 
} 

