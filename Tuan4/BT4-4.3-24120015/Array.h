#pragma once
#include<iostream>
#include <sstream>
#include <string>
#include<stdexcept>
using namespace std;

template<class T> 
class Array {
private:
    int size;
    T* arr;
public:
    Array();
    Array(int size);
    Array(size_t sizee, T* Arr);
    Array(const Array<T>& other);
    ~Array();
public:
    Array& operator = (const Array<T>& other);
    T& operator[] (int idx);
    operator T*();
 
    template <typename U>
    friend istream& operator>>(istream& in, Array<U>& a);
    
    template <typename U>
    friend ostream& operator<<(ostream& out, const Array<U>& a);
};



template<class T> 
Array<T>::~Array() {
    delete[] arr;
}

template<class T> 
Array<T>::Array() {
    size = 0;
    arr = nullptr;
}

template<class T> 
Array<T>::Array(int sizee) {
    if (sizee < 0) throw std::invalid_argument("So luong phan tu cua mang khong hop le");
    size = sizee;
    arr = new T[size]();
    if (arr == nullptr) throw std::bad_alloc();
}

template<class T> 
Array<T>::Array(size_t sizee, T* Arr) {
    if (!Arr) throw std::invalid_argument("Mang nguon khong hop le");
    size = sizee;
    arr = new T[size];
    if (arr == nullptr) throw std::bad_alloc();
    for (int i = 0;i < size;i++) {
        arr[i] = Arr[i];
    }
}

template<class T> 
Array<T>::Array(const Array<T>& other) {
    size = other.size;
    arr = new T[size];
    for (int i = 0;i < size;i++) {
        arr[i] = other.arr[i];
    }
}

template<class T> 
Array<T>& Array<T>::operator = (const Array<T>& other) {
    if (this == &other) return *this;
    T* new_arr = new T[other.size];
    if (!new_arr) throw bad_alloc();

    for (int i = 0;i < other.size;i++) {
        new_arr[i] = other.arr[i];
    }

    delete[] arr;

    size = other.size;
    arr = new_arr;
    return *this;
}

template<class T>
T& Array<T>::operator [] (int idx) {
    if (idx < 0 || idx >= size) 
        throw invalid_argument("Loi vi tri truy cap khong hop le");
    return arr[idx];
}
    
template<class T> 
Array<T>::operator T*() {
    return arr;
}

template<typename T>
istream& operator >> (istream& input, Array<T>& A) {
    string Line, buffer;
    int new_size;

    cout << "Moi ban nhap so luong phan tu cua mang: ";
    getline(input,Line);
    stringstream ss(Line);
    if (!(ss >> new_size) || new_size < 0 || (ss >> buffer))
        throw invalid_argument("Loi nhap so luong phan tu!");

    delete[] A.arr;
    A.size = new_size;
    A.arr = new T[A.size];
    if (!A.arr) throw bad_alloc();

    cout << "Moi ban nhap lan luot tung phan tu cua mang: ";
    getline(input,Line);
    ss.clear();
    ss.str(Line);

    for (int i = 0;i < A.size;i++) {
        if (!(ss >> A.arr[i])) throw invalid_argument("Loi nhap phan tu thu" + to_string(i) + "!");
    }

    if (ss >> buffer) throw invalid_argument("Loi nhap mang");
    return input;
}

template<typename T>
ostream& operator << (ostream& output, const Array<T> & A) {
    output << A.size << '\n';
    for (int i = 0;i < A.size;i++) {
        output << A.arr[i] << ' ';
    }
    output << "\n";
    return output;
}