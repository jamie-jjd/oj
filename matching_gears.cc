#include <algorithm>
#include <iostream>

bool IsMatched
(
  std::string::iterator it_0,
  std::string::iterator end_0,
  std::string::iterator it_1
)
{
  return std::equal
  (
    it_0, end_0, it_1,
    [] (char const& lhs, char const& rhs) { return (lhs != '2' || rhs != '2'); }
  );
}

int main ()
{
  std::string gear_0;
  std::string gear_1;
  while (std::cin >> gear_0 >> gear_1)
  {
    auto& long_gear {(gear_0.size() < gear_1.size()) ? gear_1 : gear_0};
    auto& short_gear {(gear_0.size() < gear_1.size()) ? gear_0 : gear_1};
    auto length {long_gear.size() + short_gear.size()};
    for (uint64_t i {}; i != (long_gear.size() - short_gear.size() + 1); ++i)
    {
      if (IsMatched(std::begin(short_gear), std::end(short_gear), std::next(std::begin(long_gear), i)))
      {
        length = long_gear.size();
        break;
      }
    }
    if (length != long_gear.size())
    {
      for (uint64_t i {1}; i != short_gear.size(); ++i)
      {
        if
        (
          IsMatched(std::next(std::begin(short_gear), i), std::end(short_gear), std::begin(long_gear))
          || IsMatched(std::prev(std::end(long_gear), short_gear.size() - i), std::end(long_gear), std::begin(short_gear))
        )
        {
          length = long_gear.size() + i;
          break;
        }
      }
    }
    std::cout << length << "\n";
  }
  return 0;
}
