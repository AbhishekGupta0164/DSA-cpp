#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next,*temp;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

class List
{
  Node *first;
  Node *last;

public:
  List()
  {
    first = last = NULL;
  }

  void push_front(int val)
  {
    Node *newNode = new Node(val); // dynamic
    if (first== NULL) 
    {
      first = last = newNode;
      return;
    }
    else
    {
      newNode->next = first;
      first = newNode;
    }
  }
  void push_last(int val){
    Node *newNode =new Node(val);
    if(first ==NULL){
       first=last =newNode;

    } else{
      last ->next= newNode;
      last = newNode;
    }
  }

   void pop_front(){
     if(first ==NULL){
      return ;
     }
    Node *temp=first;
    first =first->next;
    temp->next=NULL;
    delete temp;
   }
        
   void pop_last(){
      //    if(first ==NULL){
      //   cout <<"List is empty"<<endl;
      // return ;
    Node *temp =first;
    
    while(temp->next !=NULL){
      temp = temp->next;
    }
     temp->next =NULL;
     delete temp;
     last =temp;
    }
     
    void insert_inMiddle(int val,int pos){
      if(pos <0){
        cout<<"invalid pos\n";
        return ;
      }
      Node *temp =first;
      for(int i = 0; i<pos-1; i++){
        temp = temp->next;
      }
      Node *newNode = new Node(val);
      newNode ->next =temp ->next;
      temp->next =newNode;

    }

  void printLL()
  {
    Node *temp = first;
    while (temp != NULL)
    { 
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout <<  endl;
   }        

     // for search element exist in list or not

   int search(int key){
    Node *temp =first;
    int pos =0;
    while(temp !=NULL){
      if(temp ->data ==key){
        return pos;
      }
      temp =temp ->next;
      pos++;
    }
    return -1;
   }

};

int main()
{

  List ll;

  
  ll.push_front(10);
  ll.push_front(20);
  ll.push_front(30);
 
  ll.push_last(40);
   
  ll.insert_inMiddle(25,2); 
  ll.pop_front();
  ll.pop_last();
  ll.printLL();  //display linked list

   //cout<<ll.search(30)<<endl;

return 0;

}
