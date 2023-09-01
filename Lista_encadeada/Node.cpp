#include<iostream>
#include "Node.h"

Node::Node(int val, Node *nextPtr){
    value = val;
    next = nextPtr;
}
int Node::getValue(){
    return value;
}
Node* Node::getNext(){
    return next;
}
void Node::setvalue(int newValue){
    value = newValue;
}
void Node::setNext(Node* newNext){
    next = newNext;
}