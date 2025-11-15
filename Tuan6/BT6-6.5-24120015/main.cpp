#include "Function.h"

int main() {
    std::list<std::pair<std::string,int>> L;
    L.push_back({"Faker", 1});
    L.push_back({"Doran", 1});
    L.push_back({"Oner", 2});
    L.push_back({"Keria", 3});
    L.push_back({"Chovy", 3});
    L.push_back({"Gumayoshi", 3});

    GroupStudent(L);
    return 0;
}