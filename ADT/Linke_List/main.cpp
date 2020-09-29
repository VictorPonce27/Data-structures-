#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList<int> list; 
    // list = {0,1,2,3,4};
    list.print(); 
    list.clear(); 
    list.print(); 
    return 0;
}
