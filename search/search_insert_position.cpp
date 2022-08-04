class Solution {
public:

  int searchInsert(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1, mid = 0;
    while(i < j){
      mid = i + (j - i)/2;
      if(nums[mid] == target) return mid;
      if(nums[mid] < target) i = mid + 1;
      else j = mid - 1;
    }
    return mid;
  }

};