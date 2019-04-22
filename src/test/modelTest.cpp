#include <catch.hpp>
#include <Model.h>
#include <vector>

TEST_CASE("Model should feedForward with no layers", "[model]" )
{
    Model model;
    std::vector<double> input {3, 5, 12, 8};
    std::vector<double> output = model.feedForward(input);


    REQUIRE (input == output);
}

TEST_CASE("Model with several layers")
{
    Model model;

}
