#include <iostream>
using namespace std;

#include "Quee.h"
#include "Double_Linked_List.h"

int main(){
    
    Double_Linked_List<int> list; 
    Queue<int> list2;
    list = {51, 28, 21, 48, 25};
    list.print(); 
    list.print_backwards(); 

    list2 = {1,2,3,4};
    
    list[0] = list2.dequeue(); 

    list.print(); 
    list2.print(); 
    list.print_backwards(); 
    // list.print_backwards(); 

    return 0;
}