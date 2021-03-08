/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 *  * THIS IS THE README FILE FOR LAB 4. */

/* By: Colin Peterman */

#include "lab4.h"
#include <stdlib.h>
#include <stdio.h>

int getDataAndBuildList(Node **head, char *file_name){
        /* Creates variables that we will use in this method */
	Node* newNodePtr;
	int i = 0;
	FILE *input_file;
	/* Creates space for the new node and opens up the input file */
        newNodePtr = (Node*)malloc(sizeof(Node));
        input_file = fopen(file_name, "r");
	/* Checks to make sure space was allocated */
        if (newNodePtr == NULL) {
                printf("Storage not allocated");
        }
        else {	
		/* Begins to read the data in from the file and storing it to the new node */
		while(fscanf(input_file, " %[^\n]", newNodePtr->grocery_item.item) != EOF){
			fscanf(input_file, " %[^\n]", newNodePtr->grocery_item.department);
			fscanf(input_file, " %d",&(newNodePtr->grocery_item.stockNumber));
			fscanf(input_file, " %f", &(newNodePtr->grocery_item.pricing.wholesalePrice));
			fscanf(input_file, " %f", &(newNodePtr->grocery_item.pricing.retailPrice));
			fscanf(input_file, " %d", &(newNodePtr->grocery_item.pricing.wholesaleQuantity));
			fscanf(input_file, " %d", &(newNodePtr->grocery_item.pricing.retailQuantity));
			/* Calls to insert the new node into the head */
			insertNode(head, newNodePtr);
			/* Possibly need to create a new node pointer */
		}
	}
	return 0;
}
