/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 * THIS IS THE README FILE FOR LAB 4. */

/* By: Colin Peterman */

#include <stdlib.h>
#include <stdio.h>
#include "lab4.h"

int main(int argc, char **argv)
{
	/* Sets up variable to use */
	char *file_name;
	char *file_name2;
	Node *head = NULL;

	if (argc != 3){
		printf("Usage:  %s input_filename output_filename\n", argv[0]);
		return(1);
	}
	
	/* Gets the file names and then calls the methods to run the program */
	file_name = argv[1];
	file_name2 = argv[2];
	/* Gets all the data and builds the list */
	getDataAndBuildList(&head, file_name);
	/* Takes this created list and then asks the user for options to do with the list */
	getUserOption(&head, file_name2);
	return(0);
}

