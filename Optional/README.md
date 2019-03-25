Optional<T> provides a mechanism to wrap another class with
not-set-yet semantics.  Common alternatives to Optional<T> include
heap+NULL or an explicit invalid sentinel value within the domain
of the variable.  Using the heap adds unnecessary complexity for
memory tracking, and a sentinel value isn't always a reasonable
alternative for the domain.

The state machine is:

         -> [[NOT SET]] <-- IsPresent()==false
         |      |
 Clear() |      | Set()
         |      |
         |      V
          ---[[SET]] <-- IsPresent()==true

[Template type T is should be copy constructable.]
