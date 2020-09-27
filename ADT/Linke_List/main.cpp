#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList<int> list; 
    list.add_last(2); 
    list.add_first(1);
    list.print();
    list.add_first(0); 
    list.add_last(3); 
    list.print(); 
    if(list.delete_data(3) == true){
        cout<<"Deleted"<<endl;
    } 
    list.print(); 

    return 0;
}
