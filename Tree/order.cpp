#include <iostream>
#include <fstream>                            
#define GLOBALSPACE5
using namespace std;
struct BST
{
    int data;
    BST *left, *right;
};
BST *root, *temp, *ttemp, *p;
void init()
{
    root = temp = ttemp = p = NULL;
}
void create_root(int x)
{
    root = new BST;
    root->data = x;
    root->left = root->right = NULL;
}

void Add_BST(int x)
{
    temp = root;
    while (temp != NULL)
    {
        ttemp = temp;
        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    p = new BST;
    p->data = x;
    p->left = p->right = NULL;
    if (ttemp->data > x)
    {
        ttemp->left = p;
    }
    else
    {
        ttemp->right = p;
    }
}
void In(BST *p)
{
    if (p != NULL)
    {
        In(p->left);
        cout << p->data << " ";
        In(p->right);
    }
}
void Pre(BST *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        Pre(p->left);
        Pre(p->right);
    }
}
void Post(BST *p)
{
    if (p != NULL)
    {
        Post(p->left);
        Post(p->right);
        cout << p->data << " ";
    }
}
// DELET NODE FORM BST
// case 1:
//  LEFT,RIGHT!=NULL
void Delete_BST(int x)
{
    temp = root;
    ttemp = NULL;
    // searching node to be deleted
    while (temp != NULL && temp->data != x)
    {
        ttemp = temp;
        if (x < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        cout << "Value " << x << " not found in the BST." << endl;
        return;
    }

    // Case 3: Two children
    if (temp->left != NULL && temp->right != NULL)
    {
        BST *succParent = temp;
        BST *succ = temp->right;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        temp->data = succ->data;
        temp = succ;
        ttemp = succParent;
    }

    // Case 1 & 2: One or no child
    BST *child;
    if (temp->left != NULL)
        child = temp->left;
    else   
        child = temp->right;

    if (ttemp == NULL)
        root = child;
    else if (ttemp->left == temp)
        ttemp->left = child;
    else
        ttemp->right = child;

    delete temp;
}

//    //case 1 : both left and right child are present
   
// if (left(temp)!= NULL && right(temp) != NULL)
// {
//     temp->leftmostnode(I)
//     s = right(temp);
//     while (left(S) != NULL)
//     {
//         ttemp = s;
//         s = left(s);
//     }
//     data(temp) = data(s);
//     temp = s;
// }
// //case 2 : LEFT,RIGHT =NULL
// // left=delet,right =null
// if (ttemp = Parent(temp))
// {
//     if (left(temp) = right(temp) == NULL)
//     {
//         if (left(ttemp) == temp)
//         {
//             left(ttemp) = NULL;
//         }
//         else
//         {
//             right(ttemp) = NULL;
//         }
//         rightDelet, left = !NULL;
//     }
// }
// //case 3 : left data, right null
// // right=null,left !=null
// {
//     if (left(temp) != NULL && right(temp) == NULL)
//     {
//         if (left(ttemp) = temp)
//         {
//             temp(ttemp) = left(temp);
//         }
//         else
//         {
//             right(ttemp) = left(temp);
//         }
//         leftDelet, right != NULL;
//     }
// }
// else      // case 4 : left=null,right data
// {
//     // left =null ,right !=null
//     if(left(temp) == NULL && right(temp) != NULL)
//     {
//         if (left(ttemp) == temp)
//         {
//             left(ttemp) = right(temp);
//         }
//         else
//         {
//             right(ttemp) = right(temp);
//         }
//         leftDelet, right != NULL;
//     }

// left(temp) = right(temp) = NULL;
// Delete temp;
// }

//  2D Print of BST
void print2D(BST *root, int space)
{
    if (root == NULL)
        return;
    space += 10;
    print2D(root->right, space);
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    print2D(root->left, space);
}
int main()
{
    init();
    create_root(100);
    Add_BST(50);
    Add_BST(80);
    Add_BST(150);
    Add_BST(200);
    Add_BST(250);
    Add_BST(300);

    cout << "In-Order Traversal(Sorted): \n";
    In(root); // Correctly called with root
    cout << endl<<"\n";

    cout << "Pre-Order Traversal:\n ";
    Pre(root); // Correctly called with root
    cout << endl<<"\n";

    cout << "Post-Order Traversal: \n";
    Post(root);
    cout << endl<<"\n";

    cout << "Delete 250 from BST." << endl;
    Delete_BST(250);

    cout << "In-Order Traversal after deletion:\n ";
    In(root);
    cout << endl << "\n";

    cout << "2D representation of BST:\n";
    print2D(root, 0);

    return 0;
}