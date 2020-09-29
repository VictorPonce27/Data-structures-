#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){

    LinkedList<int> list;
    list = {51, 28, 21, 48, 25};
    list.print();
    list.sort(list, 0, list.get_size()-1);
    list.print();
    list.duplicate(); 
    list.print(); 
    list.clear(); 
    list.print(); 
    return 0;
}
