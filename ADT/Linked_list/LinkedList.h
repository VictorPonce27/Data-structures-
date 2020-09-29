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
    //TODO: duplicate, remove_duplicates, operator =, reverse;
    int find_data(T data); 
    int get_size(); 
    T& operator[](int index); 
    void print(); 
    void insert_at(int index, T newData); 
    void clear();
    void m_sort(LinkedList<T> &list, int low, int mid, int high);
    void sort(LinkedList<T> &list, int low, int high);
    void duplicate(); 
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
    else if(head->next == NULL){
       head->next = new Node<T>(data); 
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
int LinkedList<T>::get_size(){
    return size; 
}


template<class T> 
bool LinkedList<T>::delete_data(T data){
    if(!is_empty()){
        if(head->data == data){
            Node<T> *temp = head->next; 
            delete head; 
            if(temp != NULL){
                head->data = new Node<T>(temp->data, temp->next); 
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

//TODO: try to facilitate the search values (if statement with the size of the lined list)
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
    throw out_of_range("value not found");
}

template<class T> 
void LinkedList<T>::update_data(T data, T newData){
    Node<T> *aux = head; 
    bool found = false; 
    while (aux!= NULL){
        if(aux->data == data){
            aux->data = newData;
            return; 
        } 
        aux = aux->next; 
    }
    throw runtime_error("value not found");    

}

template<class T> 
void LinkedList<T>::update_at(int index, T newData){
    Node<T> *aux = head; 
    int pos = 0;
    bool found = false; 
    while (aux!= NULL){
        if(pos == index){
            aux->data = newData;
            return;  
        }
        pos++; 
        aux = aux->next; 
    }
        throw runtime_error("value not found");    
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
    throw runtime_error("value not found"); 
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
    throw out_of_range("index was not found"); 
}

template<class T> 
void LinkedList<T>::insert_at(int index, T newData){
    if(index >= 0 || index <size){
        int pos = 0; 
        bool found = false; 
        if(pos == index){
            head = new Node<T>(newData, head); 
            size++; 
            return; 
        }
        else{
            Node<T> *aux = head; 
            while(aux->next != NULL){
                if(pos+1 == index){
                    aux->next = new Node<T>(newData, aux->next);
                    size++;
                    return; 
                }
                pos++; 
                aux = aux->next; 
            }
        }
            throw out_of_range("out of range"); 
        }
}

template<class T>
void LinkedList<T>::clear(){
    if(!is_empty()){
        Node<T> *aux = head->next; 
        while(head->next!= NULL){
            head->next = aux->next; 
            delete aux; 
            aux = head->next;
        }
        head = NULL; 
        size = 0; 
        return; 
    }
    throw runtime_error("list is empty"); 
}

template<class T> 
void LinkedList<T>::m_sort(LinkedList<T> &list, int low, int mid,int high ){
    LinkedList<T> L;
    LinkedList<T> R;
    int i=0;
    int j=0;

    int pos = low;

    int n = mid-low +1;
    int m = high- mid;

    for(int i=0;i<n;i++){
        L.add_last(list[low+i]);
    }
    for(int j=0;j<m;j++){
        R.add_last(list[mid+1+j]);
    }

    while(i<n && j<m){

        if(L[i] <= R[j]){
            list[pos] = L[i];
            i++;
        }
        else{
            list[pos] = R[j];
            j++;
        }
        pos++;
    }
    while(i<n){
        list[pos] = L[i];
        i++;
        pos++;
    }
    while(j<m){
        list[pos] = R[j];
        j++;
        pos++;
    }

}

template <class T>
void LinkedList<T>::sort(LinkedList<T> &list, int low, int high){
    if(low<high){
        int mid = (low+high)/2;

        sort(list, low, mid);
        sort(list, mid + 1, high);
        m_sort(list,low,mid,high);

    }
}

template<class T> 
void LinkedList<T>::duplicate(){
    if(!is_empty()){
        Node<T> *aux = head;
        for(int i=0; i<=size;i++){
            if(i%2 == 0){
                if(aux->next == NULL){
                    aux->next = new Node<T>(aux->data); 
                    size++; 
                    return; 
                }
                else{
                insert_at(i, aux->data); 
                aux = aux->next; 
                }
            }
        }
    }
    throw runtime_error("list is empty"); 
}




#endif //LinkedList_h