#ifndef Queue_h
#define Queue_h 

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
    Node<T>* front(); 
    T back(); 
    int get_size(); 
    void clear(); 
    void operator =(Queue<T> e); 
    // void operator =(Double_Linked_list<T> e); 
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
        aux->data.print();
        aux = aux->next; 
    }
    cout<<endl;
}

template<class T> 
T Queue<T>::dequeue(){
    if(size != 0){
        Node<T> *aux = head->next; 
        T temp = head->data ; 
        if(size == 1){
            size--; 
            head = NULL; 
            tail = NULL; 
            return temp; 
        }
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
        size++; 
    }
    else{
        Node<T> *aux = head; 
        while(aux->next != NULL){
            aux = aux->next; 
        }
        aux->next = new Node<T>(newData);
        tail = aux->next;
        size++; 
    }
}

template<class T> 
Node<T>* Queue<T>::front(){
    if(size!= 0){
        return head;
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
    if(size == 0){
       return;
    }
    else{
    Node<T> *aux = head->next; 
    while(head->next != NULL){
        head->next = aux->next; 
        delete aux;; 
        aux = aux->next; 
    }
    head = NULL;
    tail = NULL; 
    size = 0; 
    }
    return; 
}

template<class T> 
void Queue<T>::operator=(Queue<T> e){
    clear(); 
    for(int i=0; i<e.get_size();i++){
        enqueue(e.dequeue()); 
    }
}

// template<class T> 
// void Queue<T>::operator=(Double_Linked_list<T> e){
//     clear(); 
//     for(int i=0; i<e.get_size();i++){
//         enqueue(e->data)
//         e = e->next; 
//     }
// }
#endif //Queue_h 
