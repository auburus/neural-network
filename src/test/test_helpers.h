#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#define CHECK_VEC_EQUAL(v1, v2) \
    if (v1.size() != v2.size()) { \
        REQUIRE(v1 == v2); \
    } \
    for (size_t i = 0; i < v1.size(); i++) { \
        if (v1[i] != Approx(v2[i])) { \
            REQUIRE(v1 == v2); \
        } \
    } \
    REQUIRE(1 == 1);
    

#endif
