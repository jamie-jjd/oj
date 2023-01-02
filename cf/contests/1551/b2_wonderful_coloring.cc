#include <iostream>
#include <map>
#include <vector>

int main ()
{
  int64_t t {};
  std::cin >> t;
  while (t--)
  {
    int64_t n, k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n);
    std::map<int64_t, int64_t> value_count;
    for (auto& a_i : a)
    {
      std::cin >> a_i;
      ++value_count[a_i];
    }
    std::map<int64_t, std::vector<int64_t>> count_value;
    for (auto [value, count] : value_count)
    {
      if (k < count) { count = k; }
      count_value[count].push_back(value);
    }
    std::map<int64_t, std::vector<int64_t>> value_color;
    std::vector<std::pair<int64_t, int64_t>> temp_value_color;
    int64_t color_offset {1};
    while (!count_value.empty())
    {
      auto major_count {std::get<0>(*count_value.rbegin())};
      auto& major_values {std::get<1>(*count_value.rbegin())};
      auto major_value {major_values.back()}; major_values.pop_back();
      if (major_values.empty()) { count_value.erase(major_count); }
      auto minor_count {k - major_count};
      while (minor_count && !count_value.empty())
      {
        auto count {std::get<0>(*count_value.begin())};
        auto& values {std::get<1>(*count_value.begin())};
        auto value {values.back()}; values.pop_back();
        if (values.empty()) { count_value.erase(count); }
        if (minor_count < count)
        {
          count_value[count - minor_count].push_back(value);
          count = minor_count;
        }
        minor_count -= count;
        while (count--)
        {
          temp_value_color.emplace_back(value, color_offset);
          color_offset = (color_offset % k) + 1;
        }
      }
      if (minor_count == 0)
      {
        for (auto [value, color] : temp_value_color)
        {
          value_color[value].push_back(color);
        }
        temp_value_color.clear();
        for (auto color {color_offset}; major_count; color = (color % k) + 1, --major_count)
        {
          value_color[major_value].push_back(color);
        }
      }
    }
    for (auto a_i : a)
    {
      auto it {value_color.find(a_i)};
      if (it != value_color.end())
      {
        auto& colors {std::get<1>(*it)};
        std::cout << colors.back() << " "; colors.pop_back();
        if (colors.empty()) { value_color.erase(a_i); }
      }
      else { std::cout << "0 "; }
    }
    std::cout << "\n";
  }
  return 0;
}