#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"
#include <vector>
#include <iostream>  
#include <algorithm>

using namespace std;

class BinaryTree{
    public:
        BinaryTree(string value);
        
        BinaryTree(BinaryTree &other);

        BinaryTree(BinaryTree &&other);

        void insert(string value);

        int size();

        void clear();

        TreeNode* min(TreeNode *s);
        TreeNode* max(TreeNode *s);

        void remove(string value);

        int search(string value);

        ostream& operator<<(ostream& out);

        BinaryTree& operator=(BinaryTree &other);    
        BinaryTree& operator=(BinaryTree &&other);    
    
        ~BinaryTree();
    private:
        void free(TreeNode *n);

        TreeNode* searchTreeNode(string value);
        TreeNode* searchTreeNode(TreeNode *n,string value);

        int search(TreeNode *n,string value);
        TreeNode* dublicate(TreeNode *n);
        TreeNode* remove(TreeNode *n,string value);
        void insert(TreeNode *x,TreeNode *z);
        void show(TreeNode *n,ostream& out, int l);
        void show(int *tab_count, TreeNode *n,ostream& out);
    protected:
        TreeNode *root;
        int count;
};


BinaryTree::BinaryTree(string value){
    root = new TreeNode;
    root->less = 0x0;
    root->more = 0x0;
    root->parent = 0x0;
    root->value = value;
    count = 1;
}

BinaryTree::BinaryTree(BinaryTree &other){
    root = new TreeNode;
    root->parent = 0x0;
    root = dublicate(other.root);
    count = other.count;
}

BinaryTree::BinaryTree(BinaryTree &&other){
    root = new TreeNode;
    root->parent = 0x0;
    root = dublicate(other.root);
    count = other.count;
    other.clear();
}

BinaryTree& BinaryTree::operator=(BinaryTree &other){
    BinaryTree copy(other);
} 

BinaryTree& BinaryTree::operator=(BinaryTree &&other){
    BinaryTree copy(move(other));
}       
    
TreeNode* BinaryTree::dublicate(TreeNode *n){
    if (n == 0x0){
		return 0x0;
	}
	TreeNode *c = new TreeNode;
    c->value = n->value;
    c->count = n->count;
    c->parent = n->parent;
	c->less = dublicate(n->less);
	c->more = dublicate(n->more);
    return c;
}



void BinaryTree::insert(string value){
    TreeNode *new_node = new TreeNode;
    new_node->value = value;
    new_node->count = 1;
    new_node->less = 0x0;
    new_node->more = 0x0;
    new_node->parent = 0x0;
    
    insert(root, new_node);
    count++;
}

void BinaryTree::insert(TreeNode *x, TreeNode *z){
    while(x != 0x0){
        if(z->value.compare(x->value) > 0){
            if(x->more != 0x0){
                x = x->more;
            } else {
                z->parent = x;
                x->more = z;
                break;
            }
        } else {
            if(z->value.compare(x->value) < 0){
                if(x->less != 0x0){
                    x = x->less;
                } else {
                    z->parent = x;
                    x->less = z;
                    break;
            } 
        }else if(z->value.compare(x->value) == 0){
            x->count++;
            break;
        }
    }
    }
} 

int BinaryTree::search(string value){
    return search(root, value);
}

int BinaryTree::search(TreeNode *n,string value){
    if((n == 0x0) || (value == n->value))
        return n->count;
    if(value.compare(n->value) < 0){
        return search(n->less, value);
    } else 
        return search(n->more, value);
}

TreeNode* BinaryTree::searchTreeNode(string value){
    return searchTreeNode(root, value);
}

TreeNode* BinaryTree::searchTreeNode(TreeNode *n,string value){
    if((n == 0x0) || (value == n->value))
        return n;
    if(value.compare(n->value) < 0){
        return searchTreeNode(n->less, value);
    } else 
        return searchTreeNode(n->more, value);
}


void BinaryTree::remove(string value){
    TreeNode *s = searchTreeNode(value);
    if(s == 0x0)
        return;
    if(s->count > 1)
        s->count--;
    else 
        remove(root, value);
}

TreeNode* BinaryTree::remove(TreeNode *n,string value){
    if(n == 0x0)
        return n;
    
    if((n->count > 1)){
        n->count--;
    } 
    if(value.compare(n->value) < 0){
       n->less = remove(n->less, value);
    } else if(value.compare(n->value) > 0){
        n->more = remove(n->more, value);
    } else if( (n->less != 0x0) && (n->more != 0x0) ){
        n->value = min(n->more)->value;
        n->more = remove(n->more, n->value);
    } else {
        if(n->less != 0x0)
            n = n->less;
        else
            n = n->more;
    }
    
    return n;
}

void BinaryTree::clear(){
    free(root);
    count = 0;
    root = 0x0;
}

void BinaryTree::free(TreeNode *n){
    if(n->less != 0x0) 
        free(n->less);
    if(n->more != 0x0) 
        free(n->more);
    delete n;
}

TreeNode* BinaryTree::min(TreeNode *s){
    if(s->less == 0x0)
        return s;
    return min(s->less);
}

TreeNode* BinaryTree::max(TreeNode *s){
    if(s->more == 0x0)
        return s;
    return max(s->more);
}


int BinaryTree::size(){
    return count;
}
void BinaryTree::show(TreeNode *n,ostream& out, int l){
    if(n != 0x0){
        show(n->less,out,l + 1);
        for(int i = 0;i < l;i++)
            cout << "   ";
        cout << n->value << endl;
        show(n->more,out,l + 1);
    }
}

void BinaryTree::show(int *tab_count, TreeNode *n,ostream& out){
    if(n == 0x0)
        return;

    if(n->less != 0x0)
        show(tab_count,n->less, out);

    //for(int i = 0;i < (*tab_count);i++)
    //    out << "    ";

    out << n->value << " (" << n->count << ") " ;
    //out << endl;
    (*tab_count)++;

    

    if(n->more != 0x0)
        show(tab_count,n->more, out);


    (*tab_count)--;
}

ostream& BinaryTree::operator<<(ostream& out)  {  
    
    int zero = 0;
    int *tab_count = &zero;
    show(tab_count, root, out);

    return out; 
} 

  

BinaryTree::~BinaryTree(){
    //clear();
};


#endif // BINARYTREE_H