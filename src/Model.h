#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <vector>
#include <Layer.h>

class Model
{

    std::list<Layer> layers = {};

    public:
        void addLayer(Layer layer);

        std::vector<double> feedForward(std::vector<double> &input);
};

#endif
