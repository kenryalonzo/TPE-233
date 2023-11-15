#include <stdio.h>
#include <stdlib.h>
#include "pile_File.h"

int main(int arg, char* argv[]) {

    whichType myStack = initialize(False);
    whichType myQueue = initialize(True);

    myStack = empiler(myStack, 5);
    myStack = empiler(myStack, 6);
    myStack = empiler(myStack, 6);
    myStack = empiler(myStack, 2);
    myStack = empiler(myStack, 1);

    print_This_Type(myStack);

    myQueue = put_On(myQueue, 5);
    myQueue = put_On(myQueue, 6);
    myQueue = put_On(myQueue, 6);
    myQueue = put_On(myQueue, 2);
    myQueue = put_On(myQueue, 1);

    print_This_Type(myQueue);

    depiler_defiler(&myStack);
    depiler_defiler(&myQueue);

    print_This_Type(myStack);
    print_This_Type(myQueue);

    int temp;

    return 0;
}