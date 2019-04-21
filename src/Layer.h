#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer
{
    public:
        std::vector<double> feedForward(std::vector<double> &in);
};

#endif
