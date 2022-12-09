#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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
// insertion
void insertAtHead(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if(tail == NULL)
    {
        insertAtHead(tail,d);
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    Node* temp = head;
    Node* newnode = new Node(d);
    int count = 1;
    if(position == 1)
    {
        insertAtHead(head,d);
        return;
    }
    while (count < position-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    // cout <<"Temp data while insert @ position " << temp->data << endl;
    // cout <<"Temp data while insert @ position " << temp->next->data << endl;
    newnode->next = temp->next;
    temp->next = newnode;
}

//deletion
void deletionOfNode(int position, Node* &head, Node* &tail)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete  temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL; 

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//length of a linked list 
int lengthofLinkedList(Node* &head)
{
    int count = 1;
    Node* temp = head;
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//Display or traversing
void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;

    printLinkedList(head);

    cout <<"Insert At Head"<< endl;
    insertAtHead(head, 25);//head
    printLinkedList(head);
    insertAtHead(head, 35);//head
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;

    cout <<"\nInsert At Tail"<< endl;
    insertAtTail(tail,12);//tail
    printLinkedList(head);
    insertAtTail(tail,22);//tail
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;

    cout <<"\nInsert At Position"<< endl;
    insertAtPosition(head,tail,1,1000);//position
    printLinkedList(head);
    insertAtPosition(head,tail,7,2000);//position
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;

    cout <<"\nDeletion of Node"<< endl;
    deletionOfNode(1,head,tail);
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;
    cout <<"\nThe Length of a Linked List is: " << lengthofLinkedList(head) << endl;
    deletionOfNode(6,head,tail);
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;
    cout <<"\nThe Length of a Linked List is: " << lengthofLinkedList(head) << endl;
    deletionOfNode(4,head,tail);
    printLinkedList(head);
    cout <<"Head data : "<< head->data << endl;
    cout <<"Tail data : "<< tail->data << endl;


    cout <<"\nThe Length of a Linked List is: " << lengthofLinkedList(head) << endl;
    return 0;
}