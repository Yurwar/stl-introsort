//
// Created by yurii on 10.11.18.
//

#ifndef INTROSORT_INTROSPECTION_SORT_H
#define INTROSORT_INTROSPECTION_SORT_H

#include "date.h"
#include "octal_number.h"
#include <vector>
#include <iostream>
#include <cmath>

template <class T>
class Introsort {
private:
    std::vector<T> arr;

    void swap(T &a, T &b);
    int partition(int p, int r);
    void introsort(int p, int r, int depth);
    void heapify(int n, int i);
    void heapSort(int n);

public:
    Introsort();
    Introsort(int size);
    void setArray();
    void setArray(std::vector<T> arr);
    void sort();
    void printArray();
    T* getArray();
    T &operator[](int i);
    void addEl(T el);
};

template<class T>
void Introsort<T>::swap(T &a, T &b) {
    T tmp;
    tmp = a; a = b; b = tmp;
}

template<class T>
int Introsort<T>::partition(int p, int r) {
    T x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; j++) {
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

template<class T>
void Introsort<T>::introsort(int p, int r, int depth) {
    if(p < r) {
        int q = partition(p, r);
        if (arr.size() <= 1) {
            return;
        }
        if (depth == 0) {
            heapSort(arr.size());
        } else {
            introsort(p, q - 1, depth--);
            introsort(q + 1, r, depth--);
        }
    }
}

template<class T>
void Introsort<T>::heapify(int arrSize, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < arrSize && arr[l] > arr[largest])
        largest = l;
    if (r < arrSize && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arrSize, largest);
    }
}

template<class T>
void Introsort<T>::heapSort(int arrSize) {
    for (int i = arrSize / 2 - 1; i >= 0; i--)
        heapify(arrSize, i);
    for (int i= arrSize - 1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

template<class T>
Introsort<T>::Introsort() {
}

template<class T>
void Introsort<T>::setArray() {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << "Enter the " << i + 1 << " element: "; std::cin >> arr[i];
    }
}

template<class T>
void Introsort<T>::setArray(std::vector<T> arr) {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << "Enter the " << i + 1 << " element: "; std::cin >> arr[i];
    }
}

template<class T>
void Introsort<T>::sort() {
    int maxDepth = (int)(floor(log(arr.size())));
    introsort(0, arr.size() - 1, maxDepth);
}

template<class T>
void Introsort<T>::printArray() {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T *Introsort<T>::getArray() {
    return arr;
}

template<class T>
T &Introsort<T>::operator[](int i) {
    if(i < 0) {
        std::cout << "Array index error\n";
        exit(1);
    } else if(i >= arr.size()) {
        arr.resize(i + 1);
    }
    return this->arr[i];
}

template<class T>
void Introsort<T>::addEl(T el) {
    arr.push_back(el);
}

template<class T>
Introsort<T>::Introsort(int size) {
    arr.resize(size);
}

template <>
Introsort<char *>::Introsort() {
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = new char[50];
    }
}

template <>
void Introsort<char *>::setArray() {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << "Enter the " << i + 1 << " element: ";
        std::cin.getline(arr[i], 50);
    }
}

template <>
void Introsort<Date>::printArray() {
    for(int i = 0; i < arr.size(); i++) {
        arr[i].printDate();
        std::cout << ' ';
    }
    std::cout << '\n';

}

template <>
void Introsort<Date>::setArray() {
    for(int i = 0; i < arr.size(); i++) {
        int d, m, y;
        std::cout << "Enter the date of " << i + 1 << " element in format (dd mm yyyy): "; std::cin >> d >> m >> y;
        arr[i] = Date(d, m, y);
    }
}

template <>
void Introsort<octal_number>::setArray() {
    for(int i = 0; i < arr.size(); i++) {
        int intNumber;
        std::cout << "Enter the " << i + 1 << " int to octal number: "; std::cin >> intNumber;
        arr[i].setIntNumber(intNumber);
    }
}

template <>
void Introsort<octal_number>::printArray() {
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i].getOctNumber() << ' ';
    }
    std::cout << std::endl;
}




#endif //INTROSORT_INTROSPECTION_SORT_H
