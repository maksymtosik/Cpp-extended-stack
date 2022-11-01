#include "Stack.h"

using namespace std;

void printResults(Stack& modelStack, Stack& moddedStack);
void populateStacks(Stack& larger, Stack& smaller);
void copyTest();
void largerToSmaller();
void smallerToLarger();
void equalSize();
void fullToEmpty();
void toItself();
void runFunction1(Stack stack);
void runFunction2(Stack& stack);
void extendedTest();
void basicTest();

int main()
{
    extendedTest();
   // basicTest();
    return 0;
}

void extendedTest(){
    copyTest();
    largerToSmaller();
    smallerToLarger();
    equalSize();
    fullToEmpty();
    toItself();
    }

void copyTest()
{
    cout << "Copying stack test" << endl;
    Stack s1;
    for (int i = 0; i < INITIAL_SIZE - 1; i++) {
        s1.push(i);
    }

    Stack s2(s1);
    printResults(s1, s2);
}

void populateStacks(Stack& larger, Stack& smaller)
{
    for (int i = 0; i < INITIAL_SIZE  + 2; i++) {
        larger.push(i);
    }
    for (int i = 0; i < INITIAL_SIZE - 1; i++) {
        smaller.push(i);
    }
}

void printResults(Stack& modelStack, Stack& moddedStack)
{
    cout << "Model stack: " << endl;
    modelStack.printStack();
    cout << "Modified stack: " << endl;
    moddedStack.printStack();
    cout << endl;
}

void largerToSmaller()
{
    cout << "Assigning larger to smaller test" << endl;
    Stack larger, smaller;
    cout << "before:" << endl;
    populateStacks(larger, smaller);
    printResults(larger, smaller);
    smaller = larger;
    cout << "after:" << endl;
    printResults(larger, smaller);
}

void smallerToLarger()
{
    cout << "Assigning smaller to larger test" << endl;
    Stack larger, smaller;
    cout << "before:" << endl;
    populateStacks(larger, smaller);
    printResults(smaller, larger);
    larger = smaller;
    cout << "after:" << endl;
    printResults(smaller, larger);
}

void equalSize()
{
    cout << "Assigning stacks of equal size" << endl;
    Stack s1, s2;
    for (int i = 0; i < INITIAL_SIZE; i++) {
        s1.push(i);
        s2.push(INITIAL_SIZE - i);
    }
    cout << "before:" << endl;
    printResults(s1, s2);
    s2 = s1;
    cout << "after:" << endl;
    printResults(s1, s2);
}

void fullToEmpty()
{
    cout << "Assigning empty stack to stack with elements:" << endl;
    Stack nonEmpty, empty;
    for (int i = 0; i < INITIAL_SIZE; i++) {
        nonEmpty.push(i);
    }
    cout << "before:" << endl;
    printResults(empty, nonEmpty);
    nonEmpty = empty;
    cout << "after:" << endl;
    printResults(empty, nonEmpty);
}

void toItself()
{
    cout << "assigning stack to itself test" << endl;
    Stack s1;
    for (int i = 0; i < INITIAL_SIZE; i++) {
        s1.push(i);
    }
    cout << "before:" << endl;
    printResults(s1, s1);
    s1 = s1;
    cout << "after:" << endl;
    printResults(s1, s1);
}

void basicTest()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    Stack s2(s1);

    Stack s3 = s1;

    Stack s4;
    s4.push(10);
    s4 = s1;

    runFunction1(s1); 
    runFunction2(s1);
}

void runFunction1(Stack stack){
    stack.printStack();
    }
void runFunction2(Stack& stack){
    stack.printStack();
    }

