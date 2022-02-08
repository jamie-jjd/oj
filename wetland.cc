#include <deque>
#include <iostream>
#include <utility>
#include <vector>

int main ()
{
  uint64_t t {};
  std::string line;
  std::getline(std::cin, line);
  t = std::stoull(line);
  std::getline(std::cin, line);
  while (t--)
  {
    std::vector<std::string> site;
    while (std::getline(std::cin, line) && !line.empty())
    {
      if (line[0] == 'L' || line[0] == 'W')
      {
        site.push_back(line);
      }
      else if (!line.empty())
      {
        auto offset_space {line.find(" ")};
        auto r {std::stoull(line.substr(0, offset_space)) - 1};
        auto c {std::stoull(line.substr(offset_space + 1)) - 1};
        std::vector<std::vector<bool>> is_discovered(site.size(), std::vector<bool>(site[0].size()));
        std::deque<std::pair<uint64_t, uint64_t>> queue;
        uint64_t area {};
        if (site[r][c] == 'W')
        {
          is_discovered[r][c] = true;
          queue.push_back({r, c});
        }
        while (!queue.empty())
        {
          ++area;
          r = std::get<0>(queue.front());
          c = std::get<1>(queue.front());
          queue.pop_front();
          if (r > 0 && c > 0 && !is_discovered[r - 1][c - 1] && site[r - 1][c - 1] == 'W')
          {
            is_discovered[r - 1][c - 1] = true;
            queue.push_back({r - 1, c - 1});
          }
          if (r > 0 && !is_discovered[r - 1][c] && site[r - 1][c] == 'W')
          {
            is_discovered[r - 1][c] = true;
            queue.push_back({r - 1, c});
          }
          if (r > 0 && c < (site[0].size() - 1) && !is_discovered[r - 1][c + 1] && site[r - 1][c + 1] == 'W')
          {
            is_discovered[r - 1][c + 1] = true;
            queue.push_back({r - 1, c + 1});
          }
          if (c > 0 && !is_discovered[r][c - 1] && site[r][c - 1] == 'W')
          {
            is_discovered[r][c - 1] = true;
            queue.push_back({r, c - 1});
          }
          if (c < (site[0].size() - 1) && !is_discovered[r][c + 1] && site[r][c + 1] == 'W')
          {
            is_discovered[r][c + 1] = true;
            queue.push_back({r, c + 1});
          }
          if (r < (site.size() - 1) && c > 0 && !is_discovered[r + 1][c - 1] && site[r + 1][c - 1] == 'W')
          {
            is_discovered[r + 1][c - 1] = true;
            queue.push_back({r + 1, c - 1});
          }
          if (r < (site.size() - 1) && !is_discovered[r + 1][c] && site[r + 1][c] == 'W')
          {
            is_discovered[r + 1][c] = true;
            queue.push_back({r + 1, c});
          }
          if (r < (site.size() - 1) && c < (site[0].size() - 1) && !is_discovered[r + 1][c + 1] && site[r + 1][c + 1] == 'W')
          {
            is_discovered[r + 1][c + 1] = true;
            queue.push_back({r + 1, c + 1});
          }
        }
        std::cout << area << "\n";
      }
    }
    if (t) { std::cout << "\n"; }
  }
  return 0;
}