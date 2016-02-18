#include <cstring>

#include "HVolume.h"

template <typename T>
HVolume<T>::HVolume(int M, int N, int O, int P, T defval) :
        Vector<T>::Vector(M*N*O*P, defval)
{
    Dims[0] = M;
    Dims[1] = N;
    Dims[2] = O;
    Dims[3] = P;
}

template <typename T>
HVolume<T>::HVolume(int M, int N, int O, int P, Vector<T> &vec) :
        Vector<T>::Vector(M*N*O*P, vec)
{
    Dims[0] = M;
    Dims[1] = N;
    Dims[2] = O;
    Dims[3] = P;
}

template <typename T>
bool HVolume<T>::dimsmatch(HVolume<T>& hvol)
{
    int* hvshape = hvol.shape();
    return (Dims[0]==hvshape[0] and Dims[1]==hvshape[1] and
            Dims[2]==hvshape[2] and Dims[3]==hvshape[3]);
}

template <typename T>
T* HVolume<T>::operator[](int x)
{
    Volume<T> output(Dims[1], Dims[2], Dims[3], Vector<T>::Guts[x]);
    return output;
}

template <typename T> const
T* HVolume<T>::operator[](int x) const
{
    Volume<T> output(Dims[1], Dims[2], Dims[3], Vector<T>::Guts[x]);
    return output;
}
