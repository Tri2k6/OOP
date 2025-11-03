#include <iostream>
using namespace std;
 
class Array {
    private:
        size_t size;
        int* arr;
    public:
        Array();
        Array(int n, int* a);
        void input();
        void output();
        size_t getSize();
        void setSize(size_t n);
        int getElement(size_t idx);
        void setElement(size_t idx, int val);
        int find(int val);
        void sort(bool (*cmp) (int, int));
};