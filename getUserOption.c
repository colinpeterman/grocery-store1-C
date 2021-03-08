/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 *  * THIS IS THE README FILE FOR LAB 4. */

/* By: Colin Peterman */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "lab4.h"
float revenue(Node *head){
	/* Calculates the Revenue */
	float revenue = 0;
	Node* traverse;
	traverse = head;
	while(traverse != NULL){
		revenue = revenue + (traverse->grocery_item.pricing.retailPrice * traverse->grocery_item.pricing.retailQuantity);
		traverse = traverse->next; 
	}
	setlocale(LC_NUMERIC,"");
	printf("Total Revenue: $%.2f\n",revenue);
	return revenue;
}

float wholesaleCost(Node* head){
	/* Calculates the Wholesale Cost */
	float cost = 0;
        Node* traverse;
        traverse = head;
        while(traverse->next != NULL){
                cost = cost + (traverse->grocery_item.pricing.wholesalePrice * traverse->grocery_item.pricing.wholesaleQuantity);
		traverse = traverse->next;
        }
        setlocale(LC_NUMERIC,"");
        printf("Total Wholesale Cost: $%.2f\n",cost);
        return cost;

}

float itemInvestment(Node* head){
	/* Calculates the item investment */
	float revenue = 0;
        Node* traverse;
        traverse = head;
        while(traverse->next != NULL){
                revenue = revenue + (traverse->grocery_item.pricing.wholesalePrice * (traverse->grocery_item.pricing.wholesaleQuantity - traverse->grocery_item.pricing.retailQuantity));
		traverse = traverse->next;
        }
        setlocale(LC_NUMERIC,"");
        printf("Total Item Investment: $%.2f\n",revenue);
        return revenue;
}

float profit(Node *head){
	/* Calculates the profit */
	float profit = revenue(head) - wholesaleCost(head) + itemInvestment(head);
	setlocale(LC_NUMERIC,"");
        printf("Total Profit: $%.2f\n",revenue);
        return profit;

}

float itemsSold(Node *head){
	/* Calculates the items sold */
	int sold = 0;
        Node* traverse;
        traverse = head;
        while(traverse != NULL){
                sold = sold + traverse->grocery_item.pricing.retailQuantity;
                traverse = traverse->next;
        }
        printf("Total Items Sold: %d\n", sold);
        return (float)sold;
}

float profitPerItem(Node *head){
	/* Calculates profit per item */
	float p = profit(head);
	float s = itemsSold(head);
	float profitPerItem = p/s;
	printf("Profit Per Item: $%.2f\n", profitPerItem);
	return profitPerItem;
}

float itemsInStock(Node *head){
	/* Finds items in stock and prints them out */
	Node* traverse;
        traverse = head;
	printf("Stock#\tQuantity\tDepartment\tItem");
        while(traverse != NULL){
                if(traverse->grocery_item.pricing.wholesaleQuantity - traverse->grocery_item.pricing.retailQuantity > 0){
			printf("%d\t%f\t%d\t%d",traverse->grocery_item.stockNumber,traverse->grocery_item.pricing.wholesaleQuantity - traverse->grocery_item.pricing.retailQuantity,traverse->grocery_item.department,traverse->grocery_item.item);
		}
                traverse = traverse->next;
        }
	printf("\n");
	return 0;
}

float itemsOutOfStock(Node *head){
	/* Finds items out of stock and prints them */
	Node* traverse;
        traverse = head;
        printf("Stock#\tQuantity\tDepartment\tItem");
        while(traverse != NULL){
                if(traverse->grocery_item.pricing.wholesaleQuantity - traverse->grocery_item.pricing.retailQuantity == 0){
                        printf("%d\t%f\t%d\t%d",traverse->grocery_item.stockNumber,traverse->grocery_item.pricing.wholesaleQuantity - traverse->grocery_item.pricing.retailQuantity,traverse->grocery_item.department,traverse->grocery_item.item);
                }
                traverse = traverse->next;
        }
	printf("\n");
	return 0;
}

float itemToInventory(Node *head){
	/* Prints out items in inventory, not completed */
	char department[50];
	scanf("Enter A Department: ",department);
}

