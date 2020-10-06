#ifndef Quee_h
#define Quee_h 

#include "Node.h"

template <typename T>
class Queue{
private:
    int size; 
    Node<T> *head; 
    Node<T> *tail; 

public:
    Queue();
    Queue(initializer_list<T> e); 
    void print(); 
    T dequeue(); 
    void enqueue(T newData); 
    T front(); 
    T back(); 
    int get_size(); 
    void clear(); 
    void operator = (Double_Linked_List *e); 
};


template<class T> 
Queue<T>::Queue(){
    size = 0; 
    head = NULL; 
    tail = NULL; 
}

template <class T>
Queue<T>::Queue(initializer_list<T> e){
    size = 0;
    for (auto i : e){
        if (size == 0){
            head = new Node<T>(i);
            tail = new Node<T>(i); 
            size++;
        }
        else
        {
            Node<T> *aux = head;
            while (aux->next != NULL){
                aux = aux->next;
            }
            delete tail; 
            aux->next = new Node<T>(i);
            tail = new Node<T>(i);
            size++;
        }
    }
}

template<class T> 
void Queue<T>::print(){
    Node<T> *aux = head; 
    while (aux!= NULL){
        cout<<aux->data<<" "; 
        aux = aux->next; 
    }
    cout<<endl;
}

template<class T> 
T Queue<T>::dequeue(){
    if(size != 0){
        Node<T> *aux = head->next; 
        T temp = head->data ; 
        delete head; 
        head =  aux; 
        size--; 
        return temp;
    }
    throw runtime_error("list is empty"); 
}

template<class T> 
void Queue<T>::enqueue(T newData){
    if(size == 0){
        head = new Node<T>(newData);
        tail = head; 
    }
    else{
        Node<T> *aux = head; 
        while(aux->next != NULL){
            aux = aux->next; 
        }
        aux->next = new Node<T>(newData);
        tail = aux->next;
    }
    size++; 
}

template<class T> 
T Queue<T>::front(){
    if(size!= 0){
        return head->data;
    }
    throw runtime_error("quee is empty"); 
}

template<class T> 
T Queue<T>::back(){
    if(size!= 0){
        return tail->data; 
    }
    throw runtime_error("quee is empty"); 
}

template<class T> 
int Queue<T>::get_size(){
    return size; 
}

template<class T> 
void Queue<T>::clear(){ 
    Node<T> *aux = head->next; 
    while(head->next != NULL){
        head->next = aux->next; 
        delete aux;; 
        aux = aux->next; 
    }
    head = NULL;
    tail = NULL; 
    size = 0; 
    return; 
}


#endif //Quee_h 
