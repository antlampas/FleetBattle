/*
Copyright 2018 Jan Wilmans

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), 
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <exception>  
#include <thread>  

#include <memory>
#include <mutex>

#ifndef MT_SHARED_PTR_HPP
#define MT_SHARED_PTR_HPP

template <typename T>
class mt_shared_ptr
{
    using ptr_t = std::shared_ptr<T>;
public:
    mt_shared_ptr() = default;
    mt_shared_ptr(const mt_shared_ptr& t) : ptr(t.share()) {}
    mt_shared_ptr(mt_shared_ptr&& other) : ptr(other.ptr)
    {
        other.ptr.reset();
    }

    mt_shared_ptr& operator=(const mt_shared_ptr& other)
    {
        if (this != &other)
        {
            ptr_t p = ptr;
            ptr_t q = other.share();
            std::lock_guard<std::mutex> lock(mutex);
            ptr = q;
        }
        return *this;
    }

    // no locking needed since moving implies the rhs is not accessed
    mt_shared_ptr& operator=(mt_shared_ptr&& other)
    {
        if (this != &other)
        {
            ptr = std::move(other.ptr);
        }
        return *this;
    }


    // we make sure we do not (possibly) run the destructor of the object that ptr references while holding the lock
    mt_shared_ptr & operator=(ptr_t p) // shared_ptr assignment
    {
        std::lock_guard<std::mutex> lock(mutex);
        ptr.swap(p);
        return *this;
    }

    mt_shared_ptr(const ptr_t& p) : ptr(p) {} // constructor taking a shared_ptr<T>

    
    ptr_t operator->() const
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (!ptr) throw std::runtime_error("mt_shared_ptr<> nullptr dereference");
        return ptr;
    }
    

    ptr_t share() const
    {
        std::lock_guard<std::mutex> lock(mutex);
        return ptr;
    }

    void reset()
    {
        ptr_t delayRelease;
        std::lock_guard<std::mutex> lock(mutex);
        delayRelease = ptr;
        ptr.reset();
    }

    void reset(ptr_t p)
    {
        std::lock_guard<std::mutex> lock(mutex);
        ptr.swap(p);
    }

private:
    mutable std::mutex mutex;
    ptr_t ptr;
};

#endif