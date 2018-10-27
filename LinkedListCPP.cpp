#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// You should use templates when you do not know what type of data will be
// stored in List
template<typename T>
// In Node we store value of a current node and a pointer for next node
struct Node {
    T data;
    Node* nextNode;
};

template<typename T>
// This class is responsible for creating, inserting and deleting nodes or
// values in our List
class List{
private:
    Node<T>* listHead;
    Node<T>* listTail;
public:
    List() :listHead(nullptr), listTail(nullptr) {}
    void createNode(T value);
    void insertValue(T value);
    void insertValueAtPosition(int pos, T value);
    void deleteFirstElement();
    void deleteLastElement();
    void deleteElementAtPosition(int pos);
    void showElementsOfList();
};

template<typename T>
void List<T>::createNode(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = value;
    tmp->nextNode = nullptr;

    if (listHead == nullptr) {
        listHead = tmp;
        listTail = tmp;
        
        tmp = nullptr;
    } else {
        listTail->nextNode = tmp;
        listTail = tmp;
    }
}

template<typename T>
void List<T>::insertValue(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = value;
    tmp->nextNode = listHead;
    listHead = tmp;
}

template<typename T>
void List<T>::insertValueAtPosition(int pos, T value)
{
    int i;
    Node<T>* pre = new Node<T>;
    Node<T>* current = new Node<T>;
    Node<T>* tmp = new Node<T>;

    current = listHead;

    for ( i = 1; i < pos; i++) {
        if(current==NULL)
            break;
        pre = current;
        current = current->nextNode;
    }
   if(pos-i>1)
   {
       cout<<"Position out of reach";
   }
    else if(pos-i==1)//when element is to be inserted at end
    {
        tmp->data=value;
        listTail->next=tmp;
        listTail=tmp;
    }
    else
    {
    tmp->data = value;
    pre->nextNode = tmp;
    tmp->nextNode = current;
    }
}

template<typename T>
void List<T>::deleteFirstElement()
{
    Node<T>* tmp = new Node<T>;
    tmp = listHead;
    if(listHead==listTail)
    {
        listHead=NULL;listTail=NULL;
        delete(tmp);
    }
    else{
    listHead = listHead->nextNode;
    
    delete tmp;
    }
}

template<typename T>
void List<T>::deleteLastElement()
{
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;

    current = listHead;

    while (current->nextNode != nullptr) {
        previous = current;
        current = current->nextNode;
    }
    if(current==listHead)
    {
        Node<T>*temp=listHead;
        listHead=NULL;listTail=NULL;
        delete(temp);
    }
    else
    {
    listTail = previous;
    previous->nextNode = nullptr;
    
    delete current;
    }
}

template<typename T>
void List<T>::deleteElementAtPosition(int pos)
{
    Node<T>* current=listHead;Node<T>*prev;//taking that first nodeis at position zero
    for(int i=0;i<pos-1;i++)
    {
        
        if(current==NULL)
        {
            cout<<"Position out of reach";
            break;
        }
       prev=current; 
       current=current->nextNode; 
    }
    if(current!=NULL)
    {
        if(current==listHead)
        {
            listHead=current->nextNode;
            
        }
        else if(current==listTail)
        {
            listTail=prev;
            prev->nextNode=current->nextNode;
        }
        else
        {
        prev->nextNode=current->nextNode;
        }
        delete(current);
        
    }
       
}

template<typename T>
void List<T>::showElementsOfList()
{
    Node<T>* tmp ;
    tmp = listHead;

    while (tmp != nullptr) {
        std::cout<<tmp->data<<"\n";
        tmp = tmp->nextNode;
    }
}

int main()
{
    List<int> objList;
    objList.createNode(21);
    objList.createNode(37);
    objList.createNode(14);
    objList.createNode(88);

    objList.showElementsOfList();

    return 0;
}
