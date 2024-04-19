#ifndef MYSHAREDPTR_H
#define MYSHAREDPTR_H

template <typename T>
class MySharedPtr {
  
public:
    // Constructor
    MySharedPtr(T* p = nullptr) : m_ptr(p), m_counter(new size_t(1)){}

    // Copy constructor
    MySharedPtr(const MySharedPtr<T> &other) : m_ptr(other.m_ptr), m_counter(other.m_counter){
        ++(*m_counter);
    }

    // Copy assignment operator
    MySharedPtr<T>& operator=(const MySharedPtr<T> &other) {
        if (this != &other) { 
            --(*m_counter);
            if (*m_counter == 0) {
                delete m_ptr;
                delete m_counter;
            }
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            ++(*m_counter);
        }
        return *this;
    }

    // Move constructor
    MySharedPtr(MySharedPtr<T>&& other) noexcept : m_ptr(other.m_ptr), m_counter(other.m_counter) {
    other.m_ptr = nullptr; 
    other.m_counter = nullptr; 
    }

    // Move assignment operator
    MySharedPtr<T>& operator=(MySharedPtr<T>&& other) noexcept {
        if (this != &other) {
            --(*m_counter);
            if (*m_counter == 0) {
                delete m_ptr;
                delete m_counter;
            }
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            other.m_ptr = nullptr;
            other.m_counter = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MySharedPtr() {
        if(--(*m_counter) == 0) {
            delete m_ptr;
            delete m_counter;
        }
    }

    int get_count() {
        return *m_counter;
    }

    T* get(){
        return m_ptr;
    }
    
    // Object access operators
    T& operator*() const {
        if (m_ptr == nullptr) {
            throw std::runtime_error("Dereferencing a nullptr");
        }
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

    // bool operator overload 
    explicit operator bool() const {
        return m_ptr != nullptr;
    }

 private:
    T* m_ptr;
    size_t* m_counter ;
};

#endif // MYSHAREDPTR_H


