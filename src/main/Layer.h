#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <string>
#include <functional>

using namespace std;

/**
  Class that represents each of the Layers in the neural network.

  This class should probably never be created directly, but always use
  one of its children.
*/
class Layer
{
    public:
        /**
          Takes an input vector and returns the output of this layer
        */
        vector<double> feedForward(vector<double> const& in);

        /**
          Setter for the layer weights (W|b)
        */
        void setWeights(vector<vector<double>>& weights); 

    protected:
        vector<vector<double>> weights_;
        string activation_function_name_ = "const";

        /**
          Gets the lambda that corresponds to the activation function name
        */
        function<double (double)> getActivationFunction();
};


/**
  First layer in a model.

  Handles the transition from the vector of data into whatever is required for the network.
*/
class InputLayer : public Layer
{
    public:
        InputLayer(size_t input_dimension);
};


/**
  Hidden layer of the model.

  Its constructor takes the number of nodes this hidden layer has, and its activation
  function.
*/
class HiddenLayer : public Layer
{
    size_t n_nodes_;

    public:
        HiddenLayer(size_t n_nodes, string activation_function_name);
}

#endif
