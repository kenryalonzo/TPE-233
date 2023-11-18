#include <stdio.h>
#include <stdlib.h>
#include "pile_File.h"

DataStructure initialize(Bool isStack) {
    DataStructure ds;
    ds.head = NULL;
    ds.tail = NULL;
    ds.isStack = isStack;
    ds.size = 0;
    ds.numElementsDiff = 0;
    ds.sum = 0;
    ds.min = -1;
    ds.max = -1;
    return ds;
}

//  Now we will write a function that sums the elements of a stack or a queue.

int sum(Node *head) {
    int sum = 0;

    if (!head) {
        return 0;
    }

    Node *current = head;

    printf("Starting to calculate sum...\n");

    while (current) {
        printf("Current node value: %d\n", current->value);
        sum += current->value;
        current = current->next;
    }

    printf("Sum of values: %d\n", sum);

    return sum;
}

//  Let's try writing a function that tests whether an element belongs to a stack or a queue.

Bool exists(Node *head, int value) {
    if (!head) {
        return False;
    }

    Node *current = head;
    while (current) {
        if (current->value == value) {
            return True;
        }

        current = current->next;
    }

    return False;
}

//  Let's now move on to writing a function that allows you to insert elements at the end of the structure.

Node *insertEnd(Node *head, int value) {
    if (!head) {
        Node *newNode = malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }

    head->next = insertEnd(head->next, value);
    return head;
}

//  Now we are write a function that supp an element of the structure

void freeList(Node *head) {
    if (head) {
        freeList(head->next);
        free(head);
    }
}

//  Here is the writing of a function which returns the number of different elements of a structure.Here is the writing of a function which returns the number of different elements of a structure.

int numElementsDiff(Node *head) {
    int count = 0;
    Node *tempList = NULL;
    Node *newTempList = head;

    while (newTempList != NULL) {
        if (exists(tempList, newTempList->value))
            newTempList = newTempList->next;
        else {
            tempList = insertEnd(tempList, newTempList->value);
            newTempList = newTempList->next;
            count++;
        }
    }

    freeList(tempList);
    return count;
}

//  And there is a function that returns the minimum of a structure.

int minimum(Node *head) {
    if (!head) {
        return -1;
    }

    int minValue = head->value;
    Node *current = head->next;

    while (current) {
        if (current->value < minValue) {
            minValue = current->value;
        }

        current = current->next;
    }

    return minValue;
}

//  On the other hand here it is rather the maximum that it returns.
int maximum(Node *head) {
    if (!head) {
        return -1;
    }

    int maxValue = head->value;
    Node *current = head->next;

    while (current) {
        if (current->value > maxValue) {
            maxValue = current->value;
        }

        current = current->next;
    }

    return maxValue;
}

//  Then we move on to the length of the structure in add new value to the structure.

void push(DataStructure *ds, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = ds->head;
    ds->head = newNode;
    ds->size++;

    // Recalculate attributes after modifying the data structure
    ds->numElementsDiff = numElementsDiff(ds->head);
    ds->sum = ds->sum + value;
}

//  Small display function, for the elements of the structure.

void printDataStructure(DataStructure ds) {
    Node *current = ds.head;
    printf("\n--------------------------------------\n");

    if (ds.isStack == True) {
        printf("INFORMATION ON THE STACK:\n");
    } else {
        printf("INFORMATION ON THE QUEUE:\n");
    }

    printf("Size: %d\n", ds.size);
    printf("Number of different elements: %d\n", ds.numElementsDiff);

    // Separate variables for minimum and maximum values
    int minValue = minimum(ds.head);
    int maxValue = maximum(ds.head);

    printf("Min: %d\n", minValue);
    printf("Max: %d\n", maxValue);
    printf("Sum: %d\n", ds.sum);
    printf("Content: \n");

    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
}

//   pop one element from the structure

int pop(DataStructure *ds) {
    if (!ds->head) {
        return -79;
    }

    int value = ds->head->value;
    Node *oldHead = ds->head;
    ds->head = ds->head->next;
    free(oldHead);

    ds->size--;

    // Recalculate attributes after modifying the data structure
    ds->numElementsDiff = numElementsDiff(ds->head);
    ds->min = minimum(ds->head);
    ds->max = maximum(ds->head);
    ds->sum = ds->sum - value;

    return value;
}

//  Remving element in the queue.

int dequeue(DataStructure *ds) {
    if (!ds->head) {
        return -79;
    }

    int value = ds->head->value;
    if (ds->head->next == NULL) {
        ds->head = NULL;
    } else {
        ds->head = ds->head->next;
    }

    ds->size--;

    // Recalculate attributes after modifying the data structure
    ds->numElementsDiff = numElementsDiff(ds->head);
    ds->min = minimum(ds->head);
    ds->max = maximum(ds->head);
    ds->sum = ds->sum - value;

    return value;
}