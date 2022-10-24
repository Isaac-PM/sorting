#ifndef INSERTION_SORT_ARRAY_H
#define INSERTION_SORT_ARRAY_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Array {
private:
    T** arr;
    int objCounter = 0;
    int maxSize;

public:
    Array(const int);
    T** getArr() const;
    int getObjCounter() const;
    int getMaxSize() const;
    bool isEmpty() const;
    bool appendBack(T*);
    bool appendFront(T*);
    bool replaceAtIndex(T*, int);
    bool appendAtIndex(T*, int);
    bool removeBack();
    bool removeFront();
    bool removeAtIndex(int);
    bool swap(int, int);
    Array<T>* subArray(int, int);
    T* at(int);
    // bool removeSearchAttribute(string);

    // Sorting.
    void insertionSort();
    void insertionSortReversed();
    void bubbleSort();
    void bubbleSortReversed();
    void selectionSort();
    void selectionSortReversed();
protected:
    void merge(Array<T>*, Array<T>*, int, int, int, int);
    void internalMergeSort(Array<T>*, Array<T>*, int, int, int);
public:
    void mergeSort();
    void mergeSortReversed();
protected:
    int partition(int, int, int);
    void internalQuickSort(int, int, int);
public:
    void quickSort();
    void quickSortReversed();
    ~Array();
};

template <class T>
void Array<T>::insertionSort() { // Creciente.
    for (int i = 1; i < objCounter; i++) {
        T current = *arr[i];
        int j = i - 1;
        while (j >= 0 && *arr[j] > current) {
            *arr[j + 1] = *arr[j];
            j--;
        }
        *arr[j + 1] = current;
    }
}

template <class T>
void Array<T>::insertionSortReversed() { // Decreciente.
    for (int i = 1; i < objCounter; i++) {
        T current = *arr[i];
        int j = i - 1;
        while (j >= 0 && *arr[j] < current) {
            *arr[j + 1] = *arr[j];
            j--;
        }
        *arr[j + 1] = current;
    }
}

template <class T>
void Array<T>::bubbleSort() { // Creciente.
    T *obj = nullptr;
    for (int i = 0; i < objCounter; i++) {
        for (int j = i + 1; j < objCounter; j++) {
            if (*arr[j] <= *arr[i]) {
                swap(i, j);
            }
        }
    }
}

template <class T>
void Array<T>::bubbleSortReversed() { // Decreciente.
    for (int i = 0; i < objCounter; i++) {
        for (int j = i + 1; j < objCounter; j++) {
            if (*arr[j] >= *arr[i]) {
                swap(i, j);
            }
        }
    }
}

template <class T>
void Array<T>::selectionSort() { // Creciente.
    for (int i = 0; i < objCounter - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < objCounter; j++) {
            if (*arr[j] <= *arr[minIndex]) minIndex = j;
        }
        swap(minIndex, i);
    }
}

template <class T>
void Array<T>::selectionSortReversed() { // Decreciente.
    for (int i = 0; i < objCounter - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < objCounter; j++) {
            if (*arr[j] >= *arr[minIndex]) minIndex = j;
        }
        swap(minIndex, i);
    }
}

template <class T>
void Array<T>::merge(Array<T> *array, Array<T> *arrayAux, int left, int mid, int right, int mode) {
    int i = 0, last = 0, len = 0, pos = 0;
    last = mid - 1;
    pos = left;
    len = right - left + 1;
    while (left <= last && mid <= right) {
        if (mode == 0) { // 0 = Creciente.
            if (*array->at(left) <= *array->at(mid)) arrayAux->replaceAtIndex(array->at(left++), pos++);
            else arrayAux->replaceAtIndex(array->at(mid++), pos++);
        } else { // 1 = Decreciente.
            if (*array->at(left) >= *array->at(mid)) arrayAux->replaceAtIndex(array->at(left++), pos++);
            else arrayAux->replaceAtIndex(array->at(mid++), pos++);
        }
    }
    while (left <= last) arrayAux->replaceAtIndex(array->at(left++), pos++);
    while (mid <= right) arrayAux->replaceAtIndex(array->at(mid++), pos++);
    for (i = 0; i < len; i++) {
        array->replaceAtIndex(arrayAux->at(right), right);
        right--;
    }
}

template <class T>
void Array<T>::internalMergeSort(Array<T> *array, Array<T> *arrayAux, int left, int right, int mode) {
    int mid = 0;
    if (left < right) {
        mid = (left + right) / 2;
        internalMergeSort(array, arrayAux, left, mid, mode);
        internalMergeSort(array, arrayAux, mid + 1, right, mode);
        merge(array, arrayAux, left, mid + 1, right, mode);
    }
}

template <class T>
void Array<T>::mergeSort() { // Creciente.
    Array<T> *arrAux = new Array<T>(this->maxSize);
    for(int i = 0; i <= this->objCounter; i++){
        arrAux->appendBack(nullptr);
    }
    this->internalMergeSort(this, arrAux, 0, this->getObjCounter() - 1, 0);
}

template <class T>
void Array<T>::mergeSortReversed() { // Decreciente.
    Array<T> *arrAux = new Array<T>(this->maxSize);
    for(int i = 0; i <= this->objCounter; i++){
        arrAux->appendBack(nullptr);
    }
    this->internalMergeSort(this, arrAux, 0, this->getObjCounter() - 1, 1);
}

