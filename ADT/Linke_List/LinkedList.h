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
    LinkedList(initializer_list<T> e); 
    void add_first(T data); 
    void add_last(T data); 
    bool delete_data(T data); 
    bool delete_at(int index); 
    bool is_empty(); 
    T& get_data(int index); 
    void update_at(int index, T newData); 
    void update_data(T data, T newData); 
    int find_data(T data); 
    T& operator[](int index); 
    void print(); 

};

template<class T>
LinkedList<T>::LinkedList(){
    size = 0; 
    head = NULL; 
}

template<class T> 
LinkedList<T>::LinkedList(initializer_list<T> e){
    size = 0; 
    for(auto i:e){
        if(is_empty()){
        head = new Node<T>(i); 
        size++;  
        }
        else{
            Node<T> *aux = head; 
            while(aux->next!= NULL){
                aux = aux->next; 
            }
            aux->next = new Node<T>(i); 
            size++; 
        }
    }
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
    return size == 0; 
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

template<class T> 
T& LinkedList<T>::get_data(int index){
    Node<T> *aux = head; 
    int pos = 0; 
    while(aux != NULL){
        if(pos == index){
            return aux->data; 
        }
        aux = aux->next; 
        pos++; 
    }
    throw invalid_argument("value not found");
}

template<class T> 
void LinkedList<T>::update_data(T data, T newData){
    Node<T> *aux = head; 
    bool found = false; 
    while (aux!= NULL){
        if(aux->data == data){
            aux->data = newData;
            found = true; 
        } 
        aux = aux->next; 
    }
    if(found == false){
        throw invalid_argument("value not found");    
    }

}

template<class T> 
void LinkedList<T>::update_at(int index, T newData){
    Node<T> *aux = head; 
    int pos = 0;
    bool found = false; 
    while (aux!= NULL){
        if(pos == index){
            aux->data = newData;
            found = true; 
        }
        pos++; 
        aux = aux->next; 
    }
    if(found == false){
        throw invalid_argument("value not found");    
    }
}

template<class T> 
int LinkedList<T>::find_data(T data){
    Node<T> *aux = head; 
    int pos = 0; 
    while(aux!= NULL){
        if(aux->data == data){
            return pos;
        }
        pos++; 
        aux = aux->next; 
    }
    throw invalid_argument("value not found"); 
}

template<class T> 
T& LinkedList<T>::operator[](int index){
    Node<T> *aux = head; 
    int pos = 0; 
    while(aux != NULL){
        if(pos == index){
            return aux->data; 
        }
        pos++; 
        aux = aux->next; 
    }
    throw invalid_argument("index was not found"); 
}



#endif //LinkedList_h