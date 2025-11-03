#include <iostream>
#include "Array.h"
#include <stdexcept>
using namespace std;

int main() {
    try
    {
        Array<int> arr_int;
        arr_int.output();
        cout << endl;

        int ex_size = 13;
        Array<double> arr_double = Array<double>(ex_size);
        arr_double.output();
        cout << endl;

        long long* ex_ll_arr = new long long[ex_size];
        for (int i = 0;i < ex_size;i++) {
            ex_ll_arr[i] = rand();
        }
        Array<long long> arr_llong = Array<long long>(ex_size - 3, ex_ll_arr);
        arr_llong.output();
        cout << endl;
                
        char * ex_char = new char[ex_size + 1];
        ex_char[ex_size] = '\0';
        for (int i = 0;i < ex_size;i++) {
            ex_char[i] = char(i + 'a');
        }
        Array<char> arr_char1 = Array<char>(ex_size, ex_char);
        Array<char>* arr_char2 = new Array<char>(arr_char1);
        arr_char2->output();
        cout << endl;

        delete[] ex_char;
        delete[] ex_ll_arr;
        delete arr_char2;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::bad_alloc& e) {
        std::cerr << "Loi cap phat bo nho: " << e.what() << '\n';
    }
    
}