template <class T>
int Array<T>::partition(int min, int max, int mode) {
    if(min > objCounter || max > objCounter) return INT_MIN;
    T* pivot = arr[min];
    int lower = min;
    for(int i = min + 1; i <= max; i++) {
        if(mode == 0) { // 0 = Creciente.
            if(*arr[i] < *pivot) {
                lower++;
                swap(lower, i);
            }
        } else { // 1 = Decreciente.
            if (*arr[i] > *pivot) {
                lower++;
                swap(lower, i);
            }
        }
    }
    swap(min, lower);
    return lower;
}

template<class T>
void Array<T>::internalQuickSort(int min, int max, int mode) {
    if(min > objCounter || max > objCounter) return;
    int division = 0;
    if (min < max) {
        division = partition(min, max, mode);
        internalQuickSort(min, division - 1, mode);
        internalQuickSort(division + 1, max, mode);
    }
}

template<class T>
void Array<T>::quickSort() { // Creciente.
    if(isEmpty()) return;
    this->internalQuickSort(0, this->getObjCounter() - 1, 0);
}

template<class T>
void Array<T>::quickSortReversed() { // Decreciente.
    if(isEmpty()) return;
    this->internalQuickSort(0, this->getObjCounter() - 1, 1);
}

template <class T>
Array<T>::Array(int maxSize) {
    this->maxSize = maxSize;
    arr = new T*[this->maxSize];
    for (int i = 0; i < this->maxSize; ++i) {
        arr[i] = nullptr;
    }
}

template <class T>
T** Array<T>::getArr() const {
    return this->arr;
}

template <class T>
int Array<T>::getObjCounter() const {
    return this->objCounter;
}

template <class T>
int Array<T>::getMaxSize() const {
    return this->maxSize;
}

template <class T>
bool Array<T>::isEmpty() const {
    return objCounter == 0;
}

template <class T>
bool Array<T>::appendBack(T* obj) {
    if (objCounter < maxSize) {
        arr[objCounter++] = obj;
        return true;
    }
    return false;
}

template <class T>
bool Array<T>::appendFront(T* obj) {
    if (objCounter < maxSize) {
        if (objCounter == 0) {
            appendBack(obj);
            return true;
        }
        arr[objCounter++] = nullptr;
        for (int i = 0; i < objCounter; i++) {
            arr[objCounter - i] = arr[objCounter - i - 1];
        }
        arr[0] = obj;
        return true;
    }
    return false;
}

template <class T>
bool Array<T>::replaceAtIndex(T* obj, int index) {
    if (isEmpty()) {
        if (appendBack(obj)) return true;
    } else if (index > objCounter) return false;
    for(int i = 0; i < objCounter; i++) {
        if (i == index) {
            arr[index] = obj;
            return true;
        }
    }
    return false;
}

template <class T>
bool Array<T>::appendAtIndex(T* obj, int index) {
    if (isEmpty() || index == 0 || index > objCounter) {
        if (appendBack(obj)) return true;
    }
    arr[objCounter++] = nullptr;
    for (int i = 1; i < (objCounter - index); i++) {

        arr[objCounter - i] = arr[objCounter - i - 1];

    }
    arr[index] = obj;
    return true;
}

template <class T>
bool Array<T>::removeBack() {
    if (!isEmpty()) {
        T* aux = arr[objCounter];
        delete aux;
        arr[objCounter] = nullptr;
        objCounter--;
        return true;
    }
    return false;
}

template <class T>
bool Array<T>::removeFront() {
    if (!isEmpty()) {
        T* aux = arr[0];
        delete aux;
        arr[0] = nullptr;
        for (int i = 0; i < objCounter; i++) {
            arr[i] = arr[i + 1];
        }
        removeBack();
        return true;
    }
    return false;
}

template <class T>
bool Array<T>::removeAtIndex(int index) {
    if (!isEmpty()) {
        if (index == 0) { removeFront(); return true; }
        T* aux = arr[index];
        delete aux;
        arr[index] = nullptr;
        for (int i = index; i < objCounter; i++) {
            if(i + 1 < objCounter) arr[i] = arr[i + 1];
        }
        objCounter--;
        return true;
    }
    return false;
}

template <class T>
bool Array<T>::swap(int indexOne, int indexTwo) {
    if (indexOne > objCounter ||
        indexTwo > objCounter ||
        indexOne == indexTwo ||
        indexOne < 0 ||
        indexTwo < 0 ||
        isEmpty()) {
        return false;
    }
    T* aux = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = aux;
    return true;
}

template <class T>
T* Array<T>::at(int index) {
    if (isEmpty()) return nullptr;
    return arr[index];
}

template <class T>
Array<T>* Array<T>::subArray(int from, int to) {
    auto *result = new Array<T>(to - from + 1);
    for (int i = from; i < to; i++) {
        result->appendBack(this->at(i));
    }
    return result;
}

template <class T>
Array<T>::~Array() {
    for (int i = 0; i < objCounter; i++) {
        delete arr[i];
    }
    delete[]arr;
    objCounter--;
}

template <typename T>
ostream& operator<<(ostream& print, const Array<T>& obj) {
    if (!obj.isEmpty()) {
        for (int i = 0; i < obj.getObjCounter(); i++) {
            print << *(obj.getArr())[i] << endl;
        }
    }
    return print;
}

#endif //INSERTION_SORT_ARRAY_H
