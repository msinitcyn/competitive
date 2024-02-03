#include <string>
#include <vector>

std::vector<int> prefix_function(std::string& s) {
    std::vector<int> result(s.length(), 0);

    for (int i = 1; i < s.length(); ++i) {
        int next_prefix = result[i-1];
        while (next_prefix > 0 && s[next_prefix] != s[i]) {
            next_prefix = result[next_prefix-1];
        }
        if (s[next_prefix] == s[i]) {
            result[i] = next_prefix+1;
        }
    }
    return result;
}

int find(std::string& s, std::string pattern) {
    char delimeter = 1;
    std::string new_s = pattern + delimeter + s;

    std::vector<int> pf = prefix_function(new_s);

    int result = -1;
    for (int i = pattern.length()*2; i < pf.size(); ++i) {
        if (pf[i] == pattern.length()) {
            result = i - 2*pattern.length();
            break;
        }
    }
    return result;
}
