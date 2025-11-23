#include<iostream>
#include<vector>
#include<list>
#include<stack>  // when we use stack from STL we don't need to create class and include this header file
using namespace std;
  // Implement stack using STL list with class /object concept
// class Stack {
//     list<int>ll;
     

// public:
//     void push(int val){
//         ll.push_front(val);
//     }
//     void pop(){
//             ll.pop_front();
//     }
//     int top(){
//          return ll.front();
//     }
  
//     bool empty(){
//         return ll.size()==0;
//     }
// };

int main(){
    stack<int> s;
     // stack s;  // we can also use this syntax in c++11 for object creation and class template

    s.push(10);
    s.push(20);
    s.push(30);
    while( !s.empty()){
        cout << s.top()<<" ";
        s.pop();
    }
    cout<< endl; //30 20 10

    return 0;
}