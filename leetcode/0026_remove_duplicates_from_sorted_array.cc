class Solution
{
public:
  int removeDuplicates (vector<int>& nums)
  {
    return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
  }
};
