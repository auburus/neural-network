#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

#include <Layer.h>
#include <string>

class HiddenLayer : public Layer
{
    int n_nodes_;

    public:
        HiddenLayer(int n_nodes, string activation_function_name)
            : n_nodes_(n_nodes), activation_function_name_(activation_function_name)
        {}
};

#endif
