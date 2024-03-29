#include <cmath>
#include <vector>
#include <string>

std::vector<std::string> generate_number_strings(int n, char low_digit, char high_digit) {

    int result_size = pow(high_digit-low_digit+1, n);
    std::vector<std::string> result(result_size);
    std::string s(n, low_digit);

    result[0] = s;

    int cur = 1;
    int i = n-1;
    while(i >= 0) {
        if (s[i] == high_digit) {
            i--;
            continue;
        }
        else {
            s[i]++;
            for (int j = i+1; j < n; ++j) {
                s[j] = low_digit;
            }
            i = n-1;
            result[cur] = s;
            cur++;
        }
    }
    return result;
}

