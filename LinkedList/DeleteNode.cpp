#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtHead(int value, Node *&head, Node *&tail)
{

    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(int value, Node *&head, Node *&tail)
{

    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
}

int getLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtPosition(int position, int value, Node *&head, Node *&tail)
{

    if (position == 1)
    {
        insertAtHead(value, head, tail);
    }
    else if (position == getLength(head) + 1)
    {
        insertAtTail(value, head, tail);
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        Node *forward = temp->next;
        temp->next = newNode;
        newNode->next = forward;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void deleteFromPosition(int position, Node *&head, Node *&tail)
{
    int len = getLength(head);
    if (position <= 0 || position > len)
    {
        cout << "Invalid position\n";
        return;
    }

    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    // Single node
    if (head == tail)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // Delete from head
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // Delete from tail
    if (position == len)
    {
        Node *temp = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        Node *nodetoDelete = temp->next;
        temp->next = NULL;
        tail = temp;
        delete nodetoDelete;
        return;
    }
    // Delete from middle
    Node *temp = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    Node *current = temp->next;
    Node *forward = current->next;
    temp->next = forward;
    current->next = NULL;
    delete current;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(10, head, tail);
    insertAtHead(20, head, tail);
    insertAtHead(30, head, tail);
    insertAtHead(40, head, tail);
    insertAtHead(50, head, tail);

    insertAtTail(80, head, tail);
    insertAtTail(90, head, tail);

    insertAtPosition(4, 110, head, tail);

    deleteFromPosition(1, head, tail);

    print(head);
}