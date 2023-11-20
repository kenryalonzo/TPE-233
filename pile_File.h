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

int get_value();
int get_choice();
int choice_structure(int choice);
int get_choice_for_stack(int choice);
int get_choice_for_queue(int choice);
int checks_if_the_user_has_completed_their_action();
void boucle_for_add_stack(int choice1, int choice2, DataStructure *ds);
void boucle_for_add_queue(int choice1, int choice2, DataStructure *ds);
void verify_secondary_choice(int choice1);
void for_choice_Structure_equal_one(int choice);
void for_choice_Structure_equal_two(int choice);

void clear_screen();
void closed();
void menu();

#endif