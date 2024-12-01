#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main() {
    // read from 'input' file
    std::unordered_set<int> left;
    std::unordered_map<int, int> right;
    std::ifstream fs("./input");
    std::string line;
    while (std::getline(fs, line)) {
        std::istringstream line_stream(line);
        int num1, num2;
        line_stream >> num1 >> num2;
        left.insert(num1);
        right[num2]++;
    }
    //

    int answer{0};
    for (auto i : left) {
        answer += i * right[i];
    }
    std::cout << answer;

    return 0;
}
