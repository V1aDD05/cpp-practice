// Заголовочный файл защищён от повторного включения при помощи `include guards`.
#ifndef INT_ARR_CLS
#define INT_ARR_CLS

#include <cstddef>  //size_t

    struct IntArray{
    // Конструктор класса IntArray
    explicit IntArray(size_t size = 0);

    // Конструктор копирования
    IntArray(IntArray const &a);

    // Деструктор
    ~IntArray();

    // Оператор присваивания
    IntArray &operator=(IntArray const &a);

    // Перемещающий конструктор
    IntArray(IntArray &&a);

    // Перемещающий оператор присваивания
    IntArray& operator=(IntArray &&a);

    // Метод swap
    void swap(IntArray &a);

    // Метод для получения информации о размере массива
    size_t size() const;

    // Метод для чтения элемента массива
    int get(size_t i) const;

    // Метод для доступа к элементу массива по ссылке
    int &get(size_t i);

    // Метод для изменения размеров массива
    void resize(size_t nsize);

private:
    size_t size_;
    int *data_;
};

#endif