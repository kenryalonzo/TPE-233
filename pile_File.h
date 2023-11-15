#ifndef __PILE__H__
#define __PILE__H__

typedef enum {

    False,

    True

}Bool;

typedef struct block {

    int value;
    struct block *next;
}list;


typedef struct pile_File
{
    list *head;
    list *tail;
    Bool pile_Or_File;
    int size, num_Elements_Diff, sum, min, max;
}whichType;

whichType initialize(Bool pile_Or_File);
int sum(list *head);
Bool exist(list *head, int value);
int num_Elements_Diff(list *head);
int minimum(list *head);
int maximum(list *head);
list *insertEnd(list *head, int value);
int length(list *head);

void print_This_Type(whichType thisType);

whichType empiler(whichType pile, int newValue);
whichType put_On(whichType file, int newValue);
int depiler_defiler(whichType *element);


#endif