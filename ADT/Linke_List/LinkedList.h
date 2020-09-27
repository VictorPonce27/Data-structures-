#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template<class T> 
class LinkedList{
private:
    int size; 
    Node<T>* head; 
public:
    LinkedList();
    LinkedList(int size, Node<T>* head); 
    void add_first(T data); 
    void add_last(T data); 
    void print(); 
    bool is_empty(); 
    //TODO: delete_data to work, make delete_at, get_data, update_at, update_data
    bool delete_data(T data); 
    bool delete_at(int index); 
    T& get_data(int index); 
    void update_at(T data, int index); 
    void update_data(T data, T newData); 


};

template<class T>
LinkedList<T>::LinkedList(){
    size = 0; 
    head = NULL; 
}

template<class T>
void LinkedList<T>::add_first(T data){
    head = new Node<T>(data, head);
    size++;  
}

template<class T> 
void LinkedList<T>::add_last(T data){
   if(is_empty()){
       head = new Node<T> (data); 
       size++; 
   }
    else{
        Node<T> *aux = head->next; 
        while(aux->next != NULL){
            aux = aux->next; 
        }
        aux -> next = new Node<T>(data); 
        size++; 
    }
}   

template<class T> 
void LinkedList<T>::print(){
    Node<T>* aux = head; 
   while(aux != NULL){
       cout<< aux->data <<" ";
       aux = aux->next;  
   }
    cout<<endl;
}

template<class T> 
bool LinkedList<T>::is_empty(){
    return head == NULL; 
}

template<class T> 
bool LinkedList<T>::delete_data(T data){
    if(!is_empty()){
        Node<T> *aux = head->next; 
        if(head->data == data){
            delete head; 
            head = new Node<T>(aux->data,aux->next); 
            size--; 
            delete aux; 
            return true; 
        }
        else{
            while(aux != NULL){
                if(aux->next->next->data == data){
                    if(aux->next->next->next != NULL){
                        delete aux->next;
                        aux->next = new Node<T>(aux->next->next->data, aux->next->next->next);
                        size--; 
                        return true; 
                    }
                    if(aux->next->next->next == NULL){
                        delete aux->next->next; 
                        aux->next = new Node<T>(aux->next->data); 
                        size--; 
                        return true; 
                    }
                }
                aux = aux->next; 
            }
        }
    }
    return false; 
}


#endif //LinkedList_h