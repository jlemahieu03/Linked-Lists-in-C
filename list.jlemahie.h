//
// Created by James on 9/19/2024.
//

#ifndef LINKED_LISTS_IN_C_LIST_JLEMAHIE_H
#define LINKED_LISTS_IN_C_LIST_JLEMAHIE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ListNodeStruct {
    void *data;
    struct ListNodeStruct *next;
} ListNode;

typedef int (* ComparisonFunction)(void *, void *);
    int compareString(char *string1, char *string2){
        if (string1 == NULL || string2 == NULL){
            printf("One of the strings given were a null pointer. Cannot compare strings.");
            return -3;
        }

        //comparing the two movie titles
        int compare = strcmp(string1, string2);

        //returning the correct value
        if (compare == -1)
            return -1;
        else if (compare == 0)
            return 0;
        else
            return 1;
    }

    int compareNumber(int number1, int number2){
        //making sure both movies are not null
        if (number1 == NULL || number2 == NULL){
            printf("One of the numbers given were a null pointer. Cannot compare numbers.");
            return -3;
        }

        //comparing audience value and returning correct value
        if (number1 < number2){
            return -1;
        } else if (number1 == number2){
            return 0;
        } else {
            return 1;
        }
    }
typedef void (* PrintFunction)(void *);


#endif //LINKED_LISTS_IN_C_LIST_JLEMAHIE_H

