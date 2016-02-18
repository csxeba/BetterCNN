/*Please refer to the LICENSE.txt file in this project's root
  for copyright informations!*/
#ifndef CONVLAYER_H
#define CONVLAYER_H

#include "Layer.h"

class ConvNet;

class ConvLayer: public Layer
{
public:
    
    dmatrix2 Excitations;
    dmatrix2 Activations;
    dmatrix2 Errors;
    ivec     InShape;
    ivec     OutShape;    
    dmatrix2 Filters;
    
    ConvLayer(int filters, ivec inshape, ivec fshape, int stride, ConvNet*);
    
    void think(dmatrix3 mat);
    void receive_error(dvec error);
    void set_twsteps();
    void backpropagation();
    void weight_update(dmatrix3* inputs);

    dmatrix3* Inputs;    
    ivec      Fshape;
    imatrix2  Steps;
    int       Stride;

    ConvNet*  Brain;

//    dmatrix2 convolve(dmatrix2, dmatrix2 kernel);
//    dmatrix2 convolve(dmatrix3, dmatrix3 kernel);
};



#endif /* CONVLAYER_H */

