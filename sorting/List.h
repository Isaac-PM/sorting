#ifndef INSERTION_SORT_LIST_H
#define INSERTION_SORT_LIST_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node {
private:
    T *data;
    Node<T> *next;
public:
    Node(T* = nullptr, Node<T>* = nullptr);
    void setData(T*);
    T* getData() const;
    void setNext(Node<T>*);
    Node<T>* getNext() const;
    ~Node() = default;
};

template <class T>
Node<T>::Node(T *data, Node<T> *next) {
    this->data = data;
    this->next = next;
}

template <class T>
void Node<T>::setData(T *data) {
    this->data = data;
}

template <class T>
T* Node<T>::getData() const {
    return this->data;
}

template <class T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}

template <class T>
Node<T> *Node<T>::getNext() const {
    return this->next;
}


//----------------------------------------


template <class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List();
    void setHead(Node<T>*);
    Node<T>* getHead() const;
    void setTail(Node<T>*);
    Node<T>* getTail() const;
    bool isEmpty() const;
    void pushBack(T*);
    void popBack();
    void resetTail();

    // Sorting.
    void insertionSort();
    void insertionSortReversed();
    void swap(Node<T>*, Node<T>*);
    void bubbleSort();
    void bubbleSortReversed();
    void selectionSort();
    void selectionSortReversed();
protected:
    Node<T>* merge(Node<T>*, Node<T>*, int);
    Node<T>* middle(Node<T>*);
    Node<T>* internalMergeSort(Node<T>*, int);
public:
    void mergeSort();
    void mergeSortReversed();
protected:
    Node<T>* partition(Node<T>*, Node<T>*, Node<T>**, Node<T>**, int);
    Node<T>* internalQuickSort(Node<T>*, Node<T>*, int);
public:
    void quickSort();
    void quickSortReversed();
};

