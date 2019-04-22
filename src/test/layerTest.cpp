#include <catch.hpp>
#include "test_helpers.h"
#include <Layer.h>
#include <vector>

using namespace std;

TEST_CASE("Layer feedforward with simple matrix and const", "[layer]")
{
    Layer layer;

    vector<vector<double>> weights(3, vector<double>(3));
    weights[0][0] = 1;
    weights[0][1] = 0;
    weights[0][2] = 0;
    weights[1][0] = 0;
    weights[1][1] = 1;
    weights[1][2] = 0;
    weights[2][0] = 0;
    weights[2][1] = 1;
    weights[2][2] = 0;

    layer.setWeights(weights);

    vector<double> input = { 3.5, 8};

    vector<double> output = layer.feedForward(input);
    vector<double> expected = {3.5, 8, 8};

    REQUIRE (expected == output);

}

TEST_CASE("Layer feedforward with random values", "[layer]")
{
    Layer layer;

    vector<vector<double>> weights(3, vector<double>(3));
    weights[0][0] = 0.82646749;
    weights[0][1] = 0.85609177;
    weights[0][2] = 0.66722571;
    weights[1][0] = 0.45935878;
    weights[1][1] = 0.10522651;
    weights[1][2] = 0.49464279;
    weights[2][0] = 0.28895577;
    weights[2][1] = 0.30294085;
    weights[2][2] = 0.31773362;
    layer.setWeights(weights);

    vector<double> input = {0.44054758, 0.04722904};

    vector<double> output = layer.feedForward(input);
    vector<double> expected = {1.07175636, 0.70198194, 0.45933999};

    CHECK_VEC_EQUAL(expected, output);
}

TEST_CASE("Test input layer creation and feedforward", "[layer]")
{
    InputLayer layer {2};

    vector<double> input {3,5};

    vector<double> output = layer.feedForward(input);

    CHECK_VEC_EQUAL(input, output);

}
