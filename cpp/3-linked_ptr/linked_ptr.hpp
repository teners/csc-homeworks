#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/** declarations */
namespace smart_ptr
{
    namespace details
    {
        using nullptr_t = decltype(nullptr);        // null pointer type

        class base_linked_ptr
        {
        public:
            /* data */
            mutable base_linked_ptr const* prev;
            mutable base_linked_ptr const* next;

        public:
            /* constructors */
            constexpr base_linked_ptr() :           // default ctor
                    prev(nullptr),
                    next(nullptr)
            {}

            virtual ~base_linked_ptr();             // destructor

            /* functions */
            void insert(base_linked_ptr const& rhs);

            void swap(base_linked_ptr & other) noexcept;
        };

    } // namespace details

    template <class T>
    class linked_ptr : private details::base_linked_ptr
    {
    private:
        T * data;

    public:
        /* constructors and so on */
        constexpr linked_ptr() noexcept;                // default ctor

        constexpr linked_ptr(details::nullptr_t) :
                linked_ptr() {}                         // ctor from null pointer

        explicit linked_ptr(T * rhs);                   // ctor from pointer

        // not pretty sure how to implement this outside the class, so let it be here at least for now :)
        template <class U,
                class = typename std::enable_if<std::is_convertible<U*, T*>::value>::type>
        linked_ptr(U * rhs) : data(rhs) { }             // ctor from convertible type

        linked_ptr(linked_ptr<T> const& rhs);           // copy ctor

        template <class U,
                class = typename std::enable_if<std::is_convertible<U*, T*>::value>::type>
        linked_ptr(linked_ptr<U> const& rhs) :          // copy from convertible type ctor
                data(rhs.get())
        {
            insert((details::base_linked_ptr&)rhs);
        }

        /* TODO: implement
        linked_ptr(linked_ptr<T> && rhs) = delete;

        template <class U>
        linked_ptr(linked_ptr<U> && rhs) = delete;
        */

        ~linked_ptr();

        /* functions */
        void reset() noexcept;

        void reset(T * rhs);

        template <class U> void reset(U * rhs);

        T * get() const noexcept;

        bool unique() const noexcept ;

        void swap(linked_ptr<T> & rhs) noexcept;

        /* operators */
        linked_ptr & operator=(linked_ptr const& rhs) noexcept;     // copy assignment operator

        template <class U,
                class = typename std::enable_if<std::is_convertible<U*, T*>::value>::type>
        linked_ptr & operator=(linked_ptr<U> const& rhs) noexcept   // copy assignment from convertible type operator
        {
            linked_ptr<T> temp(rhs);
            swap(temp);
            return *this;
        }

        /* TODO: implement
        linked_ptr & operator=(linked_ptr<T> && rhs) = delete;

        template <class U>
        linked_ptr & operator=(linked_ptr<U> && rhs) = delete;
        */

        T & operator*() const noexcept;

        T * operator->() const noexcept;

        explicit operator bool() const noexcept;
    };

    void details::base_linked_ptr::insert(base_linked_ptr const& rhs)
    {
        next           = rhs.next;
        prev           = &rhs;
        if (rhs.next)
        {
            rhs.next->prev = this;
        }
        rhs.next       = this;
    }

    void details::base_linked_ptr::swap(base_linked_ptr & other) noexcept
    {
        std::swap(prev, other.prev);
        std::swap(next, other.next);
    }

    details::base_linked_ptr::~base_linked_ptr() noexcept
    {
        if (prev)
        {
            prev->next = next;
        }
        if (next)
        {
            next->prev = prev;
        }
    }

    template <class T>
    constexpr linked_ptr<T>::linked_ptr() noexcept :
            data(nullptr)
    {}

    template <class T>
    linked_ptr<T>::linked_ptr(T * rhs) :
            data(rhs)
    {
        static_assert(sizeof(T), "Incomplete type");
    }

