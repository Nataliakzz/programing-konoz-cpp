#ifndef __LIST_H__
#define __LIST_H__
#include "school.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <fstream>
using std :: cout;
using std :: ofstream;
using std :: ifstream;
using std :: cerr;
using std :: endl;
using std :: string;

template<class T>
class List {
public:
    T** data;
    size_t size;
    List() : data(nullptr), size(0) { }
    List(const List& copy) : data(new T * [copy.size]), size(copy.size)  {
        for (size_t i = 0; i < size; i++){
            data[i] = new T(*(copy.data[i]));
        }
    }
    ~List(){
        for (size_t i = 0; i < size; i++){
            delete data[i];
        }
        if (size > 0) {
            delete[] data;
        }
    }
    void Print () const {
        for (size_t i = 0; i < this->size; i++) {
            cout << this->schools [i]->To_string();
    }
}

    void Add_Element (size_t pos, const T *school){
T** New_Array = new T*[this->size + 1];
    if (pos > this->size) {
        pos = this->size;
    }
    memcpy(New_Array, this->data, pos * sizeof(T*));
    New_Array [pos] = new T(*school);
    memcpy(New_Array + pos +1, this->data + pos, (this->size - pos) * sizeof(T*));
    if (this->size > 0) {
        delete[] this->data;
    }
    this->data = New_Array;
    this->size++;
    delete school;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
}

    void Delete_Element (size_t pos) {
if (this->size == 0) 
return;
    T** New_Array = new T*[this->size - 1];
    if (pos >= this->size) {
        pos = this->size - 1;
    }
    delete this->data[pos];
    memcpy( New_Array, this->data, pos * sizeof(T*));
    memcpy(New_Array + pos, this->data + pos +1, (this->size - pos -1) * sizeof(T*));
    delete[] this->data;
    this->data = New_Array;
    this->size--;

template <class A>
int Sort_By_Amount_of_Students_Asc(const void *a, const void *b) {
    const A *school_1 = *(const A**)a;
    const A *school_2 = *(const A**)b;

    if (school_1->getAmount_of_students() < school_2->getAmount_of_students()) {
        return -1;
    } else if (school_1->getAmount_of_students() > school_2->getAmount_of_students()) {
        return 1;
    } else {
        return 0;
    }
}

    void Sort_by_Amount_of_students (){
int (*pFunction)(const void*, const void*);
    pFunction = &Sort_By_Amount_of_Students_Asc;
    qsort(this->data, this->size, sizeof(T*), pFunction);
}}

#endif
