#include "Vector.h"

#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix: public Vector<T>
{
    public:
        Matrix(int M, int N, T defval=0);
        Matrix(int M, int N, Vector<T>&);
        Matrix(int M, int N, int**);
        Matrix(Matrix<T>&);
        
        int* shape()                {return Dims;}
        void print();
        
        T at(int x, int y)  {return Vector<T>::Guts[y*Dims[0]+x];}
        T* atp(int x, int y) {return &Vector<T>::Guts[y*Dims[0]+x];}
        virtual bool dimsmatch(Matrix<T>&);
        void transpose();
        void set(int x, int y, T val) {Vector<T>::Guts[y*Dims[0]+x] = val;}
        void set(int x, Vector<T>);
        
              T* operator[](int);
        const T* operator[](int) const;
        
    private:
        int Dims[2];
};


#endif /* MATRIX_H */

