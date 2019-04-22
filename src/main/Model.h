#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <vector>
#include <memory>
#include <Layer.h>

class Model
{

    std::list<std::shared_ptr<Layer>> layers = {};

    public:
        void addLayer(std::shared_ptr<Layer> layer);

        std::vector<int> feedForward(const std::vector<int> &input);
};

#endif
