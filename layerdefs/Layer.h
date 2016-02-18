#ifndef LAYER_H
#define LAYER_H

#include "../utility/generic.h"

class Layer
{
public:
    Layer(){}
    Layer(int position) {Position = position;}
    virtual ~Layer(){}
    virtual void receive_error(dvec error) = 0;
    virtual void backpropagation() = 0;
    
    int Position;
};

#endif /* LAYER_H */

