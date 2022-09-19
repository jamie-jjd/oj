class Solution
{
public:
  int searchInsert (std::vector<int>& nums, int target)
  {
    return std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
  }
};
