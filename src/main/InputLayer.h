#ifndef INPUTLAYER_H
#define INPUTLAYER_H

#include <Layer.h>

class InputLayer : public Layer
{
    int input_dimension_;

    public:
        InputLayer(int input_dimension) : input_dimension_(input_dimension)
        {} 

};

#endif
