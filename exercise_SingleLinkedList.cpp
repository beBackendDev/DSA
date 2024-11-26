#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

//Create Linked List with value- which been user type
Node* __Init(Node* root, int x);
Node* __insertLast(Node* root, int x);
Node* __delDetailNode(Node* root, int x);
void __traversal(Node* root);
void __toReverse(Node* root);
void __print(Node* root);
//Search node with specific position and print on screen if search successful or
//print " dont exist position have value which you want to find"
void __searchNodeWithSpecificPos(Node* root, int pos);
//count and print Length of Linked List
int __countLengthLinkedList(Node* root);
//Delete node which have duplication
Node* __delDuplicateNode( Node* root);
Node* __sortLinkedList(Node*root);
void __middleNode(Node* root);
//------------------------------MAIN FUNCTION----------------------------------
int main(){
    Node* _baseLinkedList = new Node();
    _baseLinkedList = NULL;
    int _numValue = 0,x;
    cout<<"\nInput number of value: ";
    cin>>_numValue;
    cout<<"\nInput value:\n";
   for(int i = 0; i< _numValue; i++){
    cin>>x;
    _baseLinkedList =  __Init(_baseLinkedList, x);
    __print(_baseLinkedList);
   }
    cout<<"\n____Insert in last Position___\n";
   _baseLinkedList = __insertLast(_baseLinkedList, 11);
   __print(_baseLinkedList);
   cout<<"\n____Delete Node have value = 11___\n";
   _baseLinkedList = __delDetailNode(_baseLinkedList, 11);
   __print(_baseLinkedList);
    cout<<"\n____Traversal Linked List___\n";
   __traversal(_baseLinkedList);
    cout<<"\n____Reverse Liked List___\n";
   __toReverse(_baseLinkedList);
    cout<<"\n____Search node with Specific Position___\n";
   __searchNodeWithSpecificPos(_baseLinkedList, 5);
    cout<<"\n____Delete Duplicate Node___\n";
    _baseLinkedList = __delDuplicateNode(_baseLinkedList);
    __print(_baseLinkedList);
    cout<<"\n____Middle Node___\n";
    __middleNode(_baseLinkedList);
    delete _baseLinkedList;
    return 0;
}
//------------------------------MAIN FUNCTION----------------------------------
//deltail of function
void __print(Node* root){
    Node* _curr = root;
    if(_curr == NULL) cout<<"\n Empty Linked List??";

    while(_curr != NULL){
        cout<<_curr->data<<" ";
        _curr = _curr->next;
    }
    cout<<"\n";
}

void __traversal(Node* root){
    Node* _curr = root;
    if (_curr == NULL) cout<<"\nEmpty Linked List??";
    int position = 0;
    while (_curr != NULL){
        cout<<"\nPosition["<<position<<"] = "<< _curr->data;
        _curr = _curr->next;
        position +=1;
    }
}

//Create Linked List with n_value which is typed by user
Node* __Init(Node* root, int x){
    Node* _newNode = new Node();
    _newNode->data = x;
    _newNode->next = NULL;
    if (root != NULL)
        _newNode->next = root;
    root = _newNode;

    return root;
}

//
Node* __insertLast(Node* root, int x){
    Node* _curr = root;
    Node* _newNode = new Node();
    _newNode->data = x;
    _newNode->next = NULL;
    if (_curr == NULL) return _newNode;
    while(_curr->next != NULL){

        _curr = _curr->next;
    }

    _curr->next = _newNode;
    return root;
}

//
Node* __delDetailNode(Node* root, int x){
    if(root == NULL)return root;
    Node*_prevNode = NULL;
    Node *_curr = root;
    while(_curr != NULL){
        
        if (_curr->data == x) break;
        _prevNode = _curr;
        _curr = _curr->next;
    }
    _prevNode->next = _curr->next;
    _curr->next = NULL;
    return root;
}

//using Recursion to reVerse Linked List
void __toReverse(Node* root){
    Node* _curr = root;
    //if the node dont have value (NULL) -> recursion will beak and cout with value __toReverse(1) -> __toReverse(2) -> __toReverse(3)
    if (_curr == NULL) return;
    __toReverse(_curr->next);
    cout<<"\nValue: "<<_curr->data;
}
//
void __searchNodeWithSpecificPos(Node* root, int pos){
    Node* _cur = root;
    int _curPos = 0;
    int flag = 0;
    while (_cur != NULL){
        _curPos++;
        if (_curPos == pos){
            cout<<"\nNode have value: "<<_cur->data<<" is in Position: "<<pos;
            flag = -1;
            break;
        }
        _cur = _cur->next;
    }
    if (flag == 0) cout<<"\nValue isnt found??";
}

//
int __countLengthLinkedList(Node* root){
    Node* _cur = root;
    int length = 0;
    if (_cur == NULL) return 0;


    while(_cur != NULL){
        length+=1;
        _cur = _cur->next;
    }
    return length;

}
//
Node* __delDuplicateNode( Node* root){
    //check if Linked List is null-> return 
    if(root == NULL) return root;
    //using _curr to reversal linked list
    Node* _curr = root;
    while(_curr != NULL){
        Node* _curr1 = _curr;
        while(_curr1->next != NULL){
            if (_curr->data == _curr1->next->data){
                Node* _delNode = _curr1->next;
                _curr1->next = _curr1->next->next;
                delete _delNode;
            }
            else _curr1 = _curr1->next;
        }
        _curr = _curr->next;
    }
    return root;
}

void __middleNode(Node* root){
    //using array have datatype integer to store data of each node. 
    // using while loop to reversal linked list and each arr[i] = each node 
    //count length of linked list and divide for 2 to find out middle position
    if (root == NULL) cout<<"\nEmpty Linked List??";
    int i = 0;
    int arr[i];
    Node* _curr = root;
    while(_curr->next != NULL){
        arr[i] = _curr->data;
        i++;
        _curr = _curr->next;
    }
    int middle = i/2;
    cout<<"\nMiddle Node is: "<<arr[middle];

}

Node* __sortLinkedList(Node*root){
    if(root == NULL) return root;
    Node* _curr = root;
    while (_curr->next != NULL)
    {
        
        _curr = _curr->next;
    }
}