#include <iostream>
#include <iterator>

template<typename T>
class vector
{
public:
    vector() ;
    vector(int colum,T value) ;
    vector(const vector & other) ;
    vector(vector && other) ;
    vector & operator=(const vector & other) ;
    vector & operator=(vector && other) ;
    T operator[] (int index) ;
    ~vector() ;
    vector(const std::initializer_list<T>& elems) ;
public:
    void push_back(const T& value) ;
    void pop_back() ;
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    void shrink_to_fit() ;
public:

    class iterator : public std::iterator<std::random_access_iterator_tag,T>
    {
    public:
        iterator(T * p = nullptr) { 
            iter = p ;
        }
        iterator(const iterator& it) {
            iter = it.iter ;
        }
        iterator & operator= (const iterator& it) {
            if(this == &it) { return *this ; }
            this->iter = it.iter ;
            return *this ;
        }
        iterator operator+(const int& add) {
            iterator it ;
            it.iter = iter + add ;
            return it ;
        }
        iterator operator-(const int& sub) {
            iterator it ;
            it.iter = iter - sub ;
            return it ;
        }
        iterator& operator+=(const int& add) {
            this->iter += add ;
            return *this ;
        }
        iterator& operator-=(const int& sub) {
            this->iter -= sub ;
            return *this ;
        }
        T& operator++() {
            ++iter ;
            return *iter ;
        }
        T& operator++(int) {
            T *tmp = iter ;
            ++iter ;
            return *tmp ;
        }
        T& operator--() {
            --iter ;
            return *iter ;
        }
        T& operator--(int) {
            T *tmp = iter ;
            --iter ;
            return *tmp ;
        }
        bool operator!=(const iterator& other) const {
            return this->iter != other.iter ;
        }
        T& operator*() const {
            return *iter ;
        }
    private:
        T * iter ;
    } ;

    iterator begin() ;
    iterator end() ;
    void insert(iterator& iter,const T& value) ;
    void erease(iterator& iter) ;
    const T * data() const { return arr; }    
private:
    T * arr ;
    int size ;
    int capacity ;
};


template<typename T>
vector<T>::vector()
{
    size = 0 ;
    capacity = 1 ;
    arr = new T[1] ;
}

template<typename T>
vector<T>::vector(const std::initializer_list<T>& elems) {
    size = elems.size() ;
    capacity = size * 2 ;
    arr = new T[capacity] ;
    int i = 0 ;
    for(auto it = elems.begin() ; it != elems.end(); ++it, ++i) {
        arr[i] = *it ;
    }
}

template<typename T>
vector<T>::vector(int colum, T value)
{
    size = colum ;
    capacity = size * 2 ;
    arr = new T[capacity] ;
    for(int i = 0; i < size; i++) {
        arr[i] = value ;
    }
}

template<typename T>
vector<T>::~vector()
{
    delete[] arr;
}

template<typename T>
void vector<T>::push_back(const T& value) {
    if(capacity == size) {
        T *tmp = new T[capacity * 2] ;
        for(int i = 0; i < capacity; ++i) {
            tmp[i] = arr[i] ;
        }
        delete[] arr;
        arr = tmp;
        capacity *= 2;
        tmp = nullptr;
    }
    arr[size++] = value;
}

template<typename T>
void vector<T>::pop_back() {
    T *tmp = new T[capacity - 1] ;
    for(int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i] ;
    }
    delete [] arr ;
    arr = tmp ;
    capacity-- ;
    size-- ;
}

template<typename T>
vector<T>::vector(const vector & other) {
    this->size = other.size ;
    this->capacity = other.capacity ;
    this->arr = new T [other.capacity] ;
    for(int i = 0;i < size; i++) {
        this->arr[i] = other.arr[i] ;
    }
}

template<typename T>
vector<T>::vector(vector && other) {
    arr = other.arr ;
    this->size = other.size ;
    this->capacity = other.capacity ;
    other.arr = nullptr ;
    this->size = 0 ;
    this->capacity = 0 ;
}

template<typename T>
vector<T> & vector<T>::operator=(const vector & other){
    if(this == &other) {
        return * this ;
    }
    delete [] arr ;
    this->size = other.size ;
    this->capacity = other.capacity ;
    this->arr = new T [other.capacity] ;
    for(int i = 0;i < size; i++){
    
        this->arr[i] = other.arr[i] ;
    }
    return *this ;
}

template<typename T>
vector<T> & vector<T>::operator=(vector && other){
    if(this == &other) {
        return *this ;
    }
    delete[] arr ;
    this->size = other.size ;
    this->capacity = other.capacity ;
    this->arr = other.arr ;
    other.arr = nullptr;
    return *this ;
}

template<typename T>
T vector<T>::operator[](int index) {
    return *(arr+index) ;
}

template<typename T>
void vector<T>::shrink_to_fit() {
    capacity = size ;
}

template<typename T>
void vector<T>::insert(vector<T>::iterator& iter,const T& value) 
{
    if(size < capacity) {
        for(iterator i = this->end(); i != iter ; --i) {
            *i = *(i - 1);
        }
        *iter = value ;
    }
    else
    {
        capacity *= 2;
        T* tmp = new T [capacity];
        int j = 0 ;
        for(auto i = this->begin();i != iter ;++i )
        {
            tmp[j++] = *i ;
        }
        tmp[j] = value ;
        for(;iter != this->end(); ++iter)
        {
            tmp[++j] = *iter ;
        }
        delete[] arr ;
        arr = tmp ;
    }
    size++ ;
}

template<typename T>
void vector<T>::erease(vector<T>::iterator& iter) 
{
    T *tmp = new T[capacity];
    int i = 0 ;
    for(i = 0; i < size; i++) {
        if(arr[i] == *iter) {
            break ;
        } 
        tmp[i] = arr[i] ;
    }
    for(int j = i + 1;j < size; ++j) {
        tmp[i] = arr[j] ;
        i++ ;
    }
    delete [] arr ;
    arr = tmp ;
    tmp = nullptr ;
    size-- ;
}

template<typename T>
typename vector<T>::iterator vector<T>::begin() 
{
    vector<T>::iterator it(arr) ;
    return it ;
}

template<typename T>
typename vector<T>::iterator vector<T>::end() 
{
    vector<T>::iterator it(arr + size) ;
    return it ;
}
