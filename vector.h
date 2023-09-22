#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector
{
public:
    Vector();
    void Assign(Vector<T> const & newVector);
    T& At(int const position);
    T& Back();
    int Capacity();
    void Clear();
    bool Empty();
    T& Front();
    void Insert(int const position, T const value);
    void Insert(int const position, T const * values[]);
    void Erase(int const position);
    void Erase(int const start, int const end);
    T PopBack();
    void PushBack(T const & value);
    void PushFront(T const & value);
    int Size();


private:
    int capacity;
    int size;
    T internalArr[];
};

#endif // VECTOR_H
