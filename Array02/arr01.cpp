#include <iostream>
#include<vector>
using namespace std;
 // allocation in memory using vector 
int main(){
    vector<int >vec;

vec.push_back(0);
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);
vec.push_back(4);
cout<<"after push back size = "<<vec.size()<< endl;
cout<< vec.size()<<endl;
cout<< vec.capacity()<<endl; 
 
    return 0;
 

}