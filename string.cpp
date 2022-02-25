#include "string.h"

unsigned int Utility::my_strlen(const char *s)
{
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}

String::String()
{
    size = 0;
    capacity = 16;
}

String::String(int size)
{
    this->size = size;
    capacity = 16;
}

char* String::cstr() {
    return buffer;
}

String::String(unsigned int sizee, char ch)
{
    buffer = new char(sizee+1);
    size = sizee;
    if(size < 16) {
        capacity = 16;
    }
    else {
        capacity = size + 16;
    }
    for(int i = 0; i < sizee; ++i){
        buffer[i] = ch;
    }
    buffer[sizee] = '\0';
}

String::String(const char* arr)
{
    buffer = new char(Utility::my_strlen(arr)+1);
    this->size = Utility::my_strlen(arr);
    if(size < 16) {
        capacity = 16;
    }
    else {
        capacity = size + 16;
    }
    for(int i = 0; i < Utility::my_strlen(arr); ++i) {
        buffer[i] = arr[i];
    }
    buffer[size] = '\0';
}

String::String(const String & obj)
{
    this->size = obj.size;
    this->capacity = obj.capacity;
    this->buffer = new char(obj.size);
    for(int i = 0; i < obj.size; ++i) {
        this->buffer[i] = obj.buffer[i];
    }
}

String::String(String && ob)
{
    this->size = ob.size;
    this->capacity = ob.capacity;
    this->buffer = ob.buffer;
    ob.buffer = nullptr;
    ob.size = 0;
}

String& String::operator=(String&& obj)
{
    this->size=obj.size;
    delete[] this->buffer;
    this->buffer = obj.buffer;
    this->capacity = obj.capacity;
    obj.buffer = nullptr;
    return *this;
}

String& String::operator=(const String& obj)
{
    if(this == &obj){
        return *this;
    }
    if(this->size > 1) {
        delete[] this->buffer;
    }
    else if(this->size == 1) {
        delete this->buffer;
    }
    this->size = obj.size;
    this->capacity = obj.capacity;
    this->buffer = new char(obj.size);
    for(int i = 0; i < obj.size; ++i){
        this->buffer[i] = obj.buffer[i];
    }
    return *this;
}

String String::operator+(const String & robj) const
{
    String tmp;
    int tmpp = this->size + robj.size;
    tmp.size = tmpp;
    tmp.buffer = new char(tmp.size);
    tmp.capacity = tmp.size + 16;
    for(int i = 0; i < this->size; ++i) {
        tmp.buffer[i] = this->buffer[i];
    }   
    for(int i = this->size; i < tmp.size; ++i){
        tmp.buffer[i] = robj.buffer[i-(this->size)];
    }
    return tmp;
}

String String::operator+(const char* symbols) 
{
    String tmp;
    int tmpp = this->size+Utility::my_strlen(symbols);
    tmp.size = tmpp;
    tmp.buffer = new char (tmp.size);
    this->capacity = tmp.size + 16;
    for(int i=0;i<this->size;++i){
        tmp.buffer[i]=this->buffer[i];
    }
    for(int i = this->size; i < tmp.size; ++i){
        tmp.buffer[i] = symbols[i-(this->size)];
    }  
    return tmp;
}

String String::operator+(const char ch)
{
    push_back(ch);
    return *this;
}

String& String::operator+=(const String & robj)
{
    *this = *this + robj;
    return *this;
}

bool String::operator>(const String & robj) const
{
    if(this->size>robj.size){
        return true;
    }
    else {
        return false;
    }
}

bool String::operator<(const String & robj) const
{
    if(this->size<robj.size){
        return true;
    }
    else {
        return false;
    }
}

