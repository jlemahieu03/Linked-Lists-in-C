//
// Created by James on 9/20/2024.
//
#include "list.jlemahie.h"

int insertItem(ListNode **theList, void *data, ComparisonFunction compare){
    //checking if list is null because that is the easiest case of insertion
    if (theList == NULL){
        //allocating the size of the node to the list
        *theList = malloc(sizeof(ListNode));

        //assigning data to new node and then setting next to null
        (*theList)->data = data;
        (*theList)->next = NULL;
    } else {
        //creating a current list node
        ListNode *current =  *theList;

        //looping through the list to find where the next item is greater than our current data
        while(compare(data, current->next->data) < 0){
            current = current->next;
        }

        //creating new node and inserting it into its sorted part of the list
        ListNode *newNode = malloc(sizeof(ListNode));
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
    return 0;
}