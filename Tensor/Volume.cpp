#include "Volume.h"

template <typename T>
Volume<T>::Volume(int M, int N, int O, T defval) :
        Vector<T>::Vector(M*N*O, defval)
{
    Dims[0] = M;
    Dims[1] = N;
    Dims[2] = O;
}

template <typename T>
Volume<T>::Volume(int M, int N, int O, Vector<T> &vec) :
        Vector<T>::Vector(M*N*O, vec)
{
    Dims[0] = M;
    Dims[1] = N;
    Dims[2] = O;
}

template <typename T>
void Volume<T>::print()
{
    for (int i=0; i<Dims[0]; i++) {
        for (int j=0; j<Dims[1]; j++) {
            for (int k = 0; k < Dims[2]; k++) {
                std::cout << Vector<T>::Guts[i*Dims[0]+j*Dims[1]+k] << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
}

template <typename T>
bool Volume<T>::dimsmatch(Volume<T>& vol)
{
    int* vshape = vol.shape();
    return (Dims[0]==vshape[0] and Dims[1]==vshape[1] and Dims[2]==vshape[2]);
}

template <typename T>
void Volume<T>::invert()
{
    int temp = Dims[0];
    Dims[0] = Dims[2];
    Dims[2] = temp;
}

template <typename T>
T* Volume<T>::operator[](int x)
{
    return atp(x);
}

template <typename T> const
T* Volume<T>::operator[](int x) const
{
    return atp(x);
}
