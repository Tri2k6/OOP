#ifndef SORT_H
#define SORT_H
#pragma once

/*
    Con tro ham cmp (sort criteria) co dang 
    bool cmp(T a, T b) {}
    Ham se tra ve true neu nhu a co do uu tien xep truoc b, nguoc lai thi tra ve false
*/


// Ham merge cua merge sort
template <class T>
void Merge(T* arr, int l, int mid, int r, bool (*cmp)(T, T)) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    T* arrL = new T[n1];
    T* arrR = new T[n2];

    for (int i = 0; i < n1; i++) arrL[i] = arr[l + i];
    for (int j = 0; j < n2; j++) arrR[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (cmp(arrL[i], arrR[j])) {
            arr[k] = arrL[i];
            i++;
            k++;
        }
        else {
            arr[k] = arrR[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arrR[j];
        j++;
        k++;
    }

    delete[] arrL;
    delete[] arrR;
}

// ham merge sort
template <class T>
void MergeSort(T* arr, int l, int r, bool (*cmp)(T, T)) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    MergeSort(arr, l, mid, cmp);
    MergeSort(arr, mid + 1, r, cmp);
    Merge(arr, l, mid, r, cmp);
}

// Ham merge ma de yeu cau
template <class T>
void sort(T* arr, int size, bool (*cmp)(T, T)) {
    MergeSort(arr, 0, size - 1, cmp);
}

#endif
