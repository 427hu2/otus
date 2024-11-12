#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<std::string> ip;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            ip.push_back(line);
        }

        if (line.empty()) {
            break;
        }
    }

    std::vector<std::vector<int>> vv = std::accumulate(ip.begin(), ip.end(), std::vector<std::vector<int>>(), [](std::vector<std::vector<int>> acc, std::string it) {
        std::vector<int> v;
        size_t start = 0;
        while (true) {
            auto pos = it.find('.', start);
            if (pos == std::string::npos) {
                v.push_back(std::stoi(it.substr(start)));
                break;
            }
            v.push_back(std::stoi(it.substr(start, pos - start)));
            start = pos + 1;
        }
        acc.push_back(v);
        return acc;
    });

    sort(vv.begin(), vv.end(), [](std::vector<int> left, std::vector<int> right) {
        return std::tie(left) < std::tie(right);
    });
    for(const auto& v : vv) {
        std::cout << v[0] << "." << v[1] << "." << v[2] << "." << v[3] << std::endl;
    }
}
