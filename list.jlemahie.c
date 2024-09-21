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
        while(current->next != NULL && compare(data, current->next->data) > 0 ){
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

void *findItem(ListNode *theList, void *item, ComparisonFunction compare){
    //if list is empty return null
    if (theList == NULL){
        return NULL;
    }

    //setting current as the first node in list
    ListNode *current = theList;

    //looping through the list and comparing
    while (current != NULL){
        if(compare(item, current) == 0){
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void *removeItem(ListNode **theList, void *item, ComparisonFunction compare){
    //making sure list isn't null
    if(theList ==  NULL){
        return NULL;
    }

    //checking first node
    ListNode *current = *theList;
    if(compare(current,item) == 0){
         //freeing the next pointer but returning the pointer to the data.
         free(current->next);
         return current->data;
    }

    //checking the rest of the list
    while (current->next != NULL){
        if(compare(current->next, item) == 0){
            //making temporary pointer to node we want to remove
            ListNode *rmvNode = current->next;
            //setting current next pointer to the node we are reomving next
            current->next = rmvNode->next;
            //freeing the space of the nodes next pointer
            free(rmvNode->next);
            //returning the data
            return rmvNode->data;
        }
        //next node
        current = current->next;
    }
    //returning NULL is value isn't in list.
    return NULL;
}
void *removeNthItem(ListNode **theList, int pos){
    //checking is list is null
    if(theList == NULL){
        return NULL;
    }

    //setting current
    ListNode *current = *theList;

    //setting counter variable
    int count = 1;

    //removing item in list.
    while(current->next != NULL){
        if (count == pos - 1){
            ListNode *rmvNode = current->next;
            current->next =  rmvNode->next;
            free(rmvNode->next);
            return rmvNode->data;
        }
        count++;
        current = current->next;
    }

    return NULL;
}

