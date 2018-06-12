#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
struct TreeNode{
    T value;
    struct TreeNode *less;
    struct TreeNode *more;
    struct TreeNode *parent;
};

#endif // TREENODE_H