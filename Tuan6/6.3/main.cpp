#include "Function.h"
#include <iostream>

int main() {
    std::string str = "[[[the quick,,, brown fox ]]]";
    std::cout << "String before nomalization: " << str << std::endl;
    Normalize(str);
    std::cout << "String after nomalization: " << str << std::endl;
    return 0;
}