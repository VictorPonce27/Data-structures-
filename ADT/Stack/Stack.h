#ifndef Stack_h 
#define Stack_h
using namespace std; 
#include "Node.h"

template<class T> 
class Stack{
private:
    int size; 
    Node<T> *top; 
public:
    Stack();
    Stack(initializer_list<T> e);
    void print(); 
    void push(T data); 
    T pop(); 
    T Top(); 
    int get_size(); 
    void clear(); 
};

template<class T> 
Stack<T>::Stack(){
    size = 0; 
    top = NULL;
}

template <class T>
Stack<T>::Stack(initializer_list<T> e){
    size = 0;
    top = NULL;  
    for(auto i:e){
        if(size == 0){
            top = new Node<T>(i,top); 
            size++; 
        }
        else{
            top = new Node<T> (i, top); 
            size++; 
        }
    }
}

template<class T> 
void Stack<T>::print(){
    Node<T> *aux = top; 
    while(aux!= NULL){
        cout<<aux->data<<" "; 
        aux = aux->next; 
    }
    cout<<endl;
}

template<class T> 
void Stack<T>::push(T data){
    top = new Node<T>(data, top); 
    size++; 
}

template<class T>
T Stack<T>::pop(){
    if(size != 0){
        Node<T> *aux = top->next; 
        T temp = top->data;  
        delete top; 
        top = aux; 
        size--; 
        return aux->data; 
    }
    throw runtime_error("list is empty");
}

template<class T> 
int Stack<T>::get_size(){
    return size; 
}

template<class T> 
void Stack<T>::clear(){
    Node<T> *aux = top->next; 
    while(top->next != NULL){
        top ->next = aux->next; 
        delete aux; 
        aux = top->next; 
    }
    top = NULL; 
    size = 0; 
    return; 

}

template<class T> 
T Stack<T>::Top(){
    return top->data; 
}

#endif //Stack_h 
