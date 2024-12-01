#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // read from 'input' file
    std::vector<int> left;
    std::vector<int> right;
    std::ifstream fs("./input");
    std::string line;
    while (std::getline(fs, line)) {
        std::istringstream line_stream(line);
        int num1, num2;
        line_stream >> num1 >> num2;
        left.push_back(num1);
        right.push_back(num2);
    }
    //

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int answer{0};
    for (int i = 0; i < left.size(); ++i) {
        answer += abs(left[i] - right[i]);
    }

    std::cout << answer;
    return 0;
}
