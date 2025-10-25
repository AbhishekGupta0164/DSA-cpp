#include<iostream>
using namespace std;
 
// leetcode  11Q
 // container with most water using 2 pointer approach

int main(){
    int height[]={1,8,6,2,5,4,8,3,7};

int maxWater =0;
int lp =0; 
int rp=sizeof(height) / sizeof(height[0])-1;                    

while(lp<rp){
    int width = rp-lp;
    int ht= min(height[lp], height[rp]);
    int  currWater = width*ht;
    maxWater = max(maxWater, currWater);
    (height[lp] < height[rp]) ? lp++ : rp--;

}
 cout << "Maximum water container area: " << maxWater << endl;
return maxWater;
} 