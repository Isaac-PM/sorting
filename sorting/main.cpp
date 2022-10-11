#include "Array.h"
#include "List.h"
#include "Person.h"

int main() {
    /*
    [WARNING] Comparisons with operators "<, >, <=, >=, == and !=" may vary depending on the overload implemented. [WARNING]
    [ADVERTENCIA] Las comparaciones con los operadores "<, >, <=, >=, == y !=" pueden variar en función de la sobrecarga implementada. [ADVERTENCIA]
    */

    Array<Person> *arr = new Array<Person>(1000);
    Person* per1 = new Person("John", 18);
    Person* per2 = new Person("Mathew", 13);
    Person* per3 = new Person("James", 33);
    Person* per4 = new Person("Paul", 79);
    Person* per5 = new Person("Peter", 11);
    Person* per6 = new Person("Jesus", 35);
    arr->appendBack(per1);
    arr->appendBack(per2);
    arr->appendBack(per3);
    arr->appendBack(per4);
    arr->appendBack(per5);
    /*
    cout << *arr << endl;
    arr->insertionSort();
    cout << *arr << endl;
    arr->insertionSortReversed();
    cout << *arr << endl;

    cout << *arr << endl;
    arr->bubbleSort();
    cout << *arr << endl;
    arr->bubbleSortReversed();
    cout << *arr << endl;

    cout << *arr << endl;
    arr->selectionSort();
    cout << *arr << endl;
    arr->selectionSortReversed();
    cout << *arr << endl;

    cout << *arr << endl;
    arr->mergeSort();
    cout << *arr << endl;
    arr->mergeSortReversed();
    cout << *arr << endl;

    cout << *arr << endl;
    arr->quickSort();
    cout << *arr << endl;
    arr->quickSortReversed();
    cout << *arr << endl;
    */

    List<Person> *list = new List<Person>();
    list->pushBack(per1);
    list->pushBack(per2);
    list->pushBack(per3);
    list->pushBack(per4);
    list->pushBack(per5);
    /*
    cout << *list << endl;
    list->insertionSort();
    cout << *list << endl;
    list->insertionSortReversed();
    cout << *list << endl;

    cout << *list << endl;
    list->bubbleSort();
    cout << *list << endl;
    list->bubbleSortReversed();
    cout << *list << endl;

    cout << *list << endl;
    list->selectionSort();
    cout << *list << endl;
    list->selectionSortReversed();
    cout << *list << endl;

    cout << *list << endl;
    list->mergeSort();
    cout << *list << endl;
    list->mergeSortReversed();
    cout << *list << endl;

    cout << *list << endl;
    list->quickSort();
    cout << *list << endl;
    list->quickSortReversed();
    cout << *list << endl;
     */

    return 0;
}
