#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>
#include <iostream>  

using namespace std;

template <typename T>
class BinaryTree{
    public:
        BinaryTree(T value);
        
        void insert(T value, vector<bool> code);
        
        void clear();

        void removeLeafs();

        int size();

        bool checkBinaryTree(T expect_min, T expect_max); //пробегать и проверять что в конце максимальное и начале наименьшее

        TreeNode<T>* min(TreeNode<T> *s);
        TreeNode<T>* max(TreeNode<T> *s);

        vector<bool> search(T value);

        ostream& operator<<(ostream& out);

        ~BinaryTree();
    private:
        void insert(TreeNode<T> *x, TreeNode<T> *z);
    protected:
        TreeNode<T> *root;
        int count;
};


template <typename T>
BinaryTree<T>::BinaryTree(T value){
    root = new TreeNode<T>;
    root->less = 0x0;
    root->more = 0x0;
    root->parent = 0x0;
    root->value = value;
    count = 0;
}

template <typename T>
void BinaryTree<T>::insert(T value, vector<bool> code){
    TreeNode<T> *curr = root;
    TreeNode<T> *prev = root->parent;
    for(int i = 0;i < code.size();i++){
        if(curr == 0x0){
            if(i < (code.size() - 1))
                throw "Неверный код";
            else 
                break;
        } 
        if(code[i] == 0){
            prev = curr->parent;
            curr = curr->less;
        } else {
            prev = curr->parent;
            curr = curr->more;
        }
    }

    if(prev == 0x0) 
        prev = root;

    if(curr == 0x0) {
        curr = new TreeNode<T>;
        curr->value = value;
        curr->less = 0x0;
        curr->more = 0x0;
        curr->parent = prev;
        if(code[code.size() - 1] == 1){
            prev->more = curr;
        } else {
            prev->less = curr;
        }
    } else {
        TreeNode<T> *new_node = new TreeNode<T>;
        new_node->value = value;
        new_node->less = 0x0;
        new_node->more = 0x0;
        new_node->parent = prev;
        insert(curr, new_node);
    }
}

template<typename T>
void BinaryTree<T>::insert(TreeNode<T> *x, TreeNode<T> *z){
    while(x != 0x0){
        if(z->value > x->value){
            if( x->more != 0x0){
                x = x->more;
            } else {
                z->parent = x;
                x->more = z;
                break;
            } 
        } else if(z->value < x->value){
            if( x->less != 0x0){
                x = x->less;
            } else {
                z->parent = x;
                x->less = z;
                break;
            } 
        }
    }
}

template<typename T>
void BinaryTree<T>::removeLeafs(){

}

template<typename T>
bool BinaryTree<T>::checkBinaryTree(T expect_min, T expect_max){
    if((min(root)->value == expect_min) 
            && (max(root)->value == expect_max))
        return true;
    return false;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::min(TreeNode<T> *s){
    if(s->less == 0x0)
        return s;
    return min(s->less);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::max(TreeNode<T> *s){
    if(s->more == 0x0)
        return s;
    return max(s->more);
}


template<typename T>
void BinaryTree<T>::clear(){
    
}

template <typename T>
int BinaryTree<T>::size(){
    return count;
}

template <typename T>
ostream& BinaryTree<T>::operator<<(ostream& out)  
{  
    out << "LALAALALLAALLA" << endl;
    return out; 
} 

  

template <typename T>
BinaryTree<T>::~BinaryTree(){
    
};


#endif // BINARYTREE_H