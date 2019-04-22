#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <string>
#include <functional>

using namespace std;

class Layer
{
    vector<vector<double>> weights_;
    string activation_function_name_ = "const";

    public:
        vector<double> feedForward(vector<double> const& in);

        void setWeights(vector<vector<double>>& weights); 

    protected:
        function<double (double)> getActivationFunction();
};

#endif
