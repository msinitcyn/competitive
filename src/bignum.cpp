#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

const int BASE = 9;

class BigNum {
public:
    std::vector<int> number;

    BigNum(std::string& s) {
        for (int i = s.length(); i >= 0; i-=BASE) {
            int size_left = std::min(i, BASE);
            int cur = stoi(s.substr(i-size_left, size_left));
            number.push_back(cur);
        }
        if (!number.size()) {
            number.push_back(0);
        }
    }

    BigNum(std::vector<int> v) {
        if (!v.size()) {
            number = {0};
        } else {
            number = v;
        }
    }

    std::string to_string() {
        std::string result = std::to_string(number.back());
        for (int i = number.size()-2; i >= 0; --i) {
            std::string next = std::to_string(number[i]);
            if (next.length() < BASE) {
                next.append(std::string(BASE-next.length(), '0'));
            }
            result.append(next);
        }
        return result;
    }
};

int compare(BigNum& a, BigNum& b) {
    if (a.number.size() == b.number.size()) {
        for (int i = a.number.size()-1; i >= 0; --i) {
            if (a.number[i] == b.number[i]) {
                continue;
            }
            return a.number[i] > b.number[i] ? 1 : -1;
        }
    }
    return 0;
}

BigNum add(BigNum& a, BigNum& b) {
    std::vector<int> result;
    int carry_in = 0;
    int base = (int)pow(10, BASE);
    int i = 0;
    while (i < a.number.size() || i < b.number.size() || carry_in) {
        int next = carry_in;
        next += i < a.number.size() ? a.number[i] : 0;
        next += i < b.number.size() ? b.number[i] : 0;
        if (next >= base) {
            carry_in = 1;
        }
        result.push_back(next % base);
        carry_in = next / base;
        i++;
    }
    return BigNum(result);
}

BigNum subtract(BigNum& a, BigNum& b) {
    std::vector<int> result;
    int base = (int)pow(10, BASE);
    int borrow_in = 0;
    for (int i = 0; i < a.number.size() || borrow_in; ++i) {
        int next =  a.number[i]-borrow_in;
        next -= b.number.size() <= i ? 0 : b.number[i];
        if (next < 0) {
            borrow_in = 1;
            next += base;
        } else {
            borrow_in = 0;
        }
        result.push_back(next%base);
    }
    int i = 0;
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return BigNum(result);
}
