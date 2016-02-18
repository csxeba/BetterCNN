/*Please refer to the LICENSE.txt file in this project's root
  for copyright informations!*/
#ifndef FCLAYER_H
#define FCLAYER_H

#include <vector>

#include "../utility/generic.h"
#include "Layer.h"

class ConvNet; //Forward declare this baby

class FCLayer: public Layer
{
public:
    FCLayer(ivec inshape, int neurons, ConvNet*);
    void think(dvec&);

    void backpropagation();
    void weight_update(dvec);
    
    void reset();

    dvec     Activations;
    dvec     Excitations;
    dvec     Errors;
    ivec     OutShape;
    
    dmatrix2 Weights;
    dvec     Biases;
    
    ConvNet* Brain;
};

#endif /* FCLAYER_H */

