class Solution
{
public:
  int search (std::vector<int>& nums, int target)
  {
    auto first {nums.begin()};
    auto last {nums.end()};
    while (std::next(first) != last)
    {
      auto middle {std::next(first, std::distance(first, last) / 2)};
      if (*middle < *first)
      {
        last = middle;
      }
      else
      {
        first = middle;
      }
    }
    auto target_it {std::lower_bound(nums.begin(), last, target)};
    if (target_it != nums.end() && *target_it == target)
    {
      return std::distance(nums.begin(), target_it);
    }
    target_it = std::lower_bound(last, nums.end(), target);
    if (target_it != nums.end() && *target_it == target)
    {
      return std::distance(nums.begin(), target_it);
    }
    return -1;
  }
};
