#ifndef __PILE__H__
#define __PILE__H__

typedef enum {
    False,
    True
} Bool;

typedef struct Node {
    int value;
    struct Node *next;
} Node;


typedef struct DataStructure {
    Node *head;
    Node *tail;
    Bool isStack;
    int size;
    int numElementsDiff;
    int sum;
    int min;
    int max;
} DataStructure;

DataStructure initialize(Bool isStack);
int sum(Node *head);
Bool exists(Node *head, int value);
int numElementsDiff(Node *head);
int minimum(Node *head);
int maximum(Node *head);
Node *insertEnd(Node *head, int value);
void freeList(Node *head);

void printDataStructure(DataStructure ds);

void push_Stack(DataStructure *ds, int value);
void push_Queue(DataStructure *ds, int value);
int pop(DataStructure *ds);
int dequeue(DataStructure *ds);


#endif