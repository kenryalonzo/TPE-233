#include <stdio.h>
#include <stdlib.h>
#include "pile_File.h"

whichType initialize(Bool pile_Or_File) {

    whichType types;

    types.head = types.tail = NULL;
    types.size = types.sum = types.num_Elements_Diff = 0;
    types.pile_Or_File = pile_Or_File;
    types.min = types.max = -1;

    return types;
}

//  Now we will write a function that sums the elements of a stack or a queue.

int sum(list *head) {

    int sums = 0;
    if (head == NULL)
        return 0;
    else
    {
        list *pile_File = head;
        while (pile_File != NULL) {
            sums += pile_File->value;
            pile_File = pile_File->next;
        }
        return sums;
    }
    
}

//  Let's try writing a function that tests whether an element belongs to a stack or a queue.

Bool exist(list *head, int value){

    if (head == NULL)
        return False;
    else
    {
        if (head->value == value)
            return True;
        return exist(head->next, value);
    }
}

//  Let's now move on to writing a function that allows you to insert elements at the end of the structure.

list *insertEnd(list *head, int value) {

    if (head == NULL) {
    
        list *newList = malloc(sizeof(*newList));
        newList->value = value;
        newList->next = NULL;
        return newList;
    } else
        head->next = insertEnd(head->next, value);
    
    return head; 
}

//  Here is the writing of a function which returns the number of different elements of a structure.Here is the writing of a function which returns the number of different elements of a structure.

int num_Elements_Diff(list *head) {

    int sums = 0;
    list *tempList = NULL;
    list *newTempList = head;

    while (newTempList != NULL) {

        if (exist(tempList, newTempList->value))
            newTempList = newTempList->next;
        else {
            tempList = insertEnd(tempList, newTempList->value);
            newTempList = newTempList->next;
        }    
    }
    return length(tempList);

}

//  And there is a function that returns the minimum of a structure.

int minimum(list *head) {

    if (head == NULL) 
        return -1;
    else
    {
        int min_Value = head->value;
        list *new = head->next;

        while (new != NULL) { 
            if (new->value < min_Value) {
                min_Value = new->value;
                new = new->next;
            }
        }
        return min_Value;
    }
    
}

//  On the other hand here it is rather the maximum that it returns.

int maximum(list *head) {

    if (head == NULL) 
        return -1;
    else
    {
        int max_Value = head->value;
        list *new = head->next;

        while (new != NULL) { 
            if (new->value > max_Value) {
                max_Value = new->value;
                new = new->next;
            }
        }
        return max_Value;
    }

}

//  Then we move on to the length of the structure.

int length(list *head) {

    int sums = 0;
    if (head == NULL)
        return 0;
    else {
        sums += 1;
        return sums + length(head->next);
    }

}

//  Small display function, for the elements of the structure.

void print_This_Type(whichType thisType) {

    list *pile_File = thisType.head;
    printf("\n--------------------------------------\n");

    if (thisType.pile_Or_File == True)
        printf("INFORMATION ON THE QUEUE: \n");
    printf("INFORMATION ON THE STACK : \n");

    printf("Size : %d    |    Number of different elements : %d    |    min : %d    |    max : %d   |    sum : %d \n", thisType.size, thisType.num_Elements_Diff, thisType.min, thisType.max, thisType.sum);
    printf("Content : \n");

    while (pile_File != NULL) {
        printf("%d ", pile_File->value);
        pile_File = pile_File->next;
    }
    printf("\n----------------------------------------\n");
        
}

//    STACK

whichType empiler(whichType pile, int newValue) {
    
    list *pile_File = malloc(sizeof(*pile_File));

    pile_File->value = newValue;
    pile_File->next = pile.head;

    pile.head = pile_File;
    pile.size++;
    pile.num_Elements_Diff = num_Elements_Diff(pile.head);
    pile.min = minimum(pile.head);
    pile.max = maximum(pile.head);
    pile.sum = pile.sum + newValue;

    return pile;
}

//   put on

whichType put_On(whichType file, int newValue) {

    list *stack = malloc(sizeof(*stack));
    stack->value = newValue;
    stack->next = NULL;

    if (file.head == NULL) {
        
        file.head = stack;
        file.tail = stack;
    } else {
        file.tail->next = stack;
        file.tail = stack;
    }

    file.size++;
    file.num_Elements_Diff = num_Elements_Diff(file.head);
    file.min = minimum(file.head);
    file.max = maximum(file.head);
    file.sum = file.sum + newValue;

    return file;
}

//  Remving in the stack or removing in the queue.

int depiler_defiler(whichType *element) {
    
    if (element->head != NULL) {
        
        int temp = element->head->value;
        list *stack = element->head;

        element->head = element->head->next;
        element->size--;
        element->num_Elements_Diff = num_Elements_Diff(element->head);
        element->min = minimum(element->head);
        element->max = maximum(element->head);
        element->sum = element->sum - stack->value;

        free(stack);

    }
    return -79;
    
}