#pragma once

namespace libcsc {

template <typename T>
class UniquePtr {
private:
    T* ptr_;

public:
    T* get() const
    {
        return ptr_;
    }

    void reset(T* ptr = nullptr)
    {
        delete ptr_;
        this->ptr_ = ptr;
    }

    UniquePtr(T* other = nullptr) : ptr_(other)
    {
    }

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other)
    {
        this->ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    ~UniquePtr()
    {
        delete ptr_;
    }

    UniquePtr& operator=(const UniquePtr& other) = delete;
    UniquePtr& operator=(UniquePtr&& other)
    {
        this->ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    T& operator*() const
    {
        return *ptr_;
    }

    T& operator->() const
    {
        return ptr_;
    }
};
}