bool String::operator==(const String &rhs) const
{
    if(this->size!=rhs.size){
        return false;
    }
    for(int i =0; i<this->size;++i){
        if(this->buffer[i]!=rhs.buffer[i]){
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String &rhs) const
{
    return !(*this==rhs);
}

bool String::operator>=(const String & rhs) const
{
    if(this->size>=rhs.size){
        return true;
    }
    else {
        return false;  
    }  
}

bool String::operator<=(const String & rhs) const
{
    if(this->size<=rhs.size){
        return true;
    }
    else {
        return false;  
    }  
}

char& String::operator[](const unsigned index)
{
    return this->buffer[index];
}

const char& String::operator[](const unsigned index) const
{
    return this->buffer[index];
}

void String::push_back(char symbol)
{
    if(this->size != this->capacity) {
        buffer[size] = symbol;
        ++size;
        buffer[size] = '\0';
    }
    String tmp(*this);
    if(this->size != 0 && this->size == this->capacity) {
        this->capacity *= 1.8;
        delete[] buffer;
        buffer = new char(capacity);
        for(int i = 0; i < tmp.size; ++i) {
            buffer[i] = tmp.buffer[i];
        }
        buffer[size] = symbol;
        buffer[size+1] = '\0';
        ++size;
    }
}

char String::pop_back()
{
    if(size >= 1) {
        --size;
        buffer[size] = '\0';
    }
    return '\0';
}

void String::push_front(char symbol)
{
    String tmp;
    tmp.buffer = new char(this->size+1);
    tmp.buffer[0] = symbol;
    for(int i=1; i < this->size+1; ++i){
        tmp.buffer[i] = this->buffer[i-1];
    }
    delete[] this->buffer;
    this->size++;
    this->buffer = tmp.buffer;
    tmp.buffer = nullptr;
}

char String::pop_front()
{
    char tmpp = this->buffer[0];
    erase(0);
    return tmpp;
}

void String::resize(const int count,char symbol)
{
    for(int i=0;i < count; ++i) {
        *this=*this+symbol;
    }
}

char String::erase(const int index)
{
    char syml = this->buffer[index];
    String tmp;
    tmp.size = this->size-1;
    tmp.buffer = new char(tmp.size);
    for(int i=0; i < tmp.size; ){
        if(i == index){
            for(int j=i; j < tmp.size; ++j){
                tmp.buffer[j] = this->buffer[i+1];
                ++i;
            }
            break;
        }
        else {
            tmp.buffer[i] = this->buffer[i];
            ++i;
        }
    }
    delete[] this->buffer;
    this->buffer = tmp.buffer;
    this->size = tmp.size;
    tmp.buffer = nullptr;
    return syml;
}

String& String::erase(const int index,int count)
{
    if(count>this->size){
        std::cout<<"Error";
        exit(0);
    }
    while(count){
        erase(index);
        count--;
    }
    return *this;
}

int String::find(const char ch) const
{
    for(int i = 0; i < this->size; ++i) {
        if(this->buffer[i]==ch){
            return i;
        }
    }
    return -1;
}

int String::find(const String obj) const
{
    int tmp;
    int counter{};
    for(int i = 0; i < this->size; ++i) {
        counter = 0;
       if(this->buffer[i] == obj.buffer[0]) {
           tmp = i;
           i++;           
           for(int j = 1; j < obj.size; ++j) {
                if(this->buffer[i] != obj.buffer[j]) {
                   break;
                }
                counter++;
                i++;
            }
            if(counter == obj.size-1) {
                return tmp;
            }
            --i;
        }
    }
    return -1;
}

int String::find(const char * arr)const
{
    int tmp;
    int counter {};
        for(int i = 0; i < this->size; ++i) {
        counter = 0;
            if(this->buffer[i] == arr[0]) {
                tmp = i;
                i++;  
                for(int j = 1; j < Utility::my_strlen(arr); ++j) {
                    if(this->buffer[i] != arr[j]) {
                    break;
                }
                counter++;
                i++;
            }
            if(counter == Utility::my_strlen(arr)-1){
                return tmp;
            }
            --i;
        }
    }
    return -1;
}
    
void String::insert(const int index, char symbol)
{
    if(index>this->size){
        std::cout<<"ERROR";
        exit(0);
    }
    int counter{};
    for(int i = index; i < this->size; ++i){
        counter++;
    }
    String tmp(*this);
    tmp.erase(index, counter);
    tmp = tmp + symbol;
    counter = 0;
    for(int i = 0; i < index; ++i) {
        counter++;
    }
    String tmp1(*this);
    tmp1.erase(0, counter);
    tmp += tmp1;
    delete[] this->buffer;
    this->buffer = tmp.buffer;
    tmp.buffer = nullptr;
    delete[] tmp1.buffer;
    tmp1.buffer = nullptr;
    this->size++;
}

void String::insert(const int index,int count,char symbol)
{
    if(index > this->size){
        std::cout << "ERROR";
        exit(0);
    }
    while(count){
        this->insert(index, symbol);
        count--;
    }
}

void String::insert(const int index,const String & obj)
{
    if(index > this->size){
        std::cout<<"ERROR";
        exit(0);
    }
    int tmpsize = this->size+obj.size;
    int counter{};
    for(int i = index; i < this->size; ++i) {
        counter++;
    }
    String tmp(*this);
    tmp.erase(index, counter);
    tmp += obj;
    counter = 0;
    for(int i = 0; i < index; ++i) {
        counter++;
    }
    String tmp1(*this);
    tmp1.erase(0, counter);
    tmp += tmp1;    
    delete[] this->buffer;
    this->buffer = tmp.buffer;
    tmp.buffer = nullptr;
    delete[] tmp1.buffer;
    tmp1.buffer = nullptr;
    this->size = tmpsize;    
}

void String::insert(const int index, const char* symbols)
{
    if(index > this->size){
        std::cout << "ERROR";
        exit(0);
    }
    int tmpsize = this-> size + Utility::my_strlen(symbols);
    int counter{};
    for(int i = index; i < this->size; ++i) {
        counter++;
    }
    String tmp(*this);
    tmp.erase(index, counter);
    tmp = tmp + symbols;
    counter = 0;
    for(int i = 0; i < index; ++i) {
        counter++;
    }
    String tmp1(*this);
    tmp1.erase(0, counter);
    tmp += tmp1;
    delete[] this->buffer;
    this->buffer = tmp.buffer;
    tmp.buffer = nullptr;
    delete[] tmp1.buffer;
    tmp1.buffer = nullptr;
    this->size = tmpsize;
}

void String::clear()
{
    size = 0;
    buffer[size] = '\0';
}

bool String::empty()
{
    if(this->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

void String::replace(char ch , int index)
{
    this->insert(index, ch);
    this->erase(index + 1);
}

void String::replace(int index , const char* arr)
{
    int tmpsize = this->size;
    int counter = Utility::my_strlen(arr);
    this->insert(index, arr);
    while(counter) {
        this->erase(index + Utility::my_strlen(arr));
        --counter;
    }
}

String String::substr(int start,int end) const
{
    int counter {};
    if(start < 0 || start > this->size) {
        std::cout << "Error";
        exit(0);
    }
    if(end < 0 || end > this->size) {
        std::cout<<"Error";
        exit(0);
    }
    String tmp(*this);
    for(int i = 0; i < this->size; ++i) {
        if(i == start) {
            break;
        }
        ++counter;                      
    }
    int countertmp = counter;
    while(counter){
        tmp.pop_front();
        counter--;
    }
    end -= countertmp;
    countertmp = tmp.size-end;
    while(countertmp){
        tmp.pop_back();
        countertmp--;
    }
    return tmp;
}

std::ostream& operator<<(std::ostream &out, const String &ob)
{
    out<<ob.buffer<<'\0';
    return out;
}

std::istream& operator>>(std::istream &in, String &ob)
{
    char temp[String::LIM];
    in.get(temp,String::LIM);
    if(in){
        ob=temp;
    }
    while(in && in.get() != '\n'){
        continue;
    }
    return in;
}

char& String::at(const unsigned index)
{
    if(index<0 || index>this->size){
        std::cout<<"ERROR";
        exit(0);
    }
    return this->buffer[index];
}

const char& String::at(const unsigned index) const 
{
    if(index<0 || index>this->size){
        std::cout<<"ERROR";
        exit(0);
    }
    return this->buffer[index];
}

String::~String()
{
    if(capacity > 1) {
        delete[] buffer;
    }
    else if(capacity == 1) {
        delete buffer;
    }
}