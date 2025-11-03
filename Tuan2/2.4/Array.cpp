#include<iostream>
#include "Array.h"
#include <sstream>
#include <string>
using namespace std;

Array::Array() {
    size = 0;
    arr = NULL;
}

Array::Array(int n, int* a) {
    if (n < 0) throw invalid_argument("Do dai mang la 1 so am");
    size = n;
    arr = a;
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

void Array::input() {
    string str, str_buffer;
    cout << "Moi ban nhap so luong phan tu cua mang: ";
    getline(cin,str);
    stringstream ss(str);
    int buffer;
    if (!(ss >> buffer) || buffer < 0) throw invalid_argument("Loi nhap so luong phan tu");
    if (ss >> str_buffer) throw invalid_argument("Loi nhap so luong phan tu");
    size = buffer;
    arr = new int[size];

    ss.clear();
    cout << "Moi ban nhap lan luot tung phan tu cua mang: ";
    getline(cin,str);
    ss.str(str);
    for (int i = 0;i < size;i++) {
        if (!(ss >> buffer)) throw invalid_argument("Loi nhap phan tu");
        arr[i] = buffer;
    }
    if (ss >> str_buffer) throw invalid_argument("Loi nhap phan tu");
}


void Array::output() {
    cout << size << endl;
    for (int i = 0;i < size;i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

size_t Array::getSize() {
    return size;
}

void Array::setSize(size_t n) {
    if (n < 0) throw invalid_argument("Loi so luong phan tu am");
    int *b = new int[n] {0};
    for (int i = 0;i < size;i++) b[i] = arr[i];
    arr = b;
    size = n;
}

int Array::getElement(size_t idx) {
    if (idx < 0 || idx > size - 1) throw invalid_argument("So thu tu khong hop le");
    return arr[idx]; 
}   

void Array::setElement(size_t idx, int val) {
    if (idx < 0 || idx > size - 1) throw invalid_argument("Dia chi phan tu khong hop le");
    arr[idx] = val;
}

int Array::find(int val) {
    for (int i = 0;i < size;i++) {
        if (arr[i] == val) return i;
    }
    return -1;
}

void Array::sort(bool (*cmp) (int,int)) {
    for (int i = 0;i < size - 1;i++) {
        int Min = i;
        for (int j = i + 1;j < size;j++) {
            if (!cmp(arr[Min], arr[j])) Min = j;
        }
        swap(arr[i], arr[Min]);
    }
}