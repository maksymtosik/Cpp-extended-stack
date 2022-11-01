#include <iostream>
#define INITIAL_SIZE 5
class Stack {
    public:
        Stack();
        Stack(const Stack& stack);
        Stack& operator=(const Stack& stack);
        ~Stack();
        void push(int element);
        int pop();
        bool isEmpty();
        void printStack();
    private:
        int size;
        int top;
        int * data;
        void checkIfAllocable();
};
