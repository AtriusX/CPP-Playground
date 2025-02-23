# ArrayList

This subproject is a test implementation of an array-based varying-size collection similar to `std::vector<T>`. This collection is comparable to its analog in Java: `ArrayList<T>`.

Implementing this in C++ compared to Java or other managed JVM languages posed a bit of a unique challenge as arrays in C++ do not have the same array length constructs that exist for arrays in Java. Additionally, these arrays must be explicitly assigned to pointer type `T*` in order to allow for variable length instantiation (necessary for reallocation as the list grows or shrinks).

C++ enforces the size of the array as part of the type of our class, meaning the only way around this is to allocate the array on the heap. For this example we're avoiding the use of smart pointers to learn how to manage our own memory. As such we will need to be careful to handle the internal array properly.

In this example, we utilize a few advanced features such as:

- Classes
- Templates
- Manual memory management (new/delete)
- Operator functions (==, !=)