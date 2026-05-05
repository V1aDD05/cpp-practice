
template<typename T>
class ScopedPtr
{
public:

    // конструктор
    explicit ScopedPtr(T* ptr = nullptr) : ptr_(ptr) {}

    // деструктор
    ~ScopedPtr()
    {
        delete ptr_;
    }

    //запрет копирования
    ScopedPtr(const ScopedPtr&) = delete;
    ScopedPtr& operator=(const ScopedPtr&) = delete;   

    // СЕМАНТИКА ПЕРЕМЕЩЕНИЯ
    // перемещающий конструктор
    ScopedPtr(ScopedPtr&& oldScope) : ptr_(oldScope.release()) {}

    // перемещающий оператор присваивания
    ScopedPtr& operator=(ScopedPtr&& oldScope)
    {
        //проверка на самоприсваивание
        if (this != &oldScope)
        {
            reset(oldScope.release());
        }

        return *this;
    }

    //  МЕТОДЫ

    // метод, возвращающий сырой указатель
    T* get() const
    {
        return ptr_; // передача по значению (копии)
    }

    //метод, передающий владение сырым указателем
    T* release()
    {
        T* oldPtr = ptr_;
        ptr_ = nullptr;
        return oldPtr;
    }

    //метод заставляет ScopedPtr освободить старый указатель, а вместо него захватить новый
    void reset(T* ptr = nullptr)
    {
        if (ptr != ptr_) 
        {
            // удалили из памяти объект, на который указывал указатель
            delete ptr_;
            // записали в поле новый указатель
            ptr_ = ptr;
        }
        
    }

    //операторы, обеспечивающие доступ к объекту
    T& operator*() const
    {
        return *ptr_;
    }

    T* operator->() const
    {
        return ptr_;
    }

private:
    T* ptr_;
};