    template <class T>
    linked_ptr<T>::linked_ptr(linked_ptr<T> const& rhs) :
            data(rhs.get())
    {
        insert((details::base_linked_ptr&)rhs);
    }

    template <class T>
    linked_ptr<T>::~linked_ptr()
    {
        if (next == nullptr
            && prev == nullptr)
        {
            delete data;
        }
    }

    template <class T>
    void linked_ptr<T>::reset() noexcept
    {
        if (next == prev
            && next == this)
        {
            delete data;
        }
        if (next != nullptr)
        {
            next->prev = prev;
            prev->next = next;
        }
        next       = nullptr;
        prev       = nullptr;
        data       = nullptr;
    }

    template <class T>
    void linked_ptr<T>::reset(T * rhs)
    {
        static_assert(sizeof(T), "Incomplete type");

        linked_ptr<T> temp(rhs);
        swap(temp);
    }

    template <class T>
    T * linked_ptr<T>::get() const noexcept
    {
        return data;
    }

    template <class T>
    bool linked_ptr<T>::unique() const noexcept
    {
        return (next == nullptr
                && prev == nullptr
                && data != nullptr);
    }

    template <class T>
    void linked_ptr<T>::swap(linked_ptr<T> & rhs) noexcept
    {
        std::swap(data, rhs.data);
        details::base_linked_ptr::swap(rhs);
    }

    template <class T>
    T & linked_ptr<T>::operator*() const noexcept
    {
        return *get();
    }

    template <class T>
    T * linked_ptr<T>::operator->() const noexcept
    {
        return get();
    }

    template <class T>
    linked_ptr<T>::operator bool() const noexcept
    {
        return data != nullptr;
    }

    template <class T>
    linked_ptr<T> & linked_ptr<T>::operator=(linked_ptr<T> const& rhs) noexcept
    {
        if (&rhs != this)
        {
            linked_ptr<T> temp(rhs);
            swap(temp);
        }
        return *this;
    }

    template<class T, class U>
    inline bool operator==(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return lhs.get() == rhs.get();
    }

    template<class T>
    inline bool operator==(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() == nullptr;
    }

    template<class T>
    inline bool operator==(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() == nullptr;
    }

    template<class T, class U>
    inline bool operator!=(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return lhs.get() != rhs.get();
    }

    template<class T>
    inline bool operator!=(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() != nullptr;
    }

    template<class T>
    inline bool operator!=(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() != nullptr;
    }

    template<class T, class U>
    inline bool operator<(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return rhs.get() < lhs.get();
    }

    template<class T>
    inline bool operator<(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() < nullptr;
    }

    template<class T>
    inline bool operator<(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() < nullptr;
    }

    template<class T, class U>
    inline bool operator>(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return lhs.get() > rhs.get();
    }

    template<class T>
    inline bool operator>(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() > nullptr;
    }

    template<class T>
    inline bool operator>(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() > nullptr;
    }

    template<class T, class U>
    inline bool operator>=(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return lhs.get() >= rhs.get();
    }

    template<class T>
    inline bool operator>=(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() >= nullptr;
    }

    template<class T>
    inline bool operator>=(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() >= nullptr;
    }

    template<class T, class U>
    inline bool operator<=(linked_ptr<T> const& lhs, linked_ptr<U> const& rhs) noexcept
    {
        return lhs.get() <= rhs.get();
    }

    template<class T>
    inline bool operator<=(linked_ptr<T> const& lhs, details::nullptr_t) noexcept
    {
        return lhs.get() <= nullptr;
    }

    template<class T>
    inline bool operator<=(details::nullptr_t, linked_ptr<T> const& rhs) noexcept
    {
        return rhs.get() <= nullptr;
    }

    template<class T>
    inline void swap(linked_ptr<T> & lhs, linked_ptr<T> & rhs) noexcept
    {
        lhs.swap(rhs);
    }

} // namespace smart_ptr
