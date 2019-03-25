#include <memory>  // uninitialized_fill_n()
#include <stdint.h>

template <class T>
class Optional
{
  public:

    /**
     * Default construct the T member variable and initialize the
     * Optional<T> status to NOT SET (i.e. IsPresent() is false).
     */
    Optional();

    /**
     * Copy construct the T member variable from value *but*
     * initialize the Optional<T> status to SET (IsPresent() is true).
     */
    Optional(const T& value);

    Optional(const Optional<T>& value);

    Optional<T>& operator=(const Optional<T>&);

    ~Optional();

    /**
     * @return true iff the wrapped value is currently set
     */
    bool IsPresent() const;

    /**
     * Provide access to the underlying value, iff it has been Set().
     * Provider should check the presence first before calling
     * @return a copy of the wrapped value
     */
    T GetValue() const;

    /**
     * Set the wrapped member variable to a specific value and change
     * the Optional<> state to SET (ie. IsPresent() == true).
     * @param newValue to use
     */
    void SetValue(const T& newValue);

    /**
     * Change the Optional<T> state to NOT SET.
     */
    void Clear();

  private:
    // mIsPresent is true if mValueBuffer contains a constructed, valid object
    uint8_t mValueBuffer[sizeof(T)];
    bool mIsPresent;
};
