#pragma once

#include <list>
#include <utility>

namespace libcsc {

template <typename T>
class myList {
private:
    struct node {
        T data_;
        node* next_;

        node(const T& data, node* next = nullptr) : data_(data), next_(next)
        {
        }
        node(T&& data, node* next = nullptr)
            : data_(std::move(data)), next_(next)
        {
        }
    };
    node* head_ = nullptr;
    node* tail_ = nullptr;
    int size_ = 0;
    bool is_looped = false;

public:
    ~myList();

    node* operator[](int index)
    {
        node* result = head_;
        for (int i = 0; i < index; i++) {
            result = result->next_;
        }
        return result;
    }
    class iterator {
    private:
        node* ptr_ = nullptr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using differenece_type = std::ptrdiff_t;
        using value_type = node;
        using pointer = node*;
        using reference = node&;

        iterator(node* node) : ptr_(node)
        {
        }
        T& operator*() const
        {
            return ptr_->data_;
        }

        node* operator->() const
        {
            return ptr_;
        }

        iterator& operator++()
        {
            if (ptr_ == nullptr)
                return *this;
            ptr_ = ptr_->next_;
            return *this;
        }

        iterator operator++(T)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator& operator+(int a)
        {
            for (int i = 0; i < a; i++) {
                (*this)++;
            }
            return *this;
        }

        iterator& operator+=(int a)
        {
            *this = *this + a;
            return *this;
        }

        friend bool operator==(const iterator& a, const iterator& b)
        {
            if (a.ptr_ == nullptr && b.ptr_ == nullptr)
                return true;
            if (a.ptr_ == nullptr || b.ptr_ == nullptr)
                return false;
            return (a.ptr_->data_ == b.ptr_->data_);
        };
        friend bool operator!=(const iterator& a, const iterator& b)
        {
            if (a.ptr_ == nullptr && b.ptr_ == nullptr)
                return false;
            if (a.ptr_ == nullptr || b.ptr_ == nullptr)
                return true;
            return (a.ptr_->data_ != b.ptr_->data_);
        };
    };
    iterator begin() const
    {
        return iterator(head_);
    };
    iterator end() const
    {
        return iterator(tail_->next_);
    };

    bool is_empty()
    {
        return (size_ == 0) ? 1 : 0;
    }

    void push_front(const T& data);
    void push_front(T&& data);

    void push_back(const T& data);
    void push_back(T&& data);

    void pop_back()
    {
        if (size_ == 0)
            return;
        node* tmp = head_;
        while (tmp->next_ != tail_)
            tmp = tmp->next_;
        delete tail_;
        tail_ = tmp;
    }

    void pop_front()
    {
        if (size_ == 0)
            return;
        node* tmp = head_;
        head_ = head_->next_;
        delete tmp;
    }

    void make_loop(int index);
    bool is_loop()
    {
        return is_looped;
    }

    bool check_loop()
    {
        iterator rabbit = this->begin();
        iterator turtle = this->begin();
        do {
            rabbit += 2;
            turtle += 1;
            if (rabbit == this->end() && turtle == this->end())
                return false;
        } while (rabbit != turtle);
        return true;
    }
};

template <typename T>
myList<T>::~myList()
{
    if (size_ == 0)
        return;
    node* tmp;
    tail_->next_ = nullptr;
    while (head_) {
        tmp = head_;
        head_ = head_->next_;
        delete tmp;
    }
}

template <typename T>
void myList<T>::push_front(const T& data)
{
    node* newHead = new node(data, this->head_);
    if (size_ == 0) {
        head_ = newHead;
        tail_ = newHead;
        ++size_;
        return;
    }
    head_ = newHead;
    ++size_;
}

template <typename T>
void myList<T>::push_front(T&& data)
{
    node* newHead = new node(data, this->head_);
    if (size_ == 0) {
        head_ = newHead;
        tail_ = newHead;
        ++size_;
        return;
    }
    head_ = newHead;
    ++size_;
}

template <typename T>
void myList<T>::push_back(const T& data)
{
    node* newTail = new node(data);
    if (size_ == 0) {
        head_ = newTail;
        tail_ = newTail;
        ++size_;
        return;
    }
    is_looped = false;
    tail_->next_ = newTail;
    tail_ = newTail;
    ++size_;
}

template <typename T>
void myList<T>::push_back(T&& data)
{
    node* newTail = new node(data);
    if (size_ == 0) {
        head_ = newTail;
        tail_ = newTail;
        ++size_;
        return;
    }
    is_looped = false;
    tail_->next_ = newTail;
    tail_ = newTail;
    ++size_;
}

template <typename T>
void myList<T>::make_loop(int index)
{
    if (index > size_)
        return;
    tail_->next_ = this->operator[](index);
    is_looped = true;
}
}
