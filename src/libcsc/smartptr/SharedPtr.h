#pragma once
#include <atomic>
#include <cstdio>

namespace libcsc {

template <typename T>
class SharedPtr {
private:
    T* ptr_ = nullptr;
    std::atomic<unsigned int>* count_ = nullptr;

public:
    T* get() const
    {
        return ptr_;
    }

    unsigned int use_count() const
    {
        return *count_;
    }

    void reset(T* ptr = nullptr)
    {
        if (count_ != nullptr && --*count_ == 0) {
            delete ptr_;
            delete count_;
        }
        ptr_ = ptr;

        count_ = new std::atomic<unsigned int>(1);
    }

    SharedPtr() : ptr_(nullptr), count_(nullptr)
    {
    }

    SharedPtr(T* other) : ptr_(other)
    {
        if (ptr_ == nullptr)
            return;
        count_ = new std::atomic<unsigned int>(1);
    }
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_)
    {
        if (ptr_ == nullptr)
            return;

        if (count_ != nullptr)
            ++*count_;
    }

    SharedPtr(SharedPtr&& other)
    {
        this->ptr_ = other.ptr_;
        this->count_ = other.count_;

        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    ~SharedPtr()
    {
        if (ptr_ == nullptr)
            return;
        if (--*count_ == 0) {
            delete ptr_;
            delete count_;
        }
    }

    T& operator*() const
    {
        return *ptr_;
    }

    T& operator->() const
    {
        return ptr_;
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        this->ptr_ = other.ptr_;
        this->count_ = other.count_;

        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other)
    {
        this->ptr_ = other.ptr_;
        this->count_ = other.count_;

        other.ptr_ = nullptr;
        other.count_ = nullptr;

        return *this;
    }
};

}