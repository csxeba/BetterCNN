#include <vector>
#include <numeric>
#include <algorithm>
#include <assert.h>

#include "FCLayer.h"
#include "../netdef/ConvNet.h"
#include "../utility/operations.h"
#include "../routines.h"

FCLayer::FCLayer(ivec inshape, int neurons, ConvNet* net) :
        OutShape(1, neurons),
        Biases(neurons, 0.5),
        Errors(neurons),
        Excitations(neurons),
        Activations(neurons)
{
    int inputs=1;
    
    for(int i=0;i<inshape.size();i++) {
        inputs *= inshape[i];
    }
    Weights(neurons, inputs, 0.5);
    
    Brain = net;
}

void FCLayer::think(dvec &stimuli)
{
    assert(stimuli.size() == Weights.shape()[0]);
    //TODO: check dims!
    dgemv(stimuli, Excitations, Weights, 1.0, 0.0);
    daxpy(Biases, Excitations);
    for(int x=0;x<OutShape[0];x++)
        Activations[x] = sigmoid(Excitations[x]);
    
    /* IS THIS REAL LIFE??
    for(int y=0;y<Weights.size();y++) {
        *Excitations.atp(y) = ddot(Weights.atp(y), stimuli) + Biases[y];
        *Activations.atp(y) = sigmoid(Excitations[y]);
    }
    */
}

void FCLayer::reset(void)
{
    dvec vec(Weights.size(), 0.5);
    
    dscal(Weights, 0.0);
    daxpy(vec, Weights);
}

dvec FCLayer::backpropagation()
{
    //Calculating the errors of the previous layer!
    dmatrix2 weightT = matops::transpose<real>(Weights);
    dvec output(weightT.size());

    for(int x=0;x<weightT.size();x++) {
		throw 1; //This is faulty. prevLayer exc should be used!
        output[x] = (sigmoid_p(Excitations[x]) *
                    (dot<real>(weightT[x], Errors)));
    }
    return output;
    printm(output);
}

void FCLayer::weight_update(dvec prevOutput)
{
    assert(prevOutput.size()==Weights[0].size());
    for(int i=0;i<Weights.size();i++){
        for(int j=0;j<Weights[0].size();j++) {
            // I might be wrong about this! I only did this in 2D.
            Weights[i][j] += Brain->Eta * Errors[i] * prevOutput[j];
            Biases[i] += Brain->Eta * Errors[i];
            // This means that the matrix of deltas is actually the
            // Outer product of the Error and previous output vectors.
        }
    }
}
