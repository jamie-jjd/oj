class Solution
{
public:
  bool containsNearbyAlmostDuplicate (vector<int>& nums, int k, int t)
  {
    std::multiset<int> k_sorted_nums;
    for (size_t i {}; i != std::size(nums); ++i)
    {
      k_sorted_nums.insert(nums[i]);
      auto it {k_sorted_nums.find(nums[i])};
      if (k_sorted_nums.count(nums[i]) > 1)
      {
        return true;
      }
      if
      (
        *it != *std::begin(k_sorted_nums) &&
        (*it <= std::numeric_limits<int>::min() + t || *it - t <= *std::prev(it))
      )
      {
        return true;
      }
      if
      (
        *it != *std::rbegin(k_sorted_nums) &&
        (*it >= std::numeric_limits<int>::max() - t || *it + t >= *std::next(it))
      )
      {
        return true;
      }
      if (i >= k) { k_sorted_nums.erase(k_sorted_nums.find(nums[i - k])); }
    }
    return false;
  }
};
