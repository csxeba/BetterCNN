#include <vector>
#include <assert.h>
#include <iostream>
#include <cstring>

#include "ConvLayer.h"
#include "../utility/operations.h"
#include "../utility/activations.h"
#include "../utility/operations.h"

ConvLayer::ConvLayer(int filters, ivec inshape, ivec fshape, int stride,
                     ConvNet* net) :
    InShape(inshape), Stride(stride), Fshape(fshape)
{
    OutShape = outshape(InShape, Fshape, Stride, filters);
    Steps    = calcsteps(InShape, Fshape, Stride, filters);
            
    Excitations(OutShape[0], OutShape[1]*OutShape[2]);
    Activations(OutShape[0], OutShape[1]*OutShape[2]);
    Errors(OutShape[0], OutShape[1]*OutShape[2]);
    Filters(filters, InShape[0]*Fshape[0]*Fshape[1], 0.5);
    
    Brain = net;
}

void ConvLayer::think(dmatrix3 mat)
{
    dmatrix2 rfields(OutShape[1]*OutShape[2],Fshape[0]*Fshape[1]*InShape[0]);
    dmatrix2 output(OutShape[0], OutShape[1]*OutShape[2]);
    
    Inputs = &mat;
    
    for (int i=0; i<Steps.size(); i++) {
        //We get this 4-array by acquiring the pointer to its first element
        int* step = Steps.atp(i, 0);
        dmatrix3 rfld(slice<real>invert<real>(mat, step));
        //We get the first pointer of slab's data and write it into rfields.
        //The X dim of rfields is equal to the multiplicate of slab's dims.
        *rfields.atp(i, 0) = rfld.atp(0, 0, 0);
    }
    dgemm(rfields, Filters, Excitations);
    for(int x=0;x<Excitations.size();x++)
        *Activations.atp(x) = sigmoid(Excitations.at(x));
}

void ConvLayer::receive_error(dvec error)
{
    assert(error.size()==Errors.size());
    matops::overwrite(error, Errors);
}

void ConvLayer::backpropagation() const
{   
    dmatrix2 lasterr(OutShape[0], OutShape[1]*OutShape[2]);
    
    for (int x = 0; x < Errors.size(); x++) {
        for (int i = 0; i < 4; i++) {
            *(lasterr.atp(x) + i) = *(Excitations.atp(x) + i) * Errors.at(x)
        }
    }
}

void ConvLayer::weight_update()
{    
    
//    dmatrix2 holder(InShape[0], Fshape[0]*Fshape[1]);
//    for (int i = 0; i < InShape[0]; i++) {
//        dmatrix2 sheet(Inputs->atp(i));
//        for (int s = 0; s < Fshape[0]*Fshape[1]; s++) {
//            dmatrix2 slc(slice<real>(sheet, Twsteps.atp(s*Fshape[0]*Fshape[1])));
//            std::memcpy(holder.atp(i*holder.shape()[0]), slc.atp(0),
//                        sizeof(real)*Fshape[0]*Fshape[1]);
//        }
//    }
    
    int sh[] = {OutShape[0], InShape[0], Fshape[0], Fshape[1]}; //Filter 4D
    int step[4];
    dmatrix2 sheet(OutShape[1], OutShape[2]);
    
    for(int f=0;f<sh[0];f++) {
        for(int z=0;z<sh[1];z++) {
            for(int y=0;y<sh[2];y++) {
                for(int x=0;x<sh[3];x++) {
                    step[0] = x; step[1] = x + OutShape[2];
                    step[2] = y; step[3] = y + OutShape[1];
                    
                    dmatrix2 sheet(OutShape[1], OutShape[2],
                                   slice<real>(Inputs->at(z), step));
                    dmatrix2 error(OutShape[1], OutShape[2],
                                   Errors.atp(f, 0, 0));
                    
                    *Filters.atp(f*sh[0]+z*sh[1]+y*sh[2]+x) +=
                            matops::frobenius(Errors[f], sheet);
                }
            }
        }
    }
}

//dmatrix2 ConvLayer::convolve(dmatrix2 sheet, dmatrix2 kernel, imatrix2 steps)
//{   
//    dmatrix2 recfields(steps[0][1]-steps[0][0], steps[0][3]-steps[0][2]);
//    for (int s=0; s<Steps.shape()[0]; s++)
//        *recfields.atp(s) = matops::slice<real>(sheet, Steps.atp(s, 0)).point();
//
//    //dmatrix2 output(matops::frobenius(recfields, kernel));
//    return dmatrix2(matops::frobenius(recfields, kernel));
//}