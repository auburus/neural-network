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
  more column and one more row:

   (       | b1 ) ( in1 )   ( out1 )
   (   W   | b2 ) ( in2 ) = ( out2 )
   (       | b3 ) ( in3 )   ( out3 )
   ( 0 0 0 | 1  ) (  1  )   (   1  )

   The Model class already sets up everything so W and in are in the "expanded" form.

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
