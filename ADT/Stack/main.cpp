#include <iostream>
using namespace std;
#include "Stack.h"


int main(){
    Stack<int> stack; 
    stack = {56,22,31}; 
    stack.print(); 

    cout<<"testing to function " << stack.Top() <<endl;
    stack.print(); 

    cout<< stack.pop() <<endl;
    stack.print(); 

    stack.clear(); 
    stack.print(); 

    return 0;
}
