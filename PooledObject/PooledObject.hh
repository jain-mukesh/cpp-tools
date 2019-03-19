#ifndef PooledObject_hh
#define PooledObject_hh

#include <cstddef>
#include <list>

template <class T>
class PooledObject
{
  private:
    static std::list<T*> mObjectList;

  public:
    static void Create(int num_objects);
    void* operator new(size_t size);
    void operator delete(void* object);
};

#endif // PooledObject_hh
