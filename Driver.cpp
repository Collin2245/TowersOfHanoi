#include "Stack.hpp"
#include <iostream>


int main()
{
    Stack * stackOne = new Stack();
    Stack * stackTwo = new Stack();
    Stack * stackThree = new Stack();

    stackOne->push(3);
    stackOne->push(2);
    stackOne->push(1);

    

    std::cout<<"\n";

    stackOne->popThenPush(stackTwo);

    stackOne->display3Stacks(stackOne,stackTwo,stackThree);

    return 1;
}