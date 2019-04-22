#include <catch.hpp>
#include <Model.h>
#include <vector>

TEST_CASE("Model should feedForward with no layers", "[model]" )
{
    Model model;
    std::vector<int> input {3, 5, 12, 8};
    std::vector<int> output = model.feedForward(input);


    REQUIRE (input == output);

}
