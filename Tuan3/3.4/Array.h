#pragma once
#include <iostream>
#include <stdexcept>

template<class T> 
class Array{
private:
    int size;
    T* arr;
public:
    Array() {
        size = 0;
        arr = NULL;
    }
    Array(int sizee) {
        if (sizee < 0) throw std::invalid_argument("So luong phan tu cua mang khong hop le");
        size = sizee;
        arr = new T[size]();
        if (arr == NULL) throw std::bad_alloc();
    }
    Array(size_t sizee, T* Arr) {
        if (!Arr) throw std::invalid_argument("Mang nguon khong hop le");
        if (sizee < 0) throw std::invalid_argument("So luong phan tu cua mang khong hop le");
        size = sizee;
        arr = new T[size];
        if (arr == NULL) throw std::bad_alloc();
        for (int i = 0;i < size;i++) {
            arr[i] = Arr[i];
        }
    }
    Array(const Array<T>& other) {
        size = other.size;
        arr = new T[size];
        for (int i = 0;i < size;i++) {
            arr[i] = other.arr[i];
        }
    }

    void output() {
        std::cout << size << std::endl;
        for (int i = 0;i < size;i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }

    ~Array() {
        delete[] arr;
    }
};