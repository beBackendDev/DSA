#include <iostream>
using namespace std;
// define size of Stack with Array
#define MAX 10
// we have two types of the stack: fixed size(array), dynamic size(linked list)
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack_LinkedList
{
public:
    // insert an element onto the stack
    void __Push(int data);
    // delete an element from the stack
    void __Pop(int data);
    // return a top element of the stack
    void __Top();
    // print top element but dont pop
    void __Peek(int data);
    // check if stack is null
    bool __IsEmpty();
    // check if stack is full
    bool __IsFull();
};

class Stack_Array
{
    // index of the Stack
    int _top;

public:
    int array[MAX]; // Maximum size of Stack

    Stack_Array() { _top = -1; }
    // insert an element onto the stack
    bool __Push(int data);
    // delete an element from the stack
    int __Pop();
    // return a top element of the stack
    int __Top();
    // print top element but dont pop
    int __Peek();
    // check if stack is null
    bool __IsEmpty();
    // check if stack is full
    bool __IsFull();
};

bool Stack_Array::__Push(int data)
{
    // check if stack is full
    if (_top >= (MAX - 1))
    {
        cout << "\nStack overflow";
        return false;
    }
    array[++_top] = data;
    cout << data << " is pushed in stack\n";
    return true;
}

int Stack_Array:: __Pop(){
    if(_top < 0){
        cout<<"\nStack is Empty??";
        return 0;
    }
    int x = array[_top];
    _top--;
    return x;
}

int Stack_Array:: __Peek(){
        if(_top < 0){
        cout<<"\nStack is Empty??";
        return 0;
    }
    int x = array[_top];
    return x;

}

bool Stack_Array:: __IsEmpty(){
    if (_top < 0) return true;
    else return false;
}
int main()
{
    Stack_Array _stArr;
    int _num;
    cout<<"\nInput your size of stack: ";
    cin>>_num;
    for(int i = 1; i<= _num; i++){
        _stArr.__Push(i);
    }
    int _delElem = _stArr.__Pop();
    cout<<"\nElement "<<_delElem<<" is popped";
    cout<<endl;
    while (!_stArr.__IsEmpty()){
        
        cout<<_stArr.__Peek()<<" ";
        _stArr.__Pop();
    }
    return 0;
}