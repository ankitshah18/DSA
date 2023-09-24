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