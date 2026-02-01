//singly circular LL add 
#include<iostream>
using namespace std;
#define null 0
struct SCLL
{
    int data;
    SCLL *next;
};
SCLL *first,*temp,*ttemp,*p,*q,*r,*prevM,*prevN,*currN,*currM;
void createfirst(int x){
    first= new SCLL;
    first->data= x;
    first->next= first;


}
void AddNode(int val){
  
    temp =first;
  while(temp->next!=first){
    temp=temp->next;
  }
    ttemp = new SCLL;
     ttemp->data =val;
    ttemp->next = first;
    temp->next = ttemp;
}
// void addnode()
// {  
//    ttemp=new node;
//    cin>>ttemp->data;
//    ttemp->next=first;//default 
//    if(first==null)
//    {
//    first=temp=ttemp;
//    ttemp->next=first;
//    }//circular ink
//    else
//    {
//    temp->next=ttemp;
//    ttemp->next=first;
//    temp=ttemp;
//    }
// }
void Add_before_first(int val){
    temp =first;
     while(temp->next!=first){
        temp =temp->next;
    }   
    ttemp =new SCLL;
    ttemp->data=val;
    ttemp->next=first;
   
        temp->next =ttemp;
        first =ttemp;
}

// void add_before_given(int x,int y)
// {
//  temp=first;
//  ttemp=first;
//  while(temp->data!=x)
//  {
//     ttemp=temp;
//     temp=temp->next;
//  }
//  p=new node;
//  p->data=y; 
//  if(temp==first)
//  {  
//     q=first;
//     while(q->next!=first)
//     q=q->next;
//     p->next=temp;
//     q->next=p;
//     first=p;
//  }
//  else
//  {
//     p->next=temp;
//     ttemp->next=p;
//  }
// }

void Add_before(int x,int val){
    temp =first;
    while (temp->next->data != x){
        temp =temp->next;
    }
    p =new SCLL;
    p->data=val;
    p->next =temp->next;
    temp->next =p;
}
void Add_after(int x,int val){
    temp =first;
    while (temp->data != x){
        temp =temp->next;
    }
    p =new SCLL;
    p->data=val;
    p->next =temp->next;
    temp->next =p;
}

void Add_after_last(int val){
    temp =first;
    ttemp =new SCLL;
    ttemp->data=val;
    ttemp->next=first;
    while(temp->next!=first){
        temp =temp->next;
    }   
        temp->next =ttemp;
    
}
void del_last()
{
    temp=first;
    while(temp->next!=first)
    {   
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=first;
    temp->next=null;
    delete temp;
    
}
void del_first()
{   ttemp=first;
    temp=first->next;
    while(ttemp->next!=first)
{
    ttemp=ttemp->next;
}
    ttemp->next=temp;
    first->next=null;
    first=temp;
}
void delanyMth(int m)
{ 
  if(first==null)return;
  temp=first;
  ttemp=first;
  int count=1;
  bool found=false;
  while(count<m&&temp->next!=first)
  { ttemp=temp;
    temp=temp->next;
    count++;
  }
  if(count==m)
  {
    found=true;
    cout<<"node found\n";
  }
  else 
  {
    found=false;
    cout<<"node not found\n";
    return;
  }
  p=first;
  while(p->next!=first)
  p=p->next;
  SCLL *todelete=temp;
  SCLL *after=todelete->next;
  if(todelete==first)
  {
    first=after;
    p->next=after;
  }
  else if(todelete==p)
  {
    ttemp->next=first;
  }
  else
  {
    ttemp->next=temp->next;
  } 
  delete temp;
}
void disp()
{   
    temp=first;
    do{
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=first);
}
void reverse()
{
  temp=first;
  ttemp=null;
  SCLL *next=null;
  do
  {
     next=temp->next;
     temp->next=ttemp;
     ttemp=temp;
     temp=next;
  }while(temp!=first);
  first->next=ttemp;
  first=ttemp;
}

void swapFS()
{
 p=first->next;
 temp=first;
 while(temp->next!=first)
 {
    temp=temp->next;
 }
 q=p->next;
 p->next=first;
 first->next=q;
 temp->next=p;
 first=p;
}
void swapFL()
{
   temp=first;
   p=first->next;
   while(temp->next !=first)
   {
    ttemp=temp;
    temp=temp->next;
   }
   ttemp->next=first;
   first->next=temp;
   temp->next=p;
   first=temp;
}
void swapL2L()
{
    temp=first;
    while(temp->next->next!=first)
    {
        ttemp=temp;temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    p->next=temp;
    temp->next=first;
}
void swapMN(SCLL *head,int m,int n)
{
    if(!head)
    {
        cout<<"list is empty.Swap not performed\n9";
        return;
    }
    if(m==n) 
    {
        cout<<"positions are same .no swap needed\n";
        return;
    }//if list empty or x==y 
    if(m>n)swap(m,n);
    prevM=null;    currM=head;
    prevN=null;    currN=head;
    int count=1;
    while(count!=m)
    {
        prevM=currM;
        currM=currM->next;
        count++;
        if(currM==head) {cout<<"m not found\n";return;}//m out of bound
    }
    count=1;
    while(count!=n)
    {
        prevN=currN;
        currN=currN->next;
        count++;
        if(currN==head) {cout<<"n not found\n";return;}//n out of bound
    }
    //adjacent case
    if(currM->next==currN)
    {
        if(prevM)prevM->next=currN;
        else
        head=currN;
        currM->next=currN->next;
        currN->next=currM;
    }
    //default case
    else
    {
        if(prevM)prevM->next=currN;
        if(prevN)prevN->next=currM;
        temp=currM->next;
        currM->next=currN->next;
        currN->next=temp;
        //update head if needed
        if(currM==head)head=currN;
        else if(currN==head)head=currM;
    }
}

int main()
{   
    first=ttemp=temp=null;
    int n;
    cout<<"enter no. of terms in LL: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        AddNode;
    }
    cout<<"\n";
    disp();
    cout<<"Add before first= \n";
    Add_before_first(5);
    disp();
    cout<<" Add before given data= \n";
    Add_before(5,6);
    disp();  
    // deletion
    cout<<"Delet last node= \n";
     del_last();
    disp();
    cout<<"Delet first node= \n";
    del_first();
    disp();
    cout<<"Delet Mth node= \n";
    delanyMth(1);
    disp();

    cout<<"Reverse of CLL= \n";
     reverse();
    disp();

      cout<<"\n";
    swapFS();
    disp();
    cout<<"\n";
    swapFL();
    disp();
    cout<<"\n";
    swapL2L();
    disp();
    cout<<"after Swaping MNth node= \n";
    swapMN(first,50,30);
    disp();
}