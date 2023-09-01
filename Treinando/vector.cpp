#include<iostream>
#include<vector>

using namespace std;

template <typename T>
struct vetor{
    int size;
    int capacity;
    T * data;

    vetor(int size, T value){
        this->capacity = size;
        this->size = size;
        this->data = new T[size];
        for(int i = 0; i < size; i++){
            data[i] = value;
        }
    }
    ~vetor(){
        delete[] this->data;
    }
    T& operator[](int index){
        return this->data[index];
    }
    int capacity(){
        return this->capacity;
    }
    T& front(){
        return this->data[0];
    }
    T& back(){
        return this->data[size];
    }
    int size(){
        return this->size;
    }
    void reserve(int value){
        T * new_data = new T[capacity];
        int qtd = min(this->size, capacity);
        for(int i = 0; i < qtd; i++){
            new_data[i] = data[i];
        }
        this->size = qtd;
        this->capacity = capacity;
        delete[] this->data;
        this->data = new_data;
    }
    void push_back(T value){
        if(this->size == this->capacity){
            if(this->capacity == 0){
                reserve(1);
            }else{
                reserve(2 * this->capacity);
            }
        }
        this->data[this->size] = value;
        this->size += 1;
    }
    void pop_back(){
        if(this-size == 0){
            return;
        }else{
            this->size -= 1;
        }
    }
    T& at(int index){
        if(index < 0 || index > this->size - 1){
            cout << "Indice invalido";
        }else{
            return this->data[index];
        }
    }
    T * begin(){
        return &this->data[0];
    }
    T * end(){
        return this->data + size;
    }
    void insert(T *  it, T value){
        int pos = it - this->data; 
        if(this->size == this->capacity){
            this->reserve(2 * this->capacity);
        }else{
            for(int i = this->size; i > pos; --i){
                this->data[i] = this->data[i - 1];
            }
            this->data[pos] = value;
        }
    }
    void erase(T * it){
        int pos = it - this->data; 
        for(int i = pos; i < this->size - 1; i++){
            this->data[i] = this->data[i + 1];
        }
    }
    void replaceAt(int value, int k){
    if(k < 0 || k > size - 1){
        return;
    }else{
        data[k] = value;
        return;
    }
}
void removeAt(int  k){
    for(int i = k; i < this->m_size - 1; i++){
        this->data[i] = this->data[i + 1];
    }
    size -= 1;
    return;
}
void insert(T value, int  k){
    if(k < 0 || k > size - 1){
        return;
    }else{
        if(this->m_size == this->capacity){
            this->resize(2 * this->capacity);
        }else{
            for(int i = this->size; i > k; --i){
                this->data[i] = this->data[i - 1];
            }
            this->data[k] = value;
        }
    }
}
void removeAll(int value){
    int * new_data = new int[capacity];
    int new_size{0};
    for(int i{0}; i < size; i++){
        if(value != data[i]){
            new_data[new_size] = data[i];
            new_size += 1;
        }
    }
    delete[] data;
    data = new_data;
    size = new_size;
}
void push_front(T value){
    if(size == capacity){
        if(capacity == 0){
            resize(1);
        }else{
            resize(2 * capacity);
        }
        size += 1;
        for(int i{size - 1}; i >= 1; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
    }else{
        size += 1;
        for(int i{size - 1}; i >= 1; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
    }
} 
int pop_front() {
    int frontElement = data[0];
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size -= 1;
    return frontElement;
}
};

int main(){
    vetor<int> vet(10, 1);

    cout << vet[0] << '\n';
    cout << vet.at(1) << '\n';
    cout << vet.front() << '\n';
    cout << vet.back() << '\n';
 
    vet.reserve(200);
    vet.push_back(6);
    vet.pop_back();

    vet.insert(vet.begin() + 1, 10);
    vet.erase(vet.begin() + 1);

    for(auto it = vet.begin(); it != vet.end(); it++){
        cout << *it << " ";
    }
    cout << '\n';

    for(auto elem: vet){
        cout << elem << ' ';
    }
    cout << '\n';

    auto print = [&vet]{
        for(auto it = vet.begin(); it != vet.end(); it++){
            cout << *it << " ";
        }
        cout << '\n';
    };
     
    return 0;
};