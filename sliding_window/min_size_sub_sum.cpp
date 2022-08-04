class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.size() == 1) return nums[0] != target ? 0 : 1;
    int lnth = INT_MAX, n = nums.size(); 
    for(int i = 0; i < n; i++){
      int sum = 0, j, flag = 0;
      for(j = i; j < n; j++){
        sum += nums[j];
        if(sum >= target){
          flag = 1;
          break;
        }
      }
      if(flag == 1){
        lnth = min(lnth, j - i + 1);
        if(lnth == 1) return lnth;
      }else break;
    }      
    return lnth == INT_MAX ? 0 : lnth; 
  }
};