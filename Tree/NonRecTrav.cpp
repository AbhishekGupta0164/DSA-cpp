#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left,*right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//  ITERATIVE PREORDER ---
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
}

// ---ITERATIVE INORDER ----------------
void inorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// ---POSTORDER ----------------
void postorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)  s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {

    //           1
    //         /   \
    //        2     3
    //       / \     \
    //      4   5     6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder (Iterative):  ";
    preorder(root);

    cout << "\nInorder (Iterative):   ";
    inorder(root);

    cout << "\nPostorder (Iterative): ";
    postorder(root);

    return 0;
}
