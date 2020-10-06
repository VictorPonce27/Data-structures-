#include <iostream>
using namespace std;

#include "Queue.h"

int main(){
    Queue<int> quee; 

    quee = {0,1,2,3,4}; 
    quee.print(); 
    cout<<"size of quee: "<< quee.get_size()<<endl; 


    quee.dequeue(); 
    quee.print(); 
    cout<<"size of quee: "<< quee.get_size()<<endl; 

    quee.enqueue(5); 
    quee.print(); 
    cout<<"size of quee: "<< quee.get_size()<<endl; 

    cout<<"value at the top: " <<quee.front()<<endl;
    cout<<"value at the end: " <<quee.back()<<endl;
    
    quee.clear();
    quee.print(); 
    cout<<"size of quee: "<< quee.get_size()<<endl; 

    return 0;
}
