#include <cstddef>      // size_t
#include <algorithm>    //std::swap
#include "int_array.hpp"

// Конструктор класса IntArray
IntArray::IntArray(size_t size)
    : size_(size), data_(new int[size])
{
    for (size_t i = 0; i < size; ++i)
    {
        data_[i] = 0;
    }     
}

// Конструктор копирования
IntArray::IntArray(IntArray const &a)
    : size_(a.size_), data_(new int[size_])
{
    
    for (size_t i = 0; i != a.size_; ++i)
    {
        data_[i] = a.data_[i];
    }
}

// Деструктор
IntArray::~IntArray()
{
    delete[] data_;
}

// Оператор присваивания в соответствии с идиомой `copy-and-swap`
IntArray & IntArray::operator=(IntArray const &a)
{
    if (this != &a)
        IntArray(a).swap(*this);
    return *this;
}

// Перемещающий конструктор
IntArray::IntArray(IntArray &&a) : size_(a.size_), data_(a.data_) 
{
    a.size_ = 0;
    a.data_ = nullptr;
}

// Перемещающий оператор присваивания
IntArray& IntArray::operator=(IntArray&& a)
{
    if (this != &a)
    {
        delete[] data_;
        size_ = a.size_;
        data_ = a.data_;
        a.size_ = 0;
        a.data_ = nullptr;
    }
    return *this;
}

// Метод swap
void IntArray::swap(IntArray &a)
{
    std::swap(size_, a.size_);
    std::swap(data_, a.data_);
}

// Метод для получения информации о размере массива
size_t IntArray::size() const { return size_; }

// Метод для чтения элемента массива
int IntArray::get(size_t i) const { return data_[i]; }

// Метод для доступа к элементу массива по ссылке
int & IntArray::get(size_t i) { return data_[i]; }

// Метод для изменения размеров массива
void IntArray::resize(size_t nsize)
{
    // создаём конструктором новый объект класса требуемого размера
    IntArray t(nsize);
    size_t n = nsize > size_ ? size_ : nsize;
    for (size_t i = 0; i != n; ++i)
        t.data_[i] = data_[i];
    swap(t);
}
