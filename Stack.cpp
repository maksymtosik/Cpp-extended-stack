#include <iostream>
#include "Stack.h"

using namespace std;

#define SIZE 5

Stack::Stack() {
    this->size = SIZE;
    this->top = 0;
    this->data = (int *) malloc(sizeof(int) * SIZE);
    this->checkIfAllocable();
}

Stack::Stack(const Stack& stack)
{
    this->size = stack.size;
    this->data = (int*)malloc(this->size * sizeof(int));
    this->checkIfAllocable();
    copy(stack.data, stack.data + stack.size, this->data);
    this->top = stack.top;
}

Stack& Stack::operator=(const Stack& stack)
{
    if (this == &stack) {
        return *this;
    }
    if (this->size < stack.top) {
        free(this->data);
        this -> size = stack.size;
        this->data = (int*)malloc(this -> size * sizeof(int));
        if (this->data == NULL) {
        cout << "error during stack allocation" << endl;
        abort();
    }
    }
    copy(stack.data, stack.data + stack.top, this->data);
    this -> top = stack.top;
    return *this;
}

Stack::~Stack() {
    free(this->data);
    printf("Stack has been destroyed\n");
}

void Stack::push(int element) {
    const int growth_rate = 2;
    if (this->top >= this->size) {
        this->data = (int *) realloc(this->data, sizeof(int) * growth_rate * this->size);
        this->size *= growth_rate;
        this->checkIfAllocable();
        printf("Memory reallocated\n");
    }
    this->data[this->top++] = element;
}

int Stack::pop() {
    if (this->isEmpty() || this->data == NULL) {
        printf("Stack is empty!\n");
        abort();
    }
    this->top--;
    return this->data[this->top];
}

bool Stack::isEmpty() {
    this->checkIfAllocable();
    if (this->top > 0){
        return false;
    }else{
        return true;
    }
}

void Stack::printStack()
{
    if (isEmpty()) {
        cout << "Stack empty" << endl;
    }
    else {
        for (int i = this->top - 1; i >= 0; i--) {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
}

void Stack::checkIfAllocable() {
    if (this->data == NULL) {
        printf("Allocation error");
        abort();
    }
}
