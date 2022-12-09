#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for the node with data --> " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d)
{
    Node* newnode = new Node(d);
    if(tail == NULL)
    {
        newnode->next = newnode;
        tail = newnode;
    }
    else
    {
        Node* curr = tail;
        while ((curr->data != element))
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void deleteNode(Node* &tail, int value)
{
    // empty list 
    if(tail == NULL)
    {
        cout <<"List is empty please check again."<< endl;
    }
    else
    {
        //non empty assuminhg that teh value is present in the link list
        Node* prev = tail;
        Node* curr = prev->next;
        while (curr->data != value)
        {
           prev = curr;
           curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
        
    }
}

void printLinkedList(Node* &tail)
{
    Node* temp = tail;
    // do while isliye use lenge jisse woh ek baar atleast print ho
    //agar apn while use lenge toh sabse pehle hi condition false hop jayegi to isko overcome karne k liye apn do while use lenege
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail != temp);
    cout <<endl;
}

int main(){
    
    // Node* node1 = new Node(0);
    Node *tail = NULL;

    // printLinkedList(tail);

    cout <<"Insertion in circular linked list"<< endl;
    insertNode(tail,10, 25);//head
    printLinkedList(tail);
    insertNode(tail,25, 22);//head
    printLinkedList(tail);
    insertNode(tail,22, 26);//head
    printLinkedList(tail);
    insertNode(tail,26,42);//head
    printLinkedList(tail);
    insertNode(tail,25, 52);//head
    printLinkedList(tail);    
    deleteNode(tail,22);
    printLinkedList(tail);
    deleteNode(tail,25);
    printLinkedList(tail);
    deleteNode(tail,42);
    printLinkedList(tail);

    return 0;
}