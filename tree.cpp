#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent;
    int val;
};

void level_order_traversal(struct tree_node *root)
{
    struct tree_node *node;
    queue<struct tree_node*> q;
    int i = 1;


    q.push(root);

    while(!q.empty()){
        node = q.front();
        q.pop();
        node->val = i;
        cout << node->val << " ";

        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
        i++;
    }
    cout << endl;
}

void pre_order_traversal(struct tree_node *root)
{
    if(root != NULL){
        cout << root->val << " ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void in_order_traversal(struct tree_node *root)
{
    if(root != NULL){
        in_order_traversal(root->left);
        cout << root->val << " ";
        in_order_traversal(root->right);
    }
}

void post_order_traversal(struct tree_node *root)
{
    if(root != NULL){
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->val << " ";
    }
}

int main() {
    struct tree_node *a = new tree_node;
    struct tree_node *b = new tree_node;
    struct tree_node *c = new tree_node;
    struct tree_node *d = new tree_node;
    struct tree_node *e = new tree_node;
    struct tree_node *f = new tree_node;
    struct tree_node *g = new tree_node;
    struct tree_node *h = new tree_node;
    struct tree_node *i = new tree_node;
    struct tree_node *j = new tree_node;

    a->left     = b;
    a->right    = c;
    b->left     = d;
    b->right    = e;
    d->left     = NULL;
    d->right    = NULL;
    e->left     = g;
    e->right    = h;
    c->left     = f;
    c->right = NULL;
    f->left = NULL;
    f->right = i;
    g->left = NULL;
    g->right = NULL;
    h->left = NULL;
    h->right = NULL;
    i->left = NULL;
    i->right = NULL;
    level_order_traversal(a);
    
    cout << "pre_order_traversal" << endl;
    pre_order_traversal(a);
    cout << endl;

    cout << "in_order_traversal" << endl;
    in_order_traversal(a);
    cout << endl;

    cout << "post_order_traversal" << endl;
    post_order_traversal(a);
    cout << endl;


    return 0;
}