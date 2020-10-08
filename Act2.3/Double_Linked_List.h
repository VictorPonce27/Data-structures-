#ifndef Double_Linked_List_h
#define Double_Linked_list_h

#include "Node.h"

template<class T>
class Double_Linked_List{
private:
    int size;
    Node<T> *head;
    Node<T> *tail;
public:
    Double_Linked_List();
    Double_Linked_List(initializer_list<T> e);
    void add_first(T newData);
    void add_last(T newData);
    bool delete_at(int idex);
    bool is_empty();
    void insert_at(int index, T newData);
    T& operator[](int index);
    T get_data(int index);
    void update_at(int index, T newData);
    void print();
    void Print(); 
    void print_backwards();
    void clear();
    int get_size();
    void m_sort(int low,int mid, int high, Node<T> *nLeft, Node<T> *nMid, Node<T> *nRight);
    void sorti(int low, int high, Node<T> *nleft, Node<T> *nright);
    void sort();
    void operator=(Double_Linked_List<T> *e);
    void operator=(T *e);
    Node<T>* search(Node<T> *temp, int index);
};
template<class T>
Double_Linked_List<T>::Double_Linked_List(){
    size = 0;
    head = NULL;
    tail = NULL;
}

template<class T>
Double_Linked_List<T>::Double_Linked_List(initializer_list<T> e){
    size = 0;
    for(auto i:e){
        if(is_empty()){
            head = new Node<T>(i);
            tail = head;
            size++;
        }
        else{
            Node<T> *aux = head;
            while(aux->next !=NULL){
                aux = aux->next;
            }
            aux->next = new Node<T>(i,NULL,aux);
            tail = aux->next;
            size++;
        }
    }
}

template<class T>
void Double_Linked_List<T>::add_first(T newData){
    if(is_empty()){
         head = new Node<T>(newData);
         tail = head;
         size++;
    }
    else{
        head = new Node<T>(newData,head,NULL);
        head->next->prev = head;
        size++;
    }
}
template<class T>
void Double_Linked_List<T>::add_last(T newData){
    if(is_empty()){
        head = new Node<T>(newData);
        tail = head;
        size++;
    }
    else{
        tail = new Node<T>(newData,NULL,tail);
        tail->prev->next = tail;
        size++;
    }
}


template<class T>
bool Double_Linked_List<T>::is_empty(){
    return size == 0;
}

template<class T>
void Double_Linked_List<T>::Print(){
    Node<T> *aux = head;
    ofstream outfile; 
    outfile.open("OutPutFile.txt");
    while(aux != NULL){
        outfile << aux->data.Print();
        outfile <<"\n";
        aux = aux->next;
    }
    cout << endl;
    outfile.close();
}

