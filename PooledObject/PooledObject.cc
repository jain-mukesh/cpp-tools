#include "PooledObject.hh"

using namespace std;

template <class T>
std::list<T*> PooledObject<T>::mObjectList;

template <class T>
void PooledObject<T>::Create(int num_objects)
{
    for (int i = 0; i < num_objects; ++i)
    {
        T* val = static_cast<T*>(::operator new(sizeof(T)));
        mObjectList.push_back(val);
    }
}

template <class T>
void* PooledObject<T>::operator new(size_t size)
{
    T* val = NULL;
    if (!mObjectList.empty())
    {
        val = mObjectList.front();
        mObjectList.pop_front();
    }
    else
    {
        val = static_cast<T*>(::operator new(sizeof(T)));
    }
    return val;
}

template <class T>
void PooledObject<T>::operator delete(void* object)
{
    mObjectList.push_back(reinterpret_cast<T*>(object));
}
