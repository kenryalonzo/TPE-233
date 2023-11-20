#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pile_File.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

void clear_screen() {
    system(CLEAR_SCREEN);
}

void closed() {
    printf("\n\n\t\t-------------------FINISH DEVELOPED BY GHOST-------------------------\n\n");
}

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

void push_Stack(DataStructure *ds, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = ds->head;
    ds->head = newNode;
    ds->size++;

    // Recalculate attributes after modifying the data structure
    ds->numElementsDiff = numElementsDiff(ds->head);
    ds->sum = ds->sum + value;
}

void push_Queue(DataStructure *ds, int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (!ds->head) {
        ds->head = newNode;
        ds->tail = newNode;
    } else {
        ds->tail->next = newNode;
        ds->tail = newNode;
    }

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

    printf("\n---------------------------------------\n\n");
    sleep(4);
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

//  ask the value of the choice in the structure

int get_value(){
    int value = 0;
    printf("Entrer votre valeur : \n");
    scanf("%d",&value);
    return value;
}

//  verify the choice structure

void verify_secondary_choice(int choice1) {
    if (choice1 < 1 || choice1 > 3) {
        printf("** Choix invalide! Veuillez choisir entre les options 1,2,3 **\n");
        sleep(2);
    }
}

// Fonctions de gestion du menu

int get_choice() {
    clear_screen();
    int choice;
    printf("** Menu pour le programme de manipulation de piles et de files **\n");
    printf("** Bienvenue ! **\n");
    printf("** En cas d'erreurs de manipulation des structures, le code -79 sera renvoyé à l'écran faisant office d'erreur. **\n");
    printf("** Que souhaitez-vous faire ? **\n");
    printf("** 1. Créer une structure de données (pile ou file) **\n");
    printf("** 2. Quitter le programme **\n");
    printf("** Saisissez votre choix : ");
    scanf("%d", &choice);
    return choice;
}

int choice_structure(int choice) {
    clear_screen();
    if (choice == 1) {
        printf("** 1. Pile **\n");
        printf("** 2. File **\n");
        printf("** Saisissez votre choix : ");
        scanf("%d", &choice);
        return choice;
    } else {
        return choice = 2;
    }   
}

int get_choice_for_stack(int choice) {
    clear_screen();
    if (choice == 1) {
        printf("Quelles operations voulez vous effectuer sur cette structure de données ? : **\n");
        printf("** 1. Empiler un element **\n");
        printf("** 2. Dépiler un element **\n");
        printf("** 3. Afficher votre pile **\n");
        printf("** Saisissez votre choix : ");
        scanf("%d", &choice);
    }
    return choice;
}

int get_choice_for_queue(int choice) {
    clear_screen();
    if (choice == 2) {
        printf("Quelles operations voulez vous effectuer sur cette structure de données ? : **\n");
        printf("** 1. Enfiler un element **\n");
        printf("** 2. Défiler un element **\n");
        printf("** 3. Afficher votre file **\n");
        printf("** Saisissez votre choix : ");
        scanf("%d", &choice);
    }
    return choice;
}

int checks_if_the_user_has_completed_their_action() {
    clear_screen();
    int yes_Or_no = 0; 
    printf("\n** voulez vous continuer cette action ? **\n");
    printf("**1. oui **\n");
    printf("**2. non **\n");
    scanf("%d", &yes_Or_no);
    return yes_Or_no;
}

void boucle_for_add_stack(int choice1, int choice2, DataStructure *ds) {
    int value = 0;
    if (ds->isStack == False) {
        printf("** Erreur : la structure de données n'est pas une pile. **\n");
        sleep(2);
        return;
    }

    if (choice2 != 1) {
        return;
    }
    value = get_value();
    printf("La valeur : %d, a été ajoutée à votre pile\n", value);
    push_Stack(ds, value);
    sleep(2);
}

void boucle_for_add_queue(int choice1, int choice2, DataStructure *ds) {
    int value = 0;
    if (ds->isStack) {
        printf("** Erreur : la structure de données n'est pas une file. **\n");
        sleep(2);
        return;
    }

    if (choice2 != 1) {
        return;
    }
    value = get_value();
    printf("La valeur : %d, a été ajoutée à votre file\n", value);
    push_Queue(ds, value);
    sleep(2);
}

//  for the stack

void for_choice_Structure_equal_one(int choice) {
    int second_choice = 0;
    int yes_Or_no = 0;
    int value = 0;

    DataStructure myStack;
    myStack = initialize(True);

    if (choice == 1){
        second_choice = get_choice_for_stack(choice);
        verify_secondary_choice(second_choice);

        repeat:
            if (choice == 1 && second_choice == 1) {        
                boucle_for_add_stack(choice, second_choice, &myStack);
                yes_Or_no = checks_if_the_user_has_completed_their_action();
                    if (yes_Or_no == 1) {
                        goto repeat;
                    } else {
                        second_choice = get_choice_for_stack(choice);
                    }
            }

        repeat1:
            if (choice == 1 && second_choice == 2) {
                value = pop(&myStack);
                printf("The value popped from the stack is: %d\n", value);
                sleep(2);

                yes_Or_no = checks_if_the_user_has_completed_their_action();
                if (yes_Or_no == 1) {
                        goto repeat1;
                } else {
                    second_choice = get_choice_for_stack(choice);
                }
            }

        if (choice == 1 && second_choice == 3) {
            printDataStructure(myStack);
                
        }
    }
}

//  for the queue

void for_choice_Structure_equal_two(int choice) {
    int second_choice = 0;
    int yes_Or_no = 0;
    int value = 0;

    DataStructure myQueue;
    myQueue = initialize(False);


    if (choice == 2){
        second_choice = get_choice_for_queue(choice);
        verify_secondary_choice(second_choice);

        repeat:
            if (choice == 2 && second_choice == 1) {        
                boucle_for_add_queue(choice, second_choice, &myQueue);
                yes_Or_no = checks_if_the_user_has_completed_their_action();
                    if (yes_Or_no == 1) {
                        goto repeat;
                    } else {
                        second_choice = get_choice_for_queue(choice);
                    }
            }

        repeat1:
            if (choice == 2 && second_choice == 2) {
                value = dequeue(&myQueue);
                printf("The value popped from the queue is: %d\n", value);
                sleep(2);

                yes_Or_no = checks_if_the_user_has_completed_their_action();
                if (yes_Or_no == 1) {
                        goto repeat1;
                    } else {
                        second_choice = get_choice_for_queue(choice);
                    }
            }

        if (choice == 2 && second_choice == 3) {
            printDataStructure(myQueue);
            
        }
    }
}

//  menu function

void menu() {

    // Initialisation des variables locales
    int choice = 0;
    int second_choice = 0;
    int choiceStructure = 0;
    int yes_Or_no = 0;
    int value = 0;

    DataStructure myStack;
    DataStructure myQueue;

    // Affichage du menu principal
    do {

        choice = get_choice();

        // Vérification du choix initial
        if (choice == 1) {
            choiceStructure = choice_structure(choice);
        } else if (choice == 2) {
            closed();
            break;
        } else {
            printf("** Choix invalide! Veuillez saisir 1 pour créer une pile ou 2 pour créer une file. **\n");
            sleep(2);
        }
        

        // Initialisation de la structure de données
        if (choice == 1 && choiceStructure == 1) {
            myStack = initialize(True);
            printf("--------------- Initialisation de la pile faite avec succès. ---------------\n");
            sleep(2);
        } else if (choice == 1 && choiceStructure == 2) {
            myQueue = initialize(False);
            printf("--------------- Initialisation de la file faite avec succès. ---------------\n");
            sleep(2);
        } else {
            continue;
        }
        
        if (choiceStructure == 1) {
            for_choice_Structure_equal_one(choice);
        } 
        if (choiceStructure == 2) { 
            for_choice_Structure_equal_two(choiceStructure);
        }

    } while (True);
    
}