template<class T>
void Double_Linked_List<T>::print(){
    Node<T> *aux = head;;
    while(aux != NULL){
        aux->data.print();
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
void Double_Linked_List<T>::print_backwards(){
    Node<T> *aux = tail;
    while(aux != NULL){
        cout<< aux->data<<" ";
        aux = aux->prev;
    }
    cout<<endl;
}

template<class T>
bool Double_Linked_List<T>::delete_at(int index){
    if(!is_empty()){
        if(size/2 >= index){
            int pos = 0;
            Node<T> *temp = head->next;
            if(pos == index && temp != NULL){
                delete head;
                head = temp;
                temp->prev = NULL;
                size--;
                return true;
            }
            else if(pos == index){
                head = NULL;
                tail = NULL;
                size--;
                return true;
            }
            else{
                Node<T> *aux = head;
                while(aux->next != NULL){
                    if(pos+1 == index){
                        if(aux->next->next != NULL){
                            Node<T> *temp = aux->next->next;
                            delete aux->next;
                            aux->next = temp;
                            temp->prev = aux;
                            size--;
                            return true;
                        }
                        else{
                            delete aux->next;
                            aux->next = NULL;
                            tail = aux;
                            size--;
                            return true;
                        }
                    }
                    aux = aux->next;
                    pos++;
                }
            }
        }
        else{
            int pos = size-1;
            Node<T> *temp = tail->prev;
            if(pos == index && temp != NULL){
                delete tail;
                tail = temp;
                temp->next = NULL;
                size--;
                return true;
            }
            else{
                Node<T> *aux = tail;
                while(aux->prev != NULL){
                    if(pos-1 == index){
                        if(aux->prev->prev != NULL){
                            Node<T> *temp = aux->prev->prev;
                            delete aux->prev;
                            aux->prev = temp;
                            temp->next = aux;
                            size--;
                            return true;
                        }
                        else{
                            delete aux->prev;
                            aux->prev = NULL;
                            head = aux;
                            size--;
                            return true;
                        }
                    }
                    aux = aux->prev;
                    pos--;
                }
            }
        }
    }
    return false;
}

template<class T>
void Double_Linked_List<T>::insert_at(int index, T newData){
    if ((index >= 0 || index < size) && size/2 >= index){
        int pos = 0;
        if (pos == index && pos == size){
            head = new Node<T>(newData, head, NULL);
            tail = head;
            size++;
            return;
        }
        else if(pos == index){
            head = new Node<T>(newData, head, NULL);
            head->next->prev = head;
            if(size < 1){
                tail = head->next;
            }
            size++;
            return;
        }
        else{
            Node<T> *aux = head;
            while (aux->next != NULL){
                if(pos + 1 == index && pos + 1 == size){
                    aux->next = new Node<T>(newData, aux->next, aux->prev);
                    tail = aux->next;
                    size++;
                    return;
                }
                else if (pos + 1 == index){
                    aux->next = new Node<T>(newData, aux->next, aux);
                    aux->next->next->prev = aux->next;
                    size++;
                    return;
                }
                aux = aux->next;
                pos++;
            }
        }
    }
    else if(index >= 0 || index < size){
        int pos = size;
        if (pos == index){
            tail = new Node<T>(newData,NULL,tail);
            tail->prev->prev->next = tail;
            size++;
            return;
        }
        else{
            Node<T> *aux = tail;
            while (aux->prev != NULL){
                if(pos - 1 == index){
                    aux->prev = new Node<T>(newData, aux, aux->prev);
                    aux->prev->prev->next = aux->prev;
                    size++;
                    return;
                }
                aux = aux->prev;
                pos--;
            }
        }
    }
    throw runtime_error("index is out of range");
}

template<class T>
T& Double_Linked_List<T>::operator[](int index){
    if(index>=0 || index <= size){
        if(size/2 > index){
            Node<T> *aux = head;
            int pos = 0 ;
            while(aux != NULL){
                if(pos == index){
                    return aux->data;
                }
            pos++;
            aux = aux->next;
            }
        }
        else{
            Node<T> *aux = tail;
            int pos = size-1;
            while(aux != NULL){
            if(pos == index){
                return aux->data;
            }
            pos--;
            aux = aux->prev;
            }
        }
    }
    throw out_of_range("index out of range");
}

template<class T>
void Double_Linked_List<T>::clear(){
     if(!is_empty()){
        Node<T> *aux = head->next;
        while(head->next!= NULL){
            head->next = aux->next;
            delete aux;
            aux = head->next;
        }
        delete head;
        head = NULL;
        tail = NULL;
        size = 0;
        return;
    }
    throw runtime_error("list is empty");
}

template<class T>
int Double_Linked_List<T>::get_size(){
    return size;
}


template<class T>
void Double_Linked_List<T>::operator=(Double_Linked_List<T> *e){
    clear();
    for(int i=0; i<e->size();i++){
        add_last(e[i]);
    }
}

template<class T>
void Double_Linked_List<T>::operator=(T *e){
    head->data = e;
}

template<class T>
void Double_Linked_List<T>::update_at(int index, T newData){
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
T Double_Linked_List<T>::get_data(int index){
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


template <class T>
void Double_Linked_List<T>::m_sort(int low,int mid, int high, Node<T> *nLeft, Node<T> *nMid, Node<T> *nRight){
    Queue<T> L;
    Queue<T> R;
    int i = 0;
    int j = 0;
    int n = mid-low +1;
    int m = high- mid;

    Node<T> *tempPos = nLeft;

    for(int i=0;i<n;i++){
        L.enqueue(nLeft->data);
        nLeft = nLeft->next;
    }

    for(int j=0;j<m;j++){
        R.enqueue(nMid->next->data);
        nMid = nMid->next;
    }

    while (i < n && j < m) {
        if (L.front()->data <= R.front()->data) {
            tempPos->data = L.dequeue();
            i++;
        }
        else {
            tempPos->data = R.dequeue();
            j++;
        }
        tempPos = tempPos->next;
    }

    while (i < n) {
        tempPos->data = L.dequeue();
        tempPos = tempPos->next;
        i++;
    }

    while (j < m) {
        tempPos->data = R.dequeue();
        tempPos = tempPos->next;
        j++;
    }

}

template <class T>
void Double_Linked_List<T>::sorti(int low, int high, Node<T> *nLeft, Node<T> *nRight){
    if(low<high){
        int mid = (low+high)/2;
        Node<T> *nMid = search(nLeft, mid-low);
        sorti(low,mid,nLeft, nMid);
        sorti(mid+1,high, nMid->next, nRight);
        m_sort(low,mid,high, nLeft, nMid, nRight);
    }
}
template<class T>
void Double_Linked_List<T>::sort(){
  sorti(0,size-1,head,tail);
}

template <class T>
Node<T>* Double_Linked_List<T>::search(Node<T> *temp, int index){
    Node<T> *aux = temp;
    for(int i=0; i<index; i++){
        aux = aux->next;
    }
    return aux;
}

#endif //Double_Linked_list_h
