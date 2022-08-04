class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.size() == 1) return nums[0] == target ? 1 : 0;
		int i = 0, sum = 0, lnth = INT_MAX, n =  nums.size();
		for(int j = 0; j < n; j++){
			sum += nums[j];
			while(sum >= target){
        lnth = min(lnth, j - i + 1);
				sum -= nums[i++];
			}
		}     
		return lnth == INT_MAX ? 0 : lnth;
  }
};