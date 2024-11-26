#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value = 0) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* insertFirst(Node* head, int x);
    Node* insertLast(Node* head, int x);
    Node* insertBeforePos(Node* head, int x, int pos);
    Node* insertAfterPos(Node* head, int x, int pos);
    void print(Node* head);
    Node* insertIth(Node* head, int data, int pos);
};

// Detail function implementations

void LinkedList::print(Node* head) {
    cout << "\nList is: ";
    while (head != nullptr) {
        cout << " " << head->data;
        head = head->next;
    }
}

Node* LinkedList::insertFirst(Node* head, int x) {
    Node* temp = new Node(x);
    if (head != nullptr)
        temp->next = head;
    head = temp;
    return head;
}

Node* LinkedList::insertLast(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        return newNode;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

Node* LinkedList::insertIth(Node* head, int data, int pos) {
    Node* newNode = new Node(data);
    Node* curr = head;
    if (curr == nullptr)
        return head;
    for (int i = 1; i <= pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        delete newNode;
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* LinkedList::insertBeforePos(Node* head, int x, int key) {
    Node* newNode = new Node(x);
    Node* curr = head;
    if (curr == nullptr)
        return nullptr;
    if (curr->data == key) {
        newNode->next = curr;
        return newNode;
    }
    while (curr != nullptr) {
        if (curr->next && curr->next->data == key)
            break;
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

Node* LinkedList::insertAfterPos(Node* head, int x, int key) {
    Node* newNode = new Node(x);
    Node* curr = head;
    if (curr == nullptr)
        return head;
    while (curr != nullptr) {
        if (curr->data == key) {
            newNode->next = curr->next;
            curr->next = newNode;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

// Main function

int main() {
    LinkedList list;
    Node* head = nullptr;
    int n, i, x;
    cout << "How many numbers?\n";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter your number: ";
        cin >> x;
        head = list.insertFirst(head, x);
        list.print(head);
    }

    head = list.insertIth(head, -1, 2);
    list.print(head);
    head = list.insertIth(head, -2, 2);
    list.print(head);
    head = list.insertLast(head, 11);
    list.print(head);
    head = list.insertAfterPos(head, 12, 0);
    list.print(head);
    head = list.insertBeforePos(head, 12, 2);
    list.print(head);

    return 0;
}
