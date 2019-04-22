#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <vector>
#include <memory>
#include <Layer.h>

using namespace std;

class Model
{

    list<shared_ptr<Layer>> layers_ = {};

    public:
        void addLayer(shared_ptr<Layer> layer);

        vector<double> feedForward(vector<double> const& input);
};

#endif
