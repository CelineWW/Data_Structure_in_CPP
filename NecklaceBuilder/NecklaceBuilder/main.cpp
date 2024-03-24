/*
 *
 * Celine Wang
 *
 * Chapter 18, Programming NecklacBuilder with BeadList class
 *
 * Mar 2024
 *
 */

#include <iostream>
#include "BeadList.h"
using namespace std;

int main() {
    // Define a BeadList object
    string beads[4] = {"turquoise", "coral", "gold", "copper"};
    BeadList necklace;
    necklace.appendNode("coral");
    necklace.displayNode();
    return 0;
}


