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

typedef void (* PrintFunction)(void *);

int insertItem(ListNode **theList, void *data, ComparisonFunction compare);

void * findItem(ListNode *theList, void *item, ComparisonFunction compare);

void *removeItem(ListNode **theList, void *item, ComparisonFunction compare);

void *removeNthItem(ListNode **theList, int pos);

void *findNthItem(ListNode **theList, int pos);

int printList(ListNode *theList, PrintFunction print);
#endif //LINKED_LISTS_IN_C_LIST_JLEMAHIE_H

