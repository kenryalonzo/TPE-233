#include <stdio.h>
#include <stdlib.h>
#include "pile_File.h"

int main(int arg, char* argv[]) {

    // Create two data structures: a stack and a queue
    DataStructure myStack = initialize(True);
    DataStructure myQueue = initialize(False);
    printDataStructure(myStack);
    // Push five elements onto the stack
    push(&myStack, 5);
    push(&myStack, 6);
    push(&myStack, 6);
    push(&myStack, 2);
    push(&myStack, 1);

    // Print the information about the stack
    printDataStructure(myStack);

    // Pop an element from the stack and print it
    int value = pop(&myStack);
    printf("The value popped from the stack is: %d\n", value);

    // Print the information about the stack after popping an element
    printDataStructure(myStack);

    push(&myQueue, 5);
    push(&myQueue, 6);
    push(&myQueue, 6);
    push(&myQueue, 2);
    push(&myQueue, 1);

    // Dequeue an element from the queue and print it
    value = dequeue(&myQueue);
    printf("The value dequeued from the queue is: %d\n", value);

    // Print the information about the queue after dequeuing an element
    printDataStructure(myQueue);

    return 0;
}