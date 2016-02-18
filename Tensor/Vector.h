#ifndef VECTOR_H
#define VECTOR_H

#include "Tensor.h"

template <typename T>
class Vector : public Tensor<T>
{
    public:
        Vector(int N, T defval=0);
        Vector(int N, T*);
        Vector(std::initializer_list<T> l);
        Vector(Vector<T>&);
        //No need for Vector(Matrix&) and (Volume) and (HVolume),
        //because they are all subclasses of Vector and the above
        //Constructor has to be able to handle that case with size()!
        
        ~Vector()               {delete Guts;}

        virtual T* point()      {return Guts;}
        virtual int* shape()    {return &Size;}
        virtual int size()      {return Size;}       
        virtual T at(int x)     {return Guts[x];}
        virtual T* atp(int x)   {return &Guts[x];}
        virtual void set(int x, T val) {Guts[x] = val;}
        
              T& operator[](int x)           {return Guts[x];}
        const T& operator[](int x) const     {return Guts[x];}
        
        virtual void print();        
        
    protected:
        T*  Guts;
        int Size;
};


#endif /* VECTOR_H */