template <class T>
List<T>::List() {
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
void List<T>::setHead(Node<T> *head) {
    this->head = head;
}

template <class T>
Node<T>* List<T>::getHead() const {
    return this->head;
}

template <class T>
Node<T>* List<T>::getTail() const {
    return this->tail;
}

template <class T>
bool List<T>::isEmpty() const {
    return (head == nullptr && tail == nullptr);
}

template <class T>
void List<T>::pushBack(T *obj) {
    if(isEmpty()) {
        head = new Node<T>(obj, nullptr);
        tail = head;
        return;
    }
    Node<T>* aux = new Node<T>(obj, nullptr);
    tail->setNext(aux);
    tail = aux;
}

template <class T>
void List<T>::popBack() {
    if(!isEmpty()) {
        Node<T>* current = head;
        Node<T>* prevCurrent = nullptr;
        while(current->getNext() != nullptr) {
            prevCurrent = current;
            current = current->getNext();
        }
        prevCurrent->setNext(nullptr);
        tail = prevCurrent;
        delete current;
    }
}

template <class T>
void List<T>::resetTail() {
    Node<T> *current = head;
    while(current->getNext() != nullptr) {
        current = current->getNext();
    }
    tail = current;
}

template <class T>
void List<T>::insertionSort() { // Creciente.
    if(isEmpty()) return;
    Node<T> *sorted = new Node<T>();
    Node<T> *current = head;
    Node<T> *aux = nullptr;
    while(current) {
        aux = sorted;
        while(aux->getNext() && *aux->getNext()->getData() <= *current->getData()) {
            aux = aux->getNext();
        }
        Node<T> *nextCurrent = current->getNext();
        current->setNext(aux->getNext());
        aux->setNext(current);
        current = nextCurrent;
    }
    head = sorted->getNext();
    resetTail();
}

template <class T>
void List<T>::insertionSortReversed() { // Decreciente.
    if(isEmpty()) return;
    Node<T> *sorted = new Node<T>();
    Node<T> *current = head;
    Node<T> *aux = nullptr;
    while(current) {
        aux = sorted;
        while(aux->getNext() && *aux->getNext()->getData() >= *current->getData()) {
            aux = aux->getNext();
        }
        Node<T> *nextCurrent = current->getNext();
        current->setNext(aux->getNext());
        aux->setNext(current);
        current = nextCurrent;
    }
    head = sorted->getNext();
    resetTail();
}

template <class T>
void List<T>::swap(Node<T> *nodeA, Node<T> *nodeB) {
    if(isEmpty()) return;
    T* objA = nodeA->getData();
    T* objB = nodeB->getData();
    nodeA->setData(objB);
    nodeB->setData(objA);
}

template <class T>
void List<T>::bubbleSort() { // Creciente.
    if (isEmpty()) return;
    Node<T> *current;
    Node<T> *aux = nullptr;
    bool swapped = false;
    do {
        swapped = false;
        current = head;
        while(current->getNext() != aux) {
            if(*current->getData() > *current->getNext()->getData()) {
                swap(current, current->getNext());
                swapped = true;
            }
            current = current->getNext();
        }
        aux = current;
    } while(swapped);
    resetTail();
}

template <class T>
void List<T>::bubbleSortReversed() { // Decreciente.
    if(isEmpty()) return;
    Node<T> *current;
    Node<T> *aux = nullptr;
    bool swapped = false;
    do {
        swapped = false;
        current = head;
        while(current->getNext() != aux) {
            if(*current->getData() < *current->getNext()->getData()) {
                swap(current, current->getNext());
                swapped = true;
            }
            current = current->getNext();
        }
        aux = current;
    } while(swapped);
    resetTail();
}

template <class T>
void List<T>::selectionSort() { // Creciente.
    if(isEmpty()) return;
    Node<T> *current = head;
    while(current) {
        Node<T> *min = current;
        Node<T> *aux = current->getNext();
        while(aux) {
            if (*min->getData() >= *aux->getData()) min = aux;
            aux = aux->getNext();
        }
        swap(current, min);
        current = current->getNext();
    }
    resetTail();
}

template <class T>
void List<T>::selectionSortReversed() { // Decreciente.
    if(isEmpty()) return;
    Node<T> *current = head;
    while(current) {
        Node<T> *min = current;
        Node<T> *aux = current->getNext();
        while(aux) {
            if (*min->getData() <= *aux->getData()) min = aux;
            aux = aux->getNext();
        }
        swap(current, min);
        current = current->getNext();
    }
    resetTail();
}

template <class T>
Node<T>* List<T>::merge(Node<T>* nodeA, Node<T>* nodeB, int mode) {
    Node<T> *merged = new Node<T>();
    Node<T> *aux = new Node<T>();
    merged = aux;
    while(nodeA != nullptr && nodeB != nullptr) {
        if(mode == 0) { // 0 = Creciente.
            if(*nodeA->getData() <= *nodeB->getData()) {
                aux->setNext(nodeA);
                nodeA = nodeA->getNext();
            } else {
                aux->setNext(nodeB);
                nodeB = nodeB->getNext();
            }
        } else { // 1 = Decreciente.
            if(*nodeA->getData() >= *nodeB->getData()) {
                aux->setNext(nodeA);
                nodeA = nodeA->getNext();
            } else {
                aux->setNext(nodeB);
                nodeB = nodeB->getNext();
            }
        }
        aux = aux->getNext();
    }
    while(nodeA != nullptr) {
        aux->setNext(nodeA);
        nodeA = nodeA->getNext();
        aux = aux->getNext();
    }
    while(nodeB != nullptr) {
        aux->setNext(nodeB);
        nodeB = nodeB->getNext();
        aux = aux->getNext();
    }
    return merged->getNext();
}

template <class T>
Node<T>* List<T>::middle(Node<T>* headRef){
    Node<T>* slow = headRef;
    Node<T>* fast = headRef->getNext();
    while(!slow->getNext() && (!fast && !fast->getNext())) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    return slow;
}

template <class T>
Node<T>* List<T>::internalMergeSort(Node<T>* headRef, int mode){
    if(headRef->getNext() == NULL) return headRef;
    Node<T>* mid = middle(headRef);
    Node<T>* headAux = mid->getNext();
    mid->setNext(nullptr);
    Node<T>* finalHead = merge(internalMergeSort(headRef, mode), internalMergeSort(headAux, mode), mode);
    return finalHead;
}

template <class T>
void List<T>::mergeSort() { // Creciente.
    if(isEmpty()) return;
    Node<T>* sortedHead = this->internalMergeSort(head, 0);
    setHead(sortedHead);
    resetTail();
}

template <class T>
void List<T>::mergeSortReversed() { // Decreciente.
    if(isEmpty()) return;
    Node<T>* sortedHead = this->internalMergeSort(head, 1);
    setHead(sortedHead);
    resetTail();
}

template <class T>
Node<T>* List<T>::partition(Node<T>* headAux, Node<T>* end, Node<T>** newHeadAux, Node<T>** newEnd, int mode) {
    Node<T>* pivot = end;
    Node<T>* prev = nullptr;
    Node<T>* current = headAux;
    Node<T>* newTail = pivot;
    while(current != pivot) {
        if (mode == 0) {
            if(*current->getData() < *pivot->getData()) { // 0 = Creciente.
                if(*newHeadAux == nullptr) *newHeadAux = current;
                prev = current;
                current = current->getNext();
            } else {
                if(prev) prev->setNext(current->getNext());
                Node<T>* temp = current->getNext();
                current->setNext(nullptr);
                newTail->setNext(current);
                newTail = current;
                current = temp;
            }
        } else { // 1 = Creciente.
            if(*current->getData() > *pivot->getData()) {
                if(*newHeadAux == nullptr) *newHeadAux = current;
                prev = current;
                current = current->getNext();
            } else {
                if(prev) prev->setNext(current->getNext());
                Node<T>* temp = current->getNext();
                current->setNext(nullptr);
                newTail->setNext(current);
                newTail = current;
                current = temp;
            }
        }
    }
    if(*newHeadAux == nullptr) *newHeadAux = pivot;
    *newEnd = newTail;
    return pivot;
}

template <class T>
Node<T>* List<T>::internalQuickSort(Node<T>* headAux, Node<T>* end, int mode) {
    if(!headAux || head == end) return headAux;
    Node<T>* newHead = nullptr;
    Node<T>* newEnd = nullptr;
    Node<T>* pivot = partition(head, end, &newHead, &newEnd, mode);
    if(newHead != pivot) {
        Node<T>* temp = newHead;
        while(temp->getNext() != pivot) {
            temp = temp->getNext();
        }
        temp->setNext(nullptr);
        newHead = internalQuickSort(newHead, temp, mode);
        while(temp != nullptr && temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(pivot);
    }
    pivot->setNext(internalQuickSort(pivot->getNext(), newEnd, mode));
    return newHead;
}

template <class T>
void List<T>::quickSort() { // Creciente.
    this->head = internalQuickSort(this->head, this->tail, 0);
    resetTail();
}

template <class T>
void List<T>::quickSortReversed() { // Decreciente.
    this->head = internalQuickSort(this->head, this->tail, 1);
    resetTail();
}

template <typename T>
ostream& operator<<(ostream& print, const List<T>& obj) {
    if (!obj.isEmpty()) {
        Node<T>* auxNode = obj.getHead();
        while (auxNode != nullptr) {
            print << *auxNode->getData() << endl;
            auxNode = auxNode->getNext();
        }
    }
    else {
        print << "\n[ATENTION] List is empty. [ATENTION]";
    }
    return print;
}

#endif //INSERTION_SORT_LIST_H