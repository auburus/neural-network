#include <Model.h>

using namespace std;

void Model::addLayer(shared_ptr<Layer> layer)
{
    layers_.push_back(layer);
}

vector<double> Model::feedForward(vector<double> const& input)
{
    vector<double> output = input;

    for(auto& layer: layers_)
    {
        output = layer->feedForward(output);
    }

    return output;
}
