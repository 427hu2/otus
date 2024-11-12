#include "utils.h"

#include <iostream>

int main() {
    std::vector<std::string> ip = input_command_line_data();
    std::vector<std::vector<int> > ip_as_intv = separate_and_convert_to_int(ip);

    std::sort(ip_as_intv.begin(), ip_as_intv.end(), [](std::vector<int> left, std::vector<int> right) {
        return std::tie(left) < std::tie(right);
    });

    for (const auto &v: ip_as_intv) {
        std::cout << v[0] << "." << v[1] << "." << v[2] << "." << v[3] << std::endl;
    }
}
