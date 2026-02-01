#include <iostream>
using namespace std;

// AVL Tree Node
struct Node
{
    int data;
    Node *left, *right;
    int height;
};
Node *root, *temp, *ttemp, *p;
void init()
{
    root = temp = ttemp = p = NULL;
}

Node *create_Node(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // new node height = 1
    return node;
}

// Get height of node
int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

// Get maximum of two values
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Right Rotation (LL Case)
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation (RR Case)
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance Factor
int getBalance(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

// Insert in AVL Tree
Node *insert(Node *node, int key)
{

    // 1. Normal BST insertion
    if (node == NULL)
        return create_Node(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; // duplicate not allowed

    // 2. Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor
    int balance = getBalance(node);

    //     // 4. Rotation cases

    //     // LL Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    //     // RR Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    //     // LR Case
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //     // RL Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main Function
int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 65);

    cout << "Inorder traversal of AVL Tree:\n";
    inorder(root);

    return 0;
}
