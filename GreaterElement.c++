#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace

//   vector<long long> nextLargerElement(vector<long long> arr, int n){
//         // Your code here
        
//         stack<long long> stk;
//         vector<long long> vec;
        
//         vec.push_back(-1);
//         stk.push(arr[n-1]);
        
//         for(long long i = n-2; i >= 0; i--){
//             while(!stk.empty() && stk.top() <= arr[i]){
//                 stk.pop();
//             }
            
//             long long next = (stk.empty() ? -1 : stk.top());
//             vec.push_back(next);
//             stk.push(arr[i]);
//         }
//         reverse(vec.begin(), vec.end());
//         return vec;
//  }


 vector<long long> nextGreaterElements(vector<long long>& nums) {
        int n = nums.size();

        stack<int> stk;

        for(int i = n-2; i>=0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            stk.push(nums[i]);
        }

        vector<long long> result(n,0);

        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                result[i] = -1;
            }
            else{
                result[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return result;
    }

int main(){

  int n;
  cin>>n;
  vector<long long> nums(n,0);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }

  // vector<long long > ans = nextLargerElement(nums, n);
  vector<long long> ans = nextGreaterElements(nums);

  for(int i = 0; i< ans.size(); i++){
    cout<<ans[i]<<" ";
  }


  return 0;
}