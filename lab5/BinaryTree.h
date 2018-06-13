#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>
#include <iostream>  
#include <algorithm>

using namespace std;

template <typename T>
class BinaryTree{
    public:
        BinaryTree(T value);
        
        BinaryTree(BinaryTree<T> &other);

        BinaryTree(BinaryTree<T> &&other);

        void insert(T value, vector<bool> code);

        void removeLeafs();

        int size();

        bool allPositive();

        int countEven();

        void clear();

        T arithmeticalMean();

        void show(ostream& out);

        bool checkBinaryTree(T expect_min, T expect_max); //пробегать и проверять что в конце максимальное и начале наименьшее

        TreeNode<T>* min(TreeNode<T> *s);
        TreeNode<T>* max(TreeNode<T> *s);

        vector<bool> search(T value);

        ostream& operator<<(ostream& out);

        BinaryTree<T>& operator=(BinaryTree<T> &other);    
        BinaryTree<T>& operator=(BinaryTree<T> &&other);    
    
        ~BinaryTree();
    private:
        void free(TreeNode<T> *n);
        bool search(T value, TreeNode<T> *n,vector<bool> *code);
        T sum(TreeNode<T> *n);
        TreeNode<T>* dublicate(TreeNode<T> *n);
        int countEven(TreeNode<T> *n);
        void removeLeafs(TreeNode<T> *n);
        bool positive(TreeNode<T> *n);
        void show(TreeNode<T> *n,ostream& out, int l);
        void show(int *tab_count, TreeNode<T> *n,ostream& out);
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
BinaryTree<T>::BinaryTree(BinaryTree<T> &other){
    root = new TreeNode<T>;
    root->parent = 0x0;
    root = dublicate(other.root);
    count = other.count;
}


template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &&other){
    root = new TreeNode<T>;
    root->parent = 0x0;
    root = dublicate(other.root);
    count = other.count;
    other.clear();
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> &other){
    BinaryTree<T> copy(other);
} 

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> &&other){
    BinaryTree<T> copy(move(other));
}       
    

template <typename T>
TreeNode<T>* BinaryTree<T>::dublicate(TreeNode<T> *n){
    if (n == 0x0){
		return 0x0;
	}
	TreeNode<T> *c = new TreeNode<T>;
    c->value = n->value;
    c->parent = n->parent;
	c->less = dublicate(n->less);
	c->more = dublicate(n->more);
    return c;
}



template <typename T>
void BinaryTree<T>::insert(T value, vector<bool> code){
    TreeNode<T> *new_node = new TreeNode<T>;
    new_node->value = value;
    new_node->less = 0x0;
    new_node->more = 0x0;
    new_node->parent = 0x0;
    
    TreeNode<T> *curr = root;
    for(int i = 0;i < code.size();i++){
        if(curr == 0x0)
            throw "Неверный код";
        
        if(code[i] == 1){
            if( curr->more != 0x0){
                curr = curr->more;
            } else {
                new_node->parent = curr;
                curr->more = new_node;
                break;
            } 
        } else if(code[i] == 0){
            if( curr->less != 0x0){
                curr = curr->less;
            } else {
                new_node->parent = curr;
                curr->less = new_node;
                break;
            } 
        }
    }
    count++;   
}


template<typename T>
void BinaryTree<T>::removeLeafs(){
    removeLeafs(root);
}

template<typename T>
void BinaryTree<T>::removeLeafs(TreeNode<T> *n){
    if((n->less == 0x0) && (n->more == 0x0)){
        TreeNode<T> *parent = n->parent;
        if(parent->less == n)
            parent->less = 0x0;
         else 
            parent->more = 0x0;
        delete n;
    } else {
        if(n->less != 0x0)
            removeLeafs(n->less);
        if(n->more != 0x0)
            removeLeafs(n->more);
    }
}

template <typename T>
T BinaryTree<T>::arithmeticalMean(){
    return sum(root) / size();
}

template <typename T>
T BinaryTree<T>::sum(TreeNode<T> *n){
    T result = n->value;
    if(n->less != 0x0)
        result += sum(n->less);
    if(n->more != 0x0)
        result += sum(n->more);
    return result;
}

template<typename T>
vector<bool> BinaryTree<T>::search(T value){
    vector<bool> *path = new vector<bool>;

    search(value, root, path);
        
    reverse(path->begin(),path->end());
    return *path;
}

template<typename T>
bool BinaryTree<T>::search(T value, TreeNode<T> *n,vector<bool> *code){
    
    if(n->value == value){
        //(*code).push_back(1);
        return true;
    }   
    if(n->less != 0x0) 
        if(search(value, n->less, code)){
            (*code).push_back(0);
            return true;
        }
    if(n->more != 0x0) 
        if(search(value, n->more, code)){
            (*code).push_back(1);
            return true;
        }
    return false;
}

template<typename T>
void BinaryTree<T>::clear(){
    free(root);
    count = 0;
    root = 0x0;
}

template<typename T>
void BinaryTree<T>::free(TreeNode<T> *n){
    if(n->less != 0x0) 
        free(n->less);
    if(n->more != 0x0) 
        free(n->more);
    delete n;
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


template <typename T>
bool BinaryTree<T>::allPositive(){
    if(size() == 0)
        return true;
    return positive(root);
}

template <typename T>
bool BinaryTree<T>::positive(TreeNode<T> *n){
    return ((n->value > 0) 
        && ((n->less == 0x0) || (positive(n->less))) 
        && ((n->more == 0x0) || (positive(n->more)))
        );
}


template <typename T>
int BinaryTree<T>::size(){
    return count;
}

template <typename T>
int BinaryTree<T>::countEven(){
    return countEven(root);
}

template <typename T>
int BinaryTree<T>::countEven(TreeNode<T> *n){
    int result = 0;
    if(n->value % 2 == 0)
        result = 1;

    if(n->less != 0x0)
        result += countEven(n->less);
    if(n->more != 0x0)
        result += countEven(n->more);

    return result;
}


template <typename T>
void BinaryTree<T>::show(ostream& out){
    show(root,out,0);
}

template <typename T>
void BinaryTree<T>::show(TreeNode<T> *n,ostream& out, int l){
    if(n != 0x0){
        show(n->less,out,l + 1);
        for(int i = 0;i < l;i++)
            cout << "   ";
        cout << n->value << endl;
        show(n->more,out,l + 1);
    }
}

template <typename T>
void BinaryTree<T>::show(int *tab_count, TreeNode<T> *n,ostream& out){
    if(n == 0x0)
        return;

    for(int i = 0;i < (*tab_count);i++)
        out << "    ";

    out << n->value;
    out << endl;
    (*tab_count)++;

    if(n->less != 0x0)
        show(tab_count,n->less, out);

    if(n->more != 0x0)
        show(tab_count,n->more, out);


    (*tab_count)--;
}

template <typename T>
ostream& BinaryTree<T>::operator<<(ostream& out)  {  
    
    int zero = 0;
    int *tab_count = &zero;
    show(tab_count, root, out);

    return out; 
} 

  

template <typename T>
BinaryTree<T>::~BinaryTree(){
    
};


#endif // BINARYTREE_H