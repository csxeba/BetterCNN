#ifndef VOLUME_H
#define VOLUME_H

#include "Vector.h"
#include "Matrix.h"

template <typename T>
class Volume: public Vector<T>
{
    public:
        Volume(int M, int N, int O, T defval=0);
        Volume(int M, int N, int O, Vector<T>&);
        Volume(Volume<T>&);

        int* shape()        {return Dims;}
        void print();
        
        T at(int x,int y,int z)
            {return Vector<T>::Guts[z*Dims[0]+y*Dims[1]+x];}
        T* atp(int x,int y,int z)
            {return &Vector<T>::Guts[z*Dims[0]+y*Dims[1]+x];}
        bool dimsmatch(Volume<T>&);
        void invert();
        void set(int x, int y, int z, T val)
            {Vector<T>::Guts[z*Dims[0]+y*Dims[1]+x] = val;}
        
              T* operator[](int x);
        const T* operator[](int x) const;
        
    private:
        int Dims[3];
};

#endif /* VOLUME_H */

