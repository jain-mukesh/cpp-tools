#include "Optional.hh"

template <class T>
Optional<T>::Optional()
  : mIsPresent(false)
{
}

template <class T>
Optional<T>::Optional(const T& value)
  : mIsPresent(false)
{
    SetValue(value);
}

template <class T>
Optional<T>::Optional(const Optional<T>& value)
  : mIsPresent(false)
{
    if (value.mIsPresent)
    {
        SetValue(value.GetValue());
    }
}

template <class T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
    if (this != &other)
    {
        if (other.mIsPresent)
        {
            SetValue(other.GetValue());
        }
        else
        {
            Clear();
        }
    }
    return *this;
}

template <class T>
Optional<T>::~Optional()
{
    Clear();
}

template <class T>
bool Optional<T>::IsPresent() const
{
    return mIsPresent;
}

template <class T>
T Optional<T>::GetValue() const
{
    return *(reinterpret_cast<const T*>(mValueBuffer));
}

template <class T>
void Optional<T>::SetValue(const T& newValue)
{
    Clear();
    T* val = reinterpret_cast<T*>(mValueBuffer);
    std::uninitialized_fill_n(val, 1, newValue);
    mIsPresent = true;
}

template <class T>
void Optional<T>::Clear()
{
    T* val = reinterpret_cast<T*>(mValueBuffer);
    if (mIsPresent)
    {
        // We must manually invoke the dtor here since we're storing T as raw bytes.
        (*val).~T();
    }
    mIsPresent = false;
}
