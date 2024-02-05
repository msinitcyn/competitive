#include <algorithm>
#include <vector>
#include <string>

class BigNum {

    std::vector<int> number;
    int base;

public:

    BigNum(std::string& s, int base) {
        this->base = base;
        for (int i = s.length(); i >= 0; i-=base) {
            int size_left = std::min(i, base);
            int cur = stoi(s.substr(i-size_left, size_left));
            number.push_back(cur);
        }
        if (!number.size()) {
            number.push_back(0);
        }
    }

    BigNum(std::string& s): BigNum(s, 9) {
    }

    std::string to_string() {
        std::string result;
        for (int i = number.size()-1; i >= 0; --i) {
            result.append(std::to_string(number[i]));
        }
        if (result == "") {
            result = "0";
        }
        return result;
    }
};
