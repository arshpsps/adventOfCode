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
        bool increasing = i[0] < i[1];
        bool correct = true;
        for (int j = 1; j < i.size(); ++j) {
            if (!((increasing == true &&
                   (i[j] - i[j - 1] > 0 && i[j] - i[j - 1] <= 3)) ||
                  (increasing == false &&
                   (i[j - 1] - i[j] > 0 && i[j - 1] - i[j] <= 3))))
                correct = false;
        }
        if (correct) {
            answer += 1;
        }
    }

    std::cout << answer;

    return 0;
}
