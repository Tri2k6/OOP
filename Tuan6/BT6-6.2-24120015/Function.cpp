#include "Function.h"

bool isPalindrome(std::string str) {

    std::transform(str.begin(), str.end(), str.begin(), (int(*)(int))std::tolower);

    auto condition = [] (char c) {
        return (c == ',') || c == ' ';
    };

    auto new_end = std::remove_if(str.begin(), str.end(), condition);

    str.erase(new_end,str.end());

    std::string r_str = str;
    std::reverse(r_str.begin(), r_str.end());
    return (r_str.compare(str) == 0); 
}
