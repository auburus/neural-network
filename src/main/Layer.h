#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer
{
    public:
        std::vector<int> feedForward(std::vector<int> &in);
};

#endif
