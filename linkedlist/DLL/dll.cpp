#include <iostream>
#define null 0
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

Node *first = null, *temp = null, *ttemp = null, *p = null;

void create_first(int val)
{
    first = new Node;
    first->data = val;
    first->next = null;
    first->prev = null;
}

void Add_Node(int val)
{
    if (first == null) {
        create_first(val);
        return;
    }
    temp = first;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = val;
    ttemp->prev = temp;
    ttemp->next = null;
    temp->next = ttemp;
}

void Add_Beforefirst(int val)
{
    temp = new Node;
    temp->data = val; 
    temp->prev = null;
    temp->next = first;
    if (first != null) {
        first->prev = temp;
    }
    first = temp;
}

void Add_BeforeData(int val, int y)
{
    if (first == null) return;
    temp = first;
    ttemp = null;  // Initialize for case when inserting before first
    while (temp != null && temp->data != val)
    {
        ttemp = temp;
        temp = temp->next;
    }
    if (temp == null) {
        cout << "Node with " << val << " not found.\n";
        return;
    }
    p = new Node;
    p->data = y;
    p->prev = ttemp;
    p->next = temp;
    temp->prev = p;
    if (ttemp != null) {
        ttemp->next = p;
    } else {
        first = p;  // Updating first if inserting at head
    }
}

void Add_AfterData(int val, int y)
{
    if (first == null) return;
    temp = first;
    while (temp != null && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == null) {
        cout << "Node with " << val << " not found.\n";
        return;
    }
    ttemp = temp->next;  // Node after target
    p = new Node;
    p->data = y;
    p->next = ttemp;
    p->prev = temp;
    temp->next = p;
    if (ttemp != null) {
        ttemp->prev = p;
    }
}

void Delete_AfterData(int val){
    if (first == null) return;
    temp = first;
    while (temp != null && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == null) {
        cout << "Node with " << val << " not found.\n";
        return;
    }
    ttemp = temp->next;
    if (ttemp == null) {
        cout << "No node after " << val << ".\n";
        return;
    }
    p = ttemp->next;
    temp->next = p;
    if (p != null) {
        p->prev = temp;
    }
    delete ttemp;
}

void swapDSLL(){
    if (first == null || first->next == null) return;  // No swap for 0/1 node
    temp = first; 
    ttemp = null;  // Initialize
    while(temp->next != null){
        ttemp = temp;
        temp = temp->next;
    }
    // Now temp = last, ttemp = second last
    if (ttemp == null) return;  // Safety, though covered
    p = ttemp->prev;  // Before second last
    if (p != null) {
        p->next = temp;
    } else {
        first = temp;  // For 2 nodes, update first
    }
    temp->prev = p;
    temp->next = ttemp;
    ttemp->prev = temp; 
    ttemp->next = null;
}
 
void disp()
{
    if (first == null) {
        cout << "List is empty.\n";
        return;
    }
    temp = first;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << " " << endl;
}

int main()
{
    create_first(10);
    Add_Node(20);
    Add_Node(30);
    Add_Node(50);
    Add_Node(60);

    cout << "Original List:\n";
    disp();

    cout << "\nAfter Add_Beforefirst(80):\n";
    Add_Beforefirst(80);
    disp();

    cout << "\nAfter Add_BeforeData(50,90):\n";
    Add_BeforeData(50,90);
    disp();

    cout << "\nAfter Delete_AfterData(50):\n";
    Delete_AfterData(50);
    disp();

    cout << "\nAfter swapDSLL():\n";
    swapDSLL();
    disp();

    // Optional: Cleanup to avoid leaks (not in original, but good practice)
    // while (first != null) { temp = first; first = first->next; delete temp; }

    return 0;
}