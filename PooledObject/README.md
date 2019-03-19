A PooledObject<> is a mechanism to form a pool of objects of any class
with any semantic. The PooledObject is domain free and removes unnecessary
complexity when your application does a lot of lot of memory allocation and
deallocation
No changes are necessary to the derived classes to form a pool of it objects.

Use on class Example:
class Example : public PooledObject<Example> {};

This is not thread-safe implementation. The derived class needs to take care of that
