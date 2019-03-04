#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/Tree.h"
#include "../includes/NodeWithList.h"

// Definition for testing
#ifdef TEST_SW
    #include "../includes/mainTest.h"
#endif

using namespace std;



int main_main(int argc, char **argv) {
    std::cout << "Normal execution!" << endl;
    return 0;
}
int main(int argc, char **argv) {
    int r;
    #ifdef TEST_SW
        r = mainTest(argc, argv);
    #else
        r = main_main(argc, argv);
    #endif
    return r;
}