#include "Node.hpp"

class Stack
{
    private:
        Node* top;

    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        void display();
        void popThenPush(Stack * s);
        void display3Stacks(Stack * s1, Stack *  s2, Stack  * s3);


};