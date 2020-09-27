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
    //TODO:get_data, update_at, update_data
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
        if(head->data == data){
            Node<T> *temp = head->next; 
            delete head; 
            if(temp != NULL){
                head = new Node<T>(temp->data, temp->next); 
            }
            else{
                head = NULL;
            }
            size--; 
            delete temp; 
            return true; 
        }
        else{
            Node<T> *aux = head; 
            while(aux->next != NULL){
                if(aux->next->data == data){
                    if(aux->next->next != NULL){
                        Node<T> *temp = aux->next->next; 
                        delete aux->next; 
                        aux->next = new Node<T>(temp->data,temp->next); 
                        size--; 
                        return true;
                    }
                    else{
                        delete aux->next; 
                        aux->next = NULL; 
                        return true; 
                    }
                }
                aux = aux->next; 
            }
        }
    }
    return false; 
}

template<class T> 
bool LinkedList<T>::delete_at(int index){
    if(!is_empty()){
        int pos = 0; 
        if(pos == index){
            Node<T> *temp = head->next; 
            delete head; 
            if(temp != NULL){
                head = new Node<T>(temp->data, temp->next); 
            }
            else{
                head = NULL;
            }
            size--; 
            delete temp; 
            return true; 
        }
        else{
            Node<T> *aux = head; 
            while(aux->next != NULL){
                if(pos+1 == index){
                    if(aux->next->next != NULL){
                        Node<T> *temp = aux->next->next; 
                        delete aux->next; 
                        aux->next = new Node<T>(temp->data,temp->next); 
                        size--; 
                        return true;
                    }
                    else{
                        delete aux->next; 
                        aux->next = NULL; 
                        return true; 
                    }
                }
                pos++; 
                aux = aux->next; 
            }
        }
    }
    return false; 
}




#endif //LinkedList_h