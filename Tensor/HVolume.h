#ifndef HVOLUME_H
#define HVOLUME_H

#include "Vector.h"
#include "Volume.h"

template <typename T>
class HVolume: public Vector<T>
{
    public:
        HVolume(int M, int N, int O, int P, T defval=0);
        HVolume(int M, int N, int O, int P, Vector<T>&);
        HVolume(HVolume<T>&);

        int* shape()        {return Dims;}
        void print();
        
        T at(int x,int y, int z, int f)
            {return Vector<T>::Guts[f*Dims[0]+z*Dims[1]+y*Dims[2]+x];}
        T* atp(int x, int y, int z, int f)
            {return &Vector<T>::Guts[f*Dims[0]+z*Dims[1]+y*Dims[2]+x];}
        bool dimsmatch(HVolume<T>&);
        void set(int x, int y, int z, int f, T val)
            {Vector<T>::Guts[f*Dims[0]+z*Dims[1]+y*Dims[2]+x] = val;}
        
              T* operator[](int x);
        const T* operator[](int x) const;
        
    private:
        int Dims[4];
};

#endif /* HVOLUME_H */

