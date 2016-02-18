#include <cstring>

#include "Vector.h"

template <typename T>
Vector<T>::Vector(int N, T defval)
{
    Size = N;
    Guts = new T[Size];
    for(int x=0;x<Size;x++) {
        Guts[x] = defval;
    }
}

template <typename T>
Vector<T>::Vector(int N, T* ar)
{
    Size = N;
    Guts = new T[Size];
    std::memcpy(Guts, ar, sizeof(ar));
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> l)
{
    Size = l.size();
    Guts = new T[Size];
    int i=0;
    for(auto x=l.begin();x!=l.end();x++, i++) {
        Guts[i] = *x;
    }
}

template <typename T>
Vector<T>::Vector(Vector<T> &v)
{
    Size = v.Size;
    Guts = new T[Size];
    int i=0;
    for(int x=0;x<Size;x++) {
        Guts[i] = v.at(x);
    }
}

template <typename T>
void Vector<T>::print() 
{
    for (int i=0; i<Size; i++) {
        std::cout << Guts[i] << ", " << std::endl;
    }
}

// Vector declarations end
