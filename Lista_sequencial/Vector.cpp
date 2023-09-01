#include<iostream>
#include "Vector.h"

using namespace std;

Vector::Vector() {
    this->m_capacity = 16;
    this->m_size = 0;
    this->data = new int[16];
}
Vector::Vector(int n){
   this->m_size = 0;
    this->m_capacity = n;
    this->data = new int[n];
}
Vector::Vector(const Vector& vector) {
    this->m_capacity = vector.m_capacity;
    this->m_size = vector.m_size;
    this->data = new int[vector.m_capacity];
    for (int i = 0; i < vector.m_capacity; i++){
        this->data[i] = vector.data[i];
    }
}
Vector::~Vector(){
    delete[] this->data;
    this->m_capacity = 0;
    this->m_size = 0;
}
int Vector::capacity() const{
    return m_capacity;
}
int Vector::size() const{
    return this->m_size;
}

bool Vector::empty() const{
    return this->m_size == 0;
}
int Vector::at(int index) const{
    if(index < 0 || index > size() - 1){
        return -1;
    }else{
        return this->data[index];
    }
}
int& Vector::operator[](int index){
    return data[index];
}
void Vector::resize(int n){
    int* new_data = new int[n];
    for (int i = 0; i < n; i++) {
        new_data[i] = data[i];
    }
    if(n > m_capacity){
        m_capacity = n;
    }if(n < m_capacity){
        m_capacity = n;
        if(m_size > n){
            m_size = m_capacity;
        }
    }
    delete[] data;
    data = new_data;
}
void Vector::push_back(int value){
    if(m_size == m_capacity){
        if(m_capacity == 0){
            resize(1);
            data[0] = value;
        }else{
            resize(2 * m_capacity);
        }
        data[m_size] = value;
        m_size += 1;
    }else{
        data[m_size] = value;
        m_size += 1;
    }
}
int Vector::pop_back() {
    if (m_size == 0) {
        return -1;
    } else {
        int aux = m_size - 1;
        m_size -= 1;
        return data[aux];
    }
}
void Vector::replaceAt(int value, int k){
    if(k < 0 || k > m_size - 1){
        return;
    }else{
        data[k] = value;
        return;
    }
}
void Vector::removeAt(int  k){
    for(int i = k; i < this->m_size - 1; i++){
        this->data[i] = this->data[i + 1];
    }
    m_size -= 1;
    return;
}
void Vector::insert(int value, int   k){
    if(k < 0 || k > m_size - 1){
        return;
    }else{
        if(this->m_size == this->m_capacity){
            this->resize(2 * this->m_capacity);
        }else{
            for(int i = this->m_size; i > k; --i){
                this->data[i] = this->data[i - 1];
            }
            this->data[k] = value;
        }
    }
    m_size += 1;
}
void Vector::removeAll(int value){
    int * new_data = new int[m_capacity];
    int new_size{0};
    for(int i{0}; i < m_size; i++){
        if(value != data[i]){
            new_data[new_size] = data[i];
            new_size += 1;
        }
    }
    delete[] data;
    data = new_data;
    m_size = new_size;
}
void Vector::push_front(int value){
    if(m_size == m_capacity){
        if(m_capacity == 0){
            resize(1);
        }else{
            resize(2 * m_capacity);
        }
        m_size += 1;
        for(int i{m_size - 1}; i >= 1; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
    }else{
        m_size += 1;
        for(int i{m_size - 1}; i >= 1; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
    }
} 
int Vector::pop_front() {
    int frontElement = data[0];
    for (int i = 0; i < m_size - 1; i++) {
        data[i] = data[i + 1];
    }
    m_size -= 1;
    return frontElement;
}
 void Vector::remove_duplicates(){
    int cont{0};
    for(int i{0}; i < m_size; i++){
    for(int j{0}; j < m_size; j++){
        if(data[i] == data[j]){
            removeAt(j);
            m_size -= 1;
            cont += 1;
        }
    }
    }
    printf("%d\n", cont);
}
Vector::Vector(int n, int value){
    m_size = n;
    m_capacity = 2 * n;
    data = new int[m_size];
    for(int i{0}; i < m_size; i++){
        data[i] = value;
    }
}
int Vector::front(){
    return data[0];
}
int Vector::back(){
    return data[m_size - 1];
}
int * Vector::begin(){
    return data;
}
int * Vector::end(){
    return (data + m_size);
}