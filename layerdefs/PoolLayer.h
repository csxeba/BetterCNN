/*Please refer to the LICENSE.txt file in this project's root
  for copyright informations!*/
#ifndef LAYERS_H
#define LAYERS_H

#include <vector>

#include "../utility/generic.h"
#include "Layer.h"

class ConvNet; //Forward declare this baby

struct ThoughtBubble
{
    ivec    excitation;
    double  activation;
};

class PoolLayer: public Layer
{
public:
    imatrix3 Excitations;
    dmatrix3 Activations;
    dmatrix3 Errors;
    ivec     OutShape;
    ivec     InShape;
    
    PoolLayer(ivec, ConvNet*);
    void think(dmatrix3&);
    void backpropagation();
    void weight_update(){}
    
    int      Stride;
    int*     Fshape; //filter shape
    imatrix2 Steps;
    
    ThoughtBubble max_pool(dmatrix2) const;
    void reset();
    void apply_exc(imatrix2&, int*, int);
    
    ConvNet* Brain;
};

#endif	// LAYERS_H