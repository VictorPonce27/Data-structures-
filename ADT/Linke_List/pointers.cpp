#include <iostream>
using namespace std;

#include "Node.h"

int main(){
    
    Node<int>* node = new Node<int>(5); 
    node->data = 20; 
    cout << node->data<<endl;

    return 0;
}
