/**
 * It is necessary to use googletest to run tests.
 */

#include <gtest/gtest.h>

#if defined(BUILD_MONOLITHIC)
#define main    dtl_test_main
#endif

int main (int argc, const char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
