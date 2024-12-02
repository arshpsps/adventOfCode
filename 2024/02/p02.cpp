
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // input
    std::vector<std::vector<int>> input;
    std::ifstream fs("./input");
    std::string line;
    while (std::getline(fs, line)) {
        if (!line.empty()) {
            std::istringstream line_stream(line);
            std::vector<int> v;
            int num;
            while (line_stream >> num)
                v.push_back(num);
            input.push_back(v);
        }
    }

    int answer{0};

    for (auto i : input) {
        bool increasing =
            (i[0] < i[1] && i[1] < i[2]) || (i[1] < i[2] && i[2] < i[3]) ||
            (i[2] < i[3] && i[3] < i[4]) ||
            (i[3] < i[4] && i[0] < i[1]); // better just ignore this monstrosity

        int correct = i.size();
        bool ignore_last = false;
        for (int j = 1; j < i.size() && correct >= i.size() - 1; ++j) {
            int prev = j - 1;
            if (ignore_last) {
                prev -= 1;
                ignore_last = false;
            }
            if (!((increasing == true &&
                   (i[j] - i[prev] > 0 && i[j] - i[prev] <= 3)) ||
                  (increasing == false &&
                   (i[prev] - i[j] > 0 && i[prev] - i[j] <= 3)))) {
                if (ignore_last) {
                    correct -= 1;
                    ignore_last = false;
                } else {
                    ignore_last = true;
                }
            }
        }
        if (correct >= i.size() - 1) {
            answer += 1;
        }
    }

    std::cout << answer;

    return 0;
}
