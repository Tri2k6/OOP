#include "Function.h"

void Trim(std::string& str) {
    size_t start = str.find_first_not_of(' ');
    if (start == std::string::npos) {
        return;
    }
    size_t end = str.find_last_not_of(' ');
    str = str.substr(start, end - start + 1);   
}

void Normalize(std::string& str) {
    if (str.empty()) return;
    Trim(str);

    auto isDuplicate = [] (char a, char b) {
        return (std::isspace(a) && std::isspace(b)) || (std::ispunct(a) && std::ispunct(b));
    };

    str.erase(std::unique(str.begin(), str.end(), isDuplicate), str.end());

    bool new_word = true;
    
    std::transform(str.begin(), str.end(), str.begin(), [&](char c) {
        if (std::isalpha(c)) {      
            if (new_word) {
                new_word = false;       
                return (char)std::toupper(c); 
            } else {
                return c; 
            }
        } 
        else if (std::isspace(c) || std::ispunct(c)) { 
            new_word = true;       
            return c;
        }
        
        new_word = false; 
        return c;
    });
}