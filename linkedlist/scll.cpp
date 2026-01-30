#include <iostream>
#define null 0
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *first, *temp, *ttemp, *p, *q, *r, *ptemp, *pttemp, *newnode, *nttemp;

void init()
{
    first = temp = ttemp = null;
}

void createfirst(int val)
{
    first = new Node;
    first->data = val;
    first->next = null;
}

void AddNode(int val )  
{
    temp = first;
    while (temp->next != null)
    {        
        temp = temp->next;
    }
    ttemp = new Node;
    ttemp->data = val;
    ttemp->next = null;
    temp->next = ttemp;
}

void disp()
{  
    temp = first;
    while (temp != null)
    {
        cout << temp->data <<endl;
        temp = temp->next;
    }
    
}

void Add_After(int x, int y)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
        ttemp=temp->next;
    }

    p = new Node;
    p->data = y;
    p->next = ttemp;
    temp->next = p;
}

void Add_Before(int x, int y)
{

    temp = first;
    while ( temp->data != x)
    {   ttemp=temp;
        temp = temp->next;
    }
    p = new Node;
    p->data = y;
    p->next = temp;
    ttemp->next = p;
}

void Add_Beforefirst(int x)
{
    temp = new Node;
    temp->data = x;
    temp->next = first;
    first = temp;
}

void Add_Beforelast(int x)
{
    temp = first;
    while (temp->next != null)
    {  ttemp =temp;
        temp = temp->next;
    }
    p=new Node;
    p->data=x;
    p->next=temp;
    ttemp->next=p;

    // ttemp = new Node;
    // ttemp->data = x;
    // ttemp->next = null;
    // temp->next = ttemp;
}

// Delete a node
void Delete_after(int x)
{      temp =first;
    while ( temp->data != x)
    {   
       temp = first;
        temp = temp->next;
    }
        ttemp=temp->next;
        p=ttemp->next;
        temp->next=p;
        ttemp->next =null;
        delete ttemp;

}


void Delete_before(int x){
    temp = first;  
      while ( temp->next->data != x){        
        ttemp=temp;
        temp = temp->next;
      }
       p=temp->next;
        ttemp->next = p;
        temp->next =null;
        delete temp;
}

void Delete_sec_last(){
    temp = first;  
      while ( temp->next->next != null){        
        ttemp=temp;
        temp = temp->next;
      }
       p=temp->next;
        ttemp->next = p;
        temp->next =null;
        delete temp;
}
  void Delete_first(){
    temp=first;
    first=first->next;
    temp->next=null;
    delete temp;
  }
 void Delete_last(){
        temp=first;
        while(temp->next!=null){
            ttemp=temp;
            temp=temp->next;
        }
        ttemp->next=null;
        delete temp;
    }     

void Swap_first_last() {
     temp = first;
      ttemp = temp;

    // Traverse till the second last node
    while (temp->next != null) {
         ttemp = temp;
        temp = temp->next; 
    }
    // Swap pointers
    ttemp->next = first;
    temp->next = first->next;
    first->next = null;
    first = temp;
}


int main(){ 

    init();
    createfirst(10);
    AddNode(20);
    AddNode(30);
    AddNode(50);
    AddNode(60);
    

    cout << "Original List:\n ";
    disp();

    cout << "\nAfter Add_After(30, 70):\n";
    Add_After(30, 70);
    disp();

    cout << "\nAfter Add_Before(60, 80):\n";
    Add_Before (60, 80);
    disp();

    cout << "\nAfter Add_Beforefirst(15):\n";
    Add_Beforefirst(15);
    disp();

    cout << "\nAfter Add_Beforelast(55):\n";
    Add_Beforelast(55);
    disp();
 
    // cout << "\nAfter Delete_after(30):\n";
    // Delete_after(30);
    // disp();


    cout << "\nAfter Delete_before(50) :\n";
    Delete_before(50);
    disp();

    
    cout << " Delete_secondlast :\n";
    Delete_sec_last();
    disp();

    cout<<"Delete_first : \n";
    Delete_first();
    disp();

    cout<<"Delete_last : \n";
    Delete_last();
    disp();
    
     cout << "After Swapping First and Last: ";
    Swap_first_last();
    disp();
   

return 0;

}
 