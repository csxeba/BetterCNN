#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int M, int N, T defval) :
        Vector<T>::Vector(M*N, defval)
{
    Dims[0] = M;
    Dims[1] = N;
}

template <typename T>
Matrix<T>::Matrix(int M, int N, Vector<T> &vec) :
        Vector<T>::Vector(vec)
{
    assert(vec.size()==M*N);
    Dims[0] = M;
    Dims[1] = N;
}

template <typename T>
Matrix<T>::Matrix(int M, int N, int** ar) :
        Vector<T>::Vector(M*N, ar[0])
{
    Dims[0] = M;
    Dims[1] = N;
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>& mat) :
        Vector<T>::Vector(mat)
{
    int* mshape = mat.shape();
    Dims[0] = mshape[0];
    Dims[1] = mshape[1];
}

template <typename T>
void Matrix<T>::print()
{
    for (int i=0; i<Dims[0]; i++) {
        for (int j=0; j<Dims[1]; j++) {
            std::cout << Vector<T>::Guts[i*Dims[0]+j] << ", ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool Matrix<T>::dimsmatch(Matrix<T>& mat)
{
    int* mshape = mat.shape();
    return (Dims[0]==mshape[0] and Dims[1]==mshape[1]);
}

template <typename T>
void Matrix<T>::transpose()
{
    int temp = Dims[0];
    Dims[0] = Dims[1];
    Dims[1] = temp;
}
template <typename T>
void Matrix<T>::set(int x, Vector<T> v)
{
    assert(v.size()==Dims[1]);
    for(int i=0;i<Dims[1];i++) {
        *atp(x)+i = v[i];
    }
}

template <typename T>
T* Matrix<T>::operator[](int y)
{
    return atp(y*Dims[0]);
}

template <typename T> const
T* Matrix<T>::operator[](int y) const
{
    return atp(y*Dims[0]);
}
