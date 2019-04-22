#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <string>
#include <functional>

using namespace std;

class Layer
{
    public:
        vector<double> feedForward(vector<double> const& in);

        void setWeights(vector<vector<double>>& weights); 

    protected:
        vector<vector<double>> weights_;
        string activation_function_name_ = "const";

        function<double (double)> getActivationFunction();
};

class InputLayer : public Layer
{
    public:
        InputLayer(size_t input_dimension);
};

#endif
