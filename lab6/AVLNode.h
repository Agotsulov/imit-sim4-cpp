//
// Created by byzilio on 25.06.18.
//

#ifndef LAB6_AVLNODE_H
#define LAB6_AVLNODE_H

#include <string>

using namespace std;

struct AVLNode{
    string value;
    int count;

    int height;

    struct AVLNode *less;
    struct AVLNode *more;

};

#endif //LAB6_AVLNODE_H
