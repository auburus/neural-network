#include <Model.h>

void Model::addLayer(Layer layer)
{
    layers.push_back(layer);
}

std::vector<double> Model::feedForward(std::vector<double> &input)
{
    std::vector<double> output = input;

    for(Layer& layer: layers)
    {
        output = layer.feedForward(output);
    }

    return output;
}