int getUserOption(Node **head,char *file_name){
	/* Gets the user inputed option */
        FILE *output;
	int input = 0;
	int stockNum = 0;
	Node* newNodePtr;
	Node* traversePtr;
	float (*array[9])(Node*) = {revenue,wholesaleCost,itemInvestment,profit,itemsSold,profitPerItem,itemsInStock,itemsOutOfStock,itemToInventory};      
	while(input != 12){
		printf("\n1) Print Total Revenue");
		printf("\n2) Print Total Wholesale Cost");
		printf("\n3) Print Current Grocery Item Investment");
		printf("\n4) Print Current Profit");
		printf("\n5) Print Total Number of Grocery Items Sold");
		printf("\n6) Print Average Profit per Grocery Item");
		printf("\n7) Print Grocery Items in Stock");
		printf("\n8) Print Out of Stock Grocery Items");
		printf("\n9) Print Grocery Item to Inventory");
		printf("\n10) Add Grocery Items for a Department");
		printf("\n11) Delete Grocery Item from Inventory");
		printf("\n12) Exit Program");
		
		printf("\nOption: ");
		scanf("%d", &input);

		switch(input){
			case 1:
				array[0](*head);
				break;
			case 2:
				array[1](*head);
				break;
			case 3:
				array[2](*head);
				break;
			case 4:
				array[3](*head);
				break;
			case 5:
				array[4](*head);
				break;
			case 6:
				array[5](*head);
				break;
			case 7:
				array[6](*head);
				break;
			case 8:
				array[7](*head);
				break;
			case 9:
				array[8](*head);
				break;
			case 10:
				newNodePtr = (Node*)malloc(sizeof(Node*));
        			if (newNodePtr == NULL) {
                			printf("Storage not allocated");
        			}

				printf("\nEnter the grocery item: ");
				scanf(" %[^\n]", newNodePtr->grocery_item.item);
				printf("Enter the grocery department: ");
                        	scanf(" %[^\n]", newNodePtr->grocery_item.department);
				printf("Enter the stock number: ");
                        	scanf("%d", newNodePtr->grocery_item.stockNumber);
				printf("Enter the wholesale price: ");
                        	scanf("%f", newNodePtr->grocery_item.pricing.wholesalePrice);
				printf("Enter the retail price: ");
                        	scanf("%f", newNodePtr->grocery_item.pricing.retailPrice);
				printf("Enter the wholesale quantity: ");
                        	scanf("%d", newNodePtr->grocery_item.pricing.wholesaleQuantity);
				printf("Enter the retail quantity: ");				
                        	scanf("%d", newNodePtr->grocery_item.pricing.retailQuantity);
				insertNode(head,newNodePtr);
				break;
			case 11:
				newNodePtr = (Node*)malloc(sizeof(Node*));
                                if (newNodePtr == NULL) {
                                        printf("Storage not allocated");
                                }
				
				printf("Enter a stock ID to delete: ");
				scanf("%d", stockNum);
				traversePtr = *head;
				while(traversePtr != NULL){
					if(traversePtr->grocery_item.stockNumber == stockNum){
						
					}
				}
				break;
			case 12:
				traversePtr = *head;
				output = fopen(file_name,"w");
				while(traversePtr != NULL){
					fprintf(output, " %[^\n]", traversePtr->grocery_item.item);
                        		fprintf(output, " %[^\n]", traversePtr->grocery_item.department);
                        		fprintf(output, " %d", traversePtr->grocery_item.stockNumber);
                        		fprintf(output, " %f", traversePtr->grocery_item.pricing.wholesalePrice);
                        		fprintf(output, " %f", traversePtr->grocery_item.pricing.retailPrice);
                        		fprintf(output, " %d", traversePtr->grocery_item.pricing.wholesaleQuantity);
                        		fprintf(output, " %d", traversePtr->grocery_item.pricing.retailQuantity);
					traversePtr = traversePtr->next;
				}
				fclose(output); 
				break;
		}	
		
	}
	free(head);
	return 0;
}
