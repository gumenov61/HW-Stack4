//  "Copyright [2017] <Ovcharov Anisim>"
#ifndef DESKTOP_WORKSPACE_HOMEWORK_STACK_02_INCLUDE_STACK_HPP_
#define DESKTOP_WORKSPACE_HOMEWORK_STACK_02_INCLUDE_STACK_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
using std::string;
using std::cout;
using std::endl;

template <typename T>
class Stack {
 public:
    Stack() noexcept;
    explicit Stack(size_t s) noexcept;
    Stack(const Stack& u) noexcept;
    Stack(Stack&& u) noexcept;
    Stack(std::initializer_list<T> l) noexcept;
    size_t count() const noexcept;
    bool empty() const noexcept;
    void push(T const &) noexcept;
    T& top() const noexcept;
    void pop() noexcept;
    ~Stack() noexcept;

    void swap(Stack& u) noexcept;

    Stack<T>& operator=(const Stack& u) noexcept;
    Stack<T>& operator=(Stack&& u) noexcept;
    T& operator[](size_t x) const noexcept;

 private:
    T* array_;
    size_t array_size_;
    size_t count_;
};

//ВНЕШНЯЯ РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА STACK
template <typename T>
Stack<T>::Stack() noexcept : Stack(100) {}


// start - PART IV ###################################################
template <typename T>
Stack<T>::Stack(std::initializer_list<T> ls) noexcept : array_size_(ls.size()), array_(new T[ls.size()]), count_(ls.size()) {
    std::copy(ls.begin(), ls.end(), array_);
}
// end - PART IV #####################################################


template <typename T>
Stack<T>::Stack(size_t s) noexcept : array_size_(s), array_(new T[s]), count_(0) {}

template <typename T>
Stack<T>::Stack(const Stack& u) noexcept : array_(new T[u.array_size_]), array_size_(u.array_size_), count_(u.count_) {
    std::copy(u.array_, u.array_ + u.array_size_, array_);
}

template <typename T>
void Stack<T>::swap(Stack& u) noexcept {
    // Меняем значения переменных в объектах класса Stack
    std::swap((*this).array_, u.array_);
    std::swap((*this).array_size_, u.array_size_);
    std::swap((*this).count_, u.count_);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& u) noexcept {
    if(this != &u) {
        Stack(u) .swap(*this); // Вызываем конструктор копирования для временного объекта
        // Затем вызываем фуекцию swap у временного объекта и передаем в нее указатель на текущий объект
    }
    return *this;
}

template <typename T>
Stack<T>::Stack(Stack&& u) noexcept : array_(u.array_), array_size_(u.array_size_), count_(u.count_) {
    u.array_ = nullptr;
    u.array_size_ = 0;
    u.count_ = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& u) noexcept {
    if(this != &u) {
        Stack(std::move(u)) .swap(*this); // Вызываем конструктор перемещения для временного объекта
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() noexcept {
    delete[] array_;
}

template <typename T>
void Stack<T>::push(T const &val) noexcept {
    if (count_ == array_size_) {
        T* array_exp_ = new T[array_size_*2];
        for (int i = 0; i < array_size_; i++) {
            array_exp_[i] = array_[i];
        }
        array_size_ *= 2;
        delete[] array_;
        array_ = array_exp_;
    }
    array_[count_++] = val;
}

template <typename T>
void Stack<T>::pop() noexcept {
    if(count_ == 0) throw std::runtime_error("\tERROR:\tStack empty...");
    --count_;
}

template <typename T>
size_t Stack<T>::count() const noexcept {
    return count_;
}

template <typename T>
bool Stack<T>::empty() const noexcept {
    return count();
}

template <typename T>
T& Stack<T>::top() const noexcept {
    return array_[count_];
}

template <typename T>
T& Stack<T>::operator[](size_t x) const noexcept {
    return array_[x];
}

#endif  // DESKTOP_WORKSPACE_HOMEWORK_STACK_02_INCLUDE_STACK_HPP_"
