#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using namespace std;

struct TreeNode{
    string value;
    int count;
    struct TreeNode *less;
    struct TreeNode *more;
    struct TreeNode *parent;
};

#endif // TREENODE_H