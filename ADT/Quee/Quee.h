#ifndef Quee_h
#define Quee_h 

#include "Node.h"

template <typename T>
class Quee{
private:
    int size; 
    Node<T> *head; 
    Node<T> *Tail; 

public:
   
    Quee(initializer_list<T> e); 
};

template <class T>
Quee<T>::Quee(initializer_list<T> e)
{
    size = 0;
    for (auto i : e)
    {
        if (is_empty())
        {
            head = new Node<T>(i);
            size++;
        }
        else
        {
            Node<T> *aux = head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = new Node<T>(i);
            size++;
        }
    }
}

#endif //Quee_h 
