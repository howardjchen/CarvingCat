#include <iostream>
#include <string>
#include <queue>
#include<stack>

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

void preorder_iterative(struct tree_node *root)
{
    stack<struct tree_node*> stk;
    struct tree_node *current;

    stk.push(root);
    
    while(!stk.empty()){
        current = stk.top();
        stk.pop();
        cout << current->val << " ";

        if(current->right != NULL)
            stk.push(current->right);
        if(current->left != NULL)
            stk.push(current->left);
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

void inorder_iterative(struct tree_node *root)
{
    struct tree_node *current;
    stack<struct tree_node*> stk;

    current = root;

    while(!stk.empty() || current != NULL){

        while(current != NULL){
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        cout << current->val << " ";
        current = current->right;
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

void postorder_iterative(struct tree_node *root)
{
    stack<struct tree_node*> stk;
    struct tree_node *current;

    stk.push(root);
    
    while(!stk.empty()){
        current = stk.top();

        if(current->right == NULL && current->left == NULL){
            cout << current->val << " ";
            stk.pop();
        }

        if(current->right != NULL)
            stk.push(current->right);
        if(current->left != NULL)
            stk.push(current->left);
        current->right = NULL;
        current->left = NULL;
    }
}

int max_depth(struct tree_node *root)
{
    int maximum_depth;
    int left_depth;
    int right_depth;

    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    if(root->left != NULL)
        left_depth = max_depth(root->left);
    
    if(root->right != NULL)
        right_depth = max_depth(root->right);
    
    maximum_depth = max(left_depth, right_depth);

    return maximum_depth+1;
}

int min_depth(struct tree_node *root)
{    
    int minimum_depth;
    int left_depth;
    int right_depth;

    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    if(root->left != NULL)
        left_depth = min_depth(root->left);
    
    if(root->right != NULL)
        right_depth = min_depth(root->right);
    
    minimum_depth = min(left_depth, right_depth);

    return minimum_depth+1;
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

    cout << "max_depth = " << max_depth(a) << endl;

    cout << "min_depth = " << min_depth(a) << endl;
    
    cout << "pre_order_traversal" << endl;
    pre_order_traversal(a);
    cout << endl;

    cout << "preorder_iterative" << endl;
    preorder_iterative(a);
    cout << endl;

    cout << "in_order_traversal" << endl;
    in_order_traversal(a);
    cout << endl;

    cout << "inorder_iterative" << endl;
    inorder_iterative(a);
    cout << endl;

    cout << "post_order_traversal" << endl;
    post_order_traversal(a);
    cout << endl;

    cout << "postorder_iterative" << endl;
    postorder_iterative(a);
    cout << endl;

    return 0;
}