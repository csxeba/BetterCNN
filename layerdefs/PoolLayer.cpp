#include <vector>
#include <iostream>
#include <algorithm>

#include "PoolLayer.h"
#include "../utility/operations.h"

// class constructor
PoolLayer::PoolLayer(ivec inshape, ConvNet* net) :
    Fshape({2, 2}),
    InShape(inshape),
    Excitations(inshape[0], inshape[1], inshape[2])
{   
    Stride   = 2;
    
    OutShape = outshape(InShape, Fshape, Stride, 0);
    Steps    = calcsteps(InShape, Fshape, Stride, 0);
    
    Activations(OutShape[0], OutShape[1], OutShape[2]);
    Errors(OutShape[0], OutShape[1], OutShape[2]);
    Brain = net;
}

// Sets attributes to zero before a new phase of learning
inline void PoolLayer::reset()
{
    Excitations(InShape[0], InShape[1], InShape[2]);
}

// Feedforward
void PoolLayer::think(dmatrix3 &mat)
{
    ThoughtBubble bubble;
    int index=0;
    dvec activationVec(OutShape[0]*OutShape[1]*OutShape[2]);
    
    reset();
    
    for(int z=0;z<mat.size();z++) {
        for(int i=0;i<Steps.size();i++, index++) {
            imatrix2 exc(Fshape[0], Fshape[1]);
            int* step(Steps.atp(i));
            bubble = max_pool(slice<real>(mat[z], step));
            activationVec[index] = bubble.activation;
            exc = fold2<int>(bubble.excitation, Fshape);
            apply_exc(exc, step, z);
        }
    }
    *Activations.point() = activationVec;
    return Activations;
}

void PoolLayer::apply_exc(imatrix2 &exc, int* step, int z)
{
    int i=0;
    for(int ey=step[2];ey<step[3];ey++, i++) {
        int j=0;
        for(int ex=step[0];ex<step[1];ex++, j++)
            *Excitations.atp(z,ey,ex) += exc.atp(i,j);
    }
}

ThoughtBubble PoolLayer::max_pool(dmatrix2 slice) const
{
    dvec fslice(4);
    ivec bslice(4, 0);
    double maxi;
    ThoughtBubble output;
    
    maxi = *std::max_element(slice.point(), slice.point()+slice.size());
    bslice[*std::find(slice.point(), slice.point()+slice.size(), maxi)] = 1;
    
    output.excitation = bslice;
    output.activation = maxi;
    return output;
}

dmatrix3 PoolLayer::backpropagation() const
{
    dmatrix3 outputs(OutShape[0], OutShape[1], OutShape[2]);
    int* step;
    int index;
    
    for(int z=0;z<InShape[0];z++) {
        index = 0;
        for(int y=0;y<InShape[1];y++) {
            for(int x=0;x<InShape[2];x++, index++) {
                step = Steps.atp(index);
                for(int i=step[0];i<step[1];i++) {
                    for(int j=step[2];j<step[3];j++) {
                        outputs[z][i][j] +=
                                Excitations[z][i][j] *
                                Errors[z][y][x];
                                // * d/dx(activation), which is 1 in this case
                    }
                }
            }
        }
    }
    return outputs;
}