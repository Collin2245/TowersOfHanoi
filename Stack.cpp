#include "Stack.hpp"
#include <stdlib.h>
#include <iostream>


Stack::Stack()
{
    this->top = NULL;
}

void Stack::push(int payload)
{
    Node* n = new Node(payload);
    if(top) //we have at least one elemet
    {
        n->setNextNode(top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    
}

int Stack::pop()
{
    int output = this->peek();

    Node* nodeToDelete = this->top;

    this->top = this->top->getNextNode();

    delete nodeToDelete;

    return output;
}

int Stack::peek()
{
    return this->top->getPayload();
}

void Stack::popThenPush(Stack* s)
{
    int newSpot = this -> peek();
    this->pop();
    s  -> push(newSpot);
}

void Stack::display()
{
    if(this->top)
    {
        Node * currNode = this->top;
        while(currNode)
        {
            std::cout<<currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout << "Empty stack" << "\n"; 
    }
    
}

void Stack::display3Stacks(Stack * s1, Stack * s2, Stack * s3)
{
    std::cout <<"-----Stack one-----"<< "\n";
    s1->display();
    std::cout <<"-----Stack two-----"<< "\n";
    s2->display();
    std::cout << "----Stack three------"<< "\n";
    s3->display();
    std::cout << "---------"<< "\n";
    
}