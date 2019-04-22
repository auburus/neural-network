#include <Model.h>

void Model::addLayer(std::shared_ptr<Layer> layer)
{
    layers.push_back(layer);
}

std::vector<int> Model::feedForward(std::vector<int> const& input)
{
    std::vector<int> output = input;

    for(auto& layer: layers)
    {
        output = layer->feedForward(output);
    }

    return output;
}
