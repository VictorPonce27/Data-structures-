#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){

    LinkedList<int> list;
    LinkedList<int> list2;
    list = {51, 28, 21, 48, 25};
    list.print();
    list.sort(); 
    list.print();
    list.duplicate();
    list.print();
    list.remove_duplicates();
    list.print();
    list2 = {1,2,3,4}; 
    cout<<"list 2: ";  
    list2.print(); 
    cout<<"lis 1: "; 
    list = list2; 
    list.print(); 
    list.reverse(); 
    list.print(); 
    return 0;
}
