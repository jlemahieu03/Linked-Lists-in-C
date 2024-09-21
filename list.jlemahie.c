//
// Created by James on 9/20/2024.
//
#include "list.jlemahie.h"

int insertItem(ListNode **theList, void *data, ComparisonFunction compare){
    //checking if list is null because that is the easiest case of insertion
    if (*theList == NULL){
        //allocating the size of the node to the list
        *theList = malloc(sizeof(ListNode));

        //assigning data to new node and then setting next to null
        (*theList)->data = data;
        (*theList)->next = NULL;
    } else if(compare(data, (*theList)->data) < 0) {
        ListNode *newNode = malloc(sizeof(ListNode));
        newNode->data = data;
        newNode->next = *theList;
        *theList = newNode;
    }

    else{
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
        if(compare(item, current->data) == 0){
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void *removeItem(ListNode **theList, void *item, ComparisonFunction compare){
    //making sure list isn't null
    if(*theList ==  NULL){
        return NULL;
    }

    ListNode *current = *theList;

    //removing from head of the list
    if(compare(current->data, item) == 0){
         //freeing the next pointer but returning the pointer to the data.
         ListNode *rmvNode = current;
         *theList = current->next;
         void *data = rmvNode->data;
         free(rmvNode);
         return data;
    }

    //checking the rest of the list
    while (current->next != NULL){
        if(compare(current->next->data, item) == 0){
            //making temporary pointer to node we want to remove
            ListNode *rmvNode = current->next;
            //setting current next pointer to the node we are reomving next
            current->next = rmvNode->next;
            //freeing the space of the nodes next pointer
            void *data = rmvNode->data;
            free(rmvNode);
            //returning the data
            return data;
        }
        //next node
        current = current->next;
    }


    //returning NULL is value isn't in list.
    return NULL;
}

void *removeNthItem(ListNode **theList, int pos){
    //checking is list is null
    if(*theList == NULL){
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
            void *data = rmvNode->data;
            free(rmvNode);
            return data;
        }
        count++;
        current = current->next;
    }

    return NULL;
}

void *findNthItem(ListNode **theList, int pos){
    //checking is list is null
    if(*theList == NULL){
        return NULL;
    }

    //setting current
    ListNode *current = *theList;

    //setting counter variable
    int count = 1;

    //finding and returning item in list.
    while(current->next != NULL){
        if (count == pos){
            return current->data;
        }
        count++;
        current = current->next;
    }

    return NULL;
}

int printList(ListNode *theList, PrintFunction print){
    if(theList == NULL){
        return 0;
    }
    ListNode *current = theList;

    //single node list
    if(current->next == NULL){
        print(current->data);
    }

    while(current->next != NULL){
        print(current->data);
        current = current->next;
    }
    //printing last item in list
    print(current->data);
    return 0;
}


