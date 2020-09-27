#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
    LinkedList<int> list; 
    list = {1,2}; 
    list.print(); 
    list.add_last(3); 
    list.print(); 
    list.add_first(0);
    list.print();
    if(list.delete_at(3) == true){
        cout<<"Deleted"<<endl;
    } 

    list.print(); 
    try{
        list.update_data(2,10); 
    }
    catch(invalid_argument& e){
        cout<< e.what()<<endl;
    }

    list.print(); 
    try{
        list.update_at(0,5); 
    }
    catch(invalid_argument& e){
        cout<< e.what()<<endl;
    }

    try{
       cout<<"item at position 2 is : " <<list[2]<<endl;  
    }
    catch (invalid_argument& e){
        cout<< e.what() << endl;
    }
    list.print(); 
    return 0;
}
