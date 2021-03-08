/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 *  * THIS IS THE README FILE FOR LAB 4. */

/* By: Colin Peterman */

#include "lab4.h"
#include <stdlib.h>
#include <stdio.h>

int insertNode(Node **head,Node* newNodePtr){
	/* Sets up varaibles to use */
	Node *traversePtr;
	Node *priorNode;
	
	priorNode = *head;
	traversePtr = *head;
	/* Checks to see if the list is empty if so it then adds the node */
	if(*head == NULL){
		*head = newNodePtr;
		newNodePtr->next = NULL;
		return 0;
	}
	/* Checks to see if the item will be the first one and if so then adds it to the beggining */
	if(traversePtr->grocery_item.stockNumber > newNodePtr->grocery_item.stockNumber){
		newNodePtr->next = *head;
		*head = newNodePtr;
                return 0;	
	}
	/* If those two dont happen then it will either be inserted in the middle or end */
	traversePtr = traversePtr->next;
        while(traversePtr != NULL && traversePtr->grocery_item.stockNumber > newNodePtr->grocery_item.stockNumber){
			priorNode = traversePtr;
			traversePtr = traversePtr->next;
	}
	newNodePtr->next = traversePtr;
	priorNode->next = newNodePtr;
        return 0;
}

