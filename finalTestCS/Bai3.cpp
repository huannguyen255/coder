#include <iostream>
#include <stack>

std::string encode(const std::string& s) {

    std::stack<std::pair<char, int>> charStack;
    std::string result;

    for (char c : s) {
        if (charStack.empty() || charStack.top().first != c) {
            charStack.push({c, 1});
        } else {
            charStack.top().second++;
        }
    }

    while (!charStack.empty()) {
        result += std::to_string(charStack.top().second) + charStack.top().first;
        charStack.pop();
    }

    return result;
}

int main() {
    std::string s;
    std::cout << "Nhap chuoi can endcode: ";
    std::cin >> s;

    std::string endcodeS = encode(s);

    std::cout << "Encoded: " << encodedString << std::endl;

    return 0;
}
