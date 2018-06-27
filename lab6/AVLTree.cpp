//
// Created by byzilio on 25.06.18.
//

#include "AVLTree.h"

AVLTree::AVLTree(string value){
    root = new AVLNode;
    root->less = 0x0;
    root->more = 0x0;
    root->value = value;
    root->count = 1;
    root->height = 0;
    count = 1;
}

AVLTree::AVLTree(AVLTree &other){
    root = new AVLNode;
    root = dub(other.root);
    count = other.count;
}

AVLTree::AVLTree(AVLTree &&other){
    root = new AVLNode;
    root = dub(other.root);
    count = other.count;
    other.clear();
}

AVLTree& AVLTree::operator=(AVLTree &other){
    AVLTree &copy(other);
    return copy;
}

AVLTree& AVLTree::operator=(AVLTree &&other){
    AVLTree *copy = new AVLTree(move(other));
    return *copy;
}

AVLNode* AVLTree::dub(AVLNode *n){
    if (n == 0x0){
        return 0x0;
    }
    AVLNode *c = new AVLNode;
    c->value = n->value;
    c->count = n->count;
    c->less = dub(n->less);
    c->more = dub(n->more);
    return c;
}


int AVLTree::getHeight(AVLNode *n) {
    if(n != 0x0)
        return n->height;
    return -1;
}

int AVLTree::balanceFactor(AVLNode *n) {
    if(n == 0x0)
        return 0;
    return getHeight(n->more) - getHeight(n->less);
}

void AVLTree::fixHeight(AVLNode *n) {
    int h1 = getHeight(n->less);
    int h2 = getHeight(n->more);
    if(h1 > h2)
        n->height = h1 + 1;
    else
        n->height = h2 + 1;
}

AVLNode* AVLTree::rotateRight(AVLNode *n) {
    AVLNode *a = n->less;
    n->less = a->more;
    a->more = n;
    //fixHeight(n);
    n->height = std::max(getHeight(n->less), getHeight(n->more)) + 1;
    a->height = std::max(getHeight(n->less), n->height) + 1;
    //fixHeight(a);
    return a;
};

AVLNode* AVLTree::rotateLeft(AVLNode *n) {
    AVLNode *a = n->more;
    n->more = a->less;
    a->less = n;
    //fixHeight(n);
    n->height = std::max(getHeight(n->less), getHeight(n->more)) + 1;
    a->height = std::max(getHeight(n->more), n->height) + 1;
    //fixHeight(a);
    return a;
};


AVLNode* AVLTree::balance(AVLNode *n) {
    fixHeight(n);
    if(balanceFactor(n) == 2){
        if(balanceFactor(n->more) < 0)
            n->more = rotateRight(n->more);
        return rotateLeft(n);
    }
    if(balanceFactor(n) == -2){
        if(balanceFactor(n->less) > 0)
            n->less = rotateLeft(n->less);
        return rotateRight(n);
    }
    return n;
}


void AVLTree::insert(string value){
    AVLNode *s = searchTreeNode(value);
    if(s != 0x0)
        s->count++;
    else
        root = insert(root, value);
    count++;
}

AVLNode* AVLTree::insert(AVLNode *x, string value){
    if(x == 0x0)
    {
        AVLNode *t = new AVLNode;
        t->value = value;
        t->height = 0;
        t->less = t->more = 0x0;
        return t;
    }
    if( value.compare(x->value) < 0)
        x->less = insert(x->less, value);
    else
        x->more = insert(x->more, value);
    return balance(x);

}

int AVLTree::search(string value){
    return search(root, value);
}

int AVLTree::search(AVLNode *n,string value){
    if((n == 0x0) || (value == n->value))
        return n->count;
    if(value.compare(n->value) < 0){
        return search(n->less, value);
    } else
        return search(n->more, value);
}

AVLNode* AVLTree::searchTreeNode(string value){
    return searchTreeNode(root, value);
}

AVLNode* AVLTree::searchTreeNode(AVLNode *n,string value){
    if((n == 0x0) || (value == n->value))
        return n;
    if(value.compare(n->value) < 0){
        return searchTreeNode(n->less, value);
    } else
        return searchTreeNode(n->more, value);
}


void AVLTree::remove(string value){
    AVLNode *s = searchTreeNode(value);
    if(s == 0x0)
        return;
    if(s->count > 1)
        s->count--;
    else
        remove(root, value);
}

AVLNode* AVLTree::remove(AVLNode *n,string value){
    if( n == 0x0 )
        return 0x0;

    if(value.compare(n->value) < 0)
        n->less = remove(n->less, value);
    else if(value.compare(n->value) > 0)
            n->more = remove(n->more, value);
    else {
        AVLNode *l = n->less;
        AVLNode *r = n->more;
        delete n;
        if(r == 0x0)
            return l;
        AVLNode *m = min(r);
        m->more = removeMin(r);
        m->less = l;
        return balance(m);
    }
    return balance(n);
}

void AVLTree::clear(){
    if(root != 0x0)
        free(root);
    count = 0;
    root = 0x0;
}

void AVLTree::free(AVLNode *n){
    if(n->less != 0x0)
        free(n->less);
    else
        delete n->less;
    if(n->more != 0x0)
        free(n->more);
    else
        delete n->more;
    delete n;
}

AVLNode* AVLTree::min(AVLNode *s){
    if(s == 0x0)
        return 0x0;
    if(s->less == 0x0)
        return s;
    return min(s->less);
}

AVLNode* AVLTree::removeMin(AVLNode *n){
    if( n->less == 0x0 )
        return n->more;
    n->less = removeMin(n->less);
    return balance(n);
}

AVLNode* AVLTree::max(AVLNode *s){
    if(s == 0x0)
        return 0x0;
    if(s->more == 0x0)
        return s;
    return max(s->more);
}


int AVLTree::size(){
    return count;
}

void AVLTree::show(AVLNode *n,ostream& out, int l){
    if(n != 0x0){
        show(n->less,out,l + 1);
        for(int i = 0;i < l;i++)
            cout << "   ";
        cout << n->value << endl;
        show(n->more,out,l + 1);
    }
}

void AVLTree::show(int *tab_count, AVLNode *n,ostream& out){
    if(n == 0x0)
        return;


    if(n->less != 0x0)
        show(tab_count,n->less, out);

    //for(int i = 0;i < (*tab_count);i++) //Если раскоментитть будет видно как insert кладет в дерево
    //    out << "    ";

    out << n->value << " (" << n->count << ") " ;
    //out << endl;
    (*tab_count)++;




    if(n->more != 0x0)
        show(tab_count,n->more, out);


    (*tab_count)--;
}

ostream& AVLTree::operator<<(ostream& out)  {

    int zero = 0;
    int *tab_count = &zero;
    show(tab_count, root, out);

    return out;
}

AVLTree::~AVLTree(){
    clear();
}

