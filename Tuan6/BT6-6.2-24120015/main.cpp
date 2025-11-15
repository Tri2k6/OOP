#include <iostream>
#include "Function.h"

int main() {
    std::string str = "toi bi ngu";
    std::cout << str << " is a palindrome: " << (isPalindrome(str) ? "Yes": "No");
    return 0;
}