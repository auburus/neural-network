#include <Layer.h>
#include <stdexcept>

using namespace std;

/**
  Computes this expression: f(W * in + b)
  Where
    - f is the activation function
    - W is the weights matrix
    - v is the input vector
    - b is the bias vector

  For convenience, `b` is considered the last column of `W`, so `W` has one
  more column than necessary (it technically doesn't match);

   (       | b1 ) ( in1 )   ( out1 )
   (   W   | b2 ) ( in2 ) = ( out2 )
   (       | b3 ) ( in3 )   ( out3 )

    Warning: This method DOES NOT check that the dimensions match.
    TODO: It probably should.
*/
vector<double> Layer::feedForward(vector<double> const& in)
{
    vector<double> out(weights_.size(), 0); 
    auto activation_function = getActivationFunction();

    for (size_t i = 0; i < out.size(); i++)
    {
        for (size_t j = 0; j < in.size(); j++)
        {
            out[i] += weights_[i][j] * in[j];
        }

        // Add the last column, b
        out[i] += weights_[i][in.size()];


        out[i] = activation_function(out[i]);
    }

    return out;
}

function<double (double)> Layer::getActivationFunction()
{
    if (activation_function_name_ == "const")
    {
        return [](double x) -> double { return x; };
    }

    throw invalid_argument("Function " + activation_function_name_ +
            " is not a valid activation function name");

}

void Layer::setWeights(vector<vector<double>>& weights)
{
    weights_ = weights;
}

InputLayer::InputLayer(size_t input_size)
{
    weights_ = vector<vector<double>> 
        (input_size, vector<double> (input_size + 1, 0));

    for (size_t i = 0; i < input_size; i++)
    {
        weights_[i][i] = 1;
    }
}

HiddenLayer(size_t n_nodes, string activation_function_name)
    : n_nodes_(n_nodes), activation_function_name_(activation_function_name)
{}
