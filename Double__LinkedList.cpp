#include <iostream>
using namespace std;
class Node
{
private:
public:
    // attributes
    int data;
    Node *next;
    Node *prev;
    // methods
    Node(int d)
    {
        next = prev = NULL;
        data = d;
    }
};

class DoubleLinkedList
{
public:
    void __print(Node *root);
    Node *__insertHead(Node *root, int data);
    Node *__insertTail(Node *root, int data);
    void __delwPosition(Node *root, int pos);
    void __delwValue(Node *root, int value);
};

void DoubleLinkedList::__print(Node *root)
{
    if (root == NULL)
        cout << "\nEmpty Linked List??";
    else
    {
        while (root != NULL)
        {
            cout << root->data << " ";
            root = root->next;
        }
        cout << "\n";
    }
}

Node *DoubleLinkedList::__insertHead(Node *root, int data)
{
    Node *_newNode = new Node(data);
    if (root == NULL)
    {
        root = _newNode;
    }

    else
    {
        _newNode->next = root;
        _newNode->prev = NULL;

        root->prev = _newNode;
        root = _newNode;
    }
    return root;
}
Node *DoubleLinkedList::__insertTail(Node *root, int data)
{
    Node *_newNode = new Node(data);
    if (root == NULL)
        return _newNode;
    Node *_curr = root;
    while (_curr->next != NULL)
    {
        _curr = _curr->next;
    }

    _newNode->prev = _curr;
    _curr->next = _newNode;
    return root;
}

void DoubleLinkedList::__delwPosition(Node *root, int pos) // Use Node *&root to modify root if head is deleted
{
    if (root == NULL) {
        cout << "\nEmpty LinkedList??";
        return;
    }

    Node *_curr = root;
    int _currPos = 1;

    // Traverse to the specified position
    while (_curr != NULL && _currPos < pos) {
        _curr = _curr->next;
        _currPos++;
    }

    // If position is invalid
    if (_curr == NULL) {
        cout << "\nNode at position " << pos << " does not exist.";
        return;
    }

    // Now, _curr is the node to delete
    if (_curr->prev != NULL) { // Not the head node
        _curr->prev->next = _curr->next;
    } else { // Deleting the head node
        root = _curr->next;
    }

    if (_curr->next != NULL) { // Not the last node
        _curr->next->prev = _curr->prev;
    }

    cout << "\nDeleted node data: " << _curr->data<<"\n";
    delete _curr; // Free the memory of the deleted node
}

void DoubleLinkedList::__delwValue(Node *root, int value)
{
}
int main()
{
    int number;
    Node *_DoubleLinkedList = NULL;
    DoubleLinkedList _list;
    cout << "\nInput number of LinkedList: ";
    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        _DoubleLinkedList = _list.__insertHead(_DoubleLinkedList, i);
    }
    _list.__print(_DoubleLinkedList);
    for (int i = 1; i <= number; i++)
    {
        _DoubleLinkedList = _list.__insertTail(_DoubleLinkedList, i + 10);
    }
    _list.__print(_DoubleLinkedList);
    _list.__delwPosition(_DoubleLinkedList, 10);
    _list.__print(_DoubleLinkedList);
    return 0;
}
