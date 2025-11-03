#include <iostream>
#include "sort.h"
#include "Fraction.h"
#include <stdexcept>
using namespace std; 

// vi du truong hop Phan so 

// Thu tu sort vi du (sap xep giam dan mau so roi xet den tang dan tu, so)
bool cmp(Fraction<int> a, Fraction<int> b) {
    if (a.den != b.den) return a.den > b.den;
    return a.num < b.num;
}

int main() {
    try
    {
        int size;
        Fraction<int>* arr;
        cout << "Moi ban nhap so luong phan so: ";
        cin >> size;
        if (size <= 0) throw invalid_argument("Error: Do dai cua mang nhap vao khong hop le");
        arr = new Fraction<int>[size];
        if (arr == nullptr) throw invalid_argument("Error: Khong du bo nho de cap phat mang");
        for (int i = 0;i < size;i++) {
            cout << "Phan so thu " << i + 1 << " : "; 
            cin >> arr[i];
        }

        sort(arr, size, cmp);

        cout << "Mang phan so sau khi sap xep: " << endl;

        for (int i = 0;i < size; i++) {
            cout << arr[i] << endl;
        }

        delete[] arr;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}