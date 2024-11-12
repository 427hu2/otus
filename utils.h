#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

std::vector<std::string> input_command_line_data() {
    // argv example 123.123.123.123
    std::vector<std::string> ip;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            ip.push_back(line);
        }

        // TODO
        if (line.empty()) {
            break;
        }
    }

    return ip;
}

std::vector<std::vector<int> > separate_and_convert_to_int(const std::vector<std::string> &ip) {
    return std::accumulate(ip.begin(), ip.end(), std::vector<std::vector<int> >(),
                           [](std::vector<std::vector<int> > acc, const std::string& it) {
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
}
#endif //UTILS_H
