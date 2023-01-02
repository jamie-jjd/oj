class Solution
{
public:
  std::vector<int> searchRange (std::vector<int>& nums, int target)
  {
    std::vector<int> range(2, -1);
    auto lower_bound {std::lower_bound(nums.begin(), nums.end(), target)};
    auto upper_bound {std::upper_bound(nums.begin(), nums.end(), target)};
    if (lower_bound != upper_bound)
    {
      range[0] = std::distance(nums.begin(), lower_bound);
      range[1] = std::distance(nums.begin(), upper_bound) - 1;
    }
    return range;
  }
};
