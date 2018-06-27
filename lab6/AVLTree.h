//
// Created by byzilio on 25.06.18.
//

#ifndef LAB6_AVLTREE_H
#define LAB6_AVLTREE_H



#include "AVLNode.h"
#include <iostream>
#include <algorithm>

using namespace std;

class AVLTree{
public:
    AVLTree(string value);

    AVLTree(AVLTree &other);

    AVLTree(AVLTree &&other);

    void insert(string value);

    int size();

    void clear();

    AVLNode* min(AVLNode *s); //Самый левый
    AVLNode* max(AVLNode *s); //Самый правый

    void remove(string value);

    int search(string value);

    ostream& operator<<(ostream& out);

    AVLTree& operator=(AVLTree &other);
    AVLTree& operator=(AVLTree &&other);

    ~AVLTree();
private:
    void free(AVLNode *n);

    AVLNode* searchTreeNode(string value);
    AVLNode* searchTreeNode(AVLNode *n,string value);

    int search(AVLNode *n,string value);
    AVLNode* dub(AVLNode *n);
    AVLNode* remove(AVLNode *n,string value);
    AVLNode* insert(AVLNode *x,string value);
    void show(AVLNode *n,ostream& out, int l);
    void show(int *tab_count, AVLNode *n,ostream& out);

    int getHeight(AVLNode *n);
    int balanceFactor(AVLNode *n);
    void fixHeight(AVLNode *n);

    AVLNode* rotateRight(AVLNode *n);
    AVLNode* rotateLeft(AVLNode *n);
    
    AVLNode* balance(AVLNode *n);

    AVLNode* removeMin(AVLNode *n);
protected:
    AVLNode *root;
    int count;
};


#endif //LAB6_AVLTREE_H
