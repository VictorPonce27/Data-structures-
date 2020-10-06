#include <iostream>
using namespace std;
#include "Stack.h"


int main(){
    Stack<int> stack; 
    stack = {56,22,31}; 
    stack.print(); 
    stack.get_size(); 

    cout<<"value at the top " << stack.Top() <<endl;
    stack.print();
    cout<<"size of quee: "<<stack.get_size()<<endl;

    cout<< stack.pop() <<endl;
    stack.print();
    cout<<"size of quee: "<<stack.get_size()<<endl;

    stack.clear(); 
    stack.print();
     cout<<"size of quee: "<<stack.get_size()<<endl;

    return 0;
}
 