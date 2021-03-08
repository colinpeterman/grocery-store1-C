struct Cost {
	float wholesalePrice;
	float retailPrice;
	int wholesaleQuantity; 
	int retailQuantity;
};
struct Data {
	char item[50];
	char department[30]; 
	int stockNumber; 
	struct Cost pricing;
};
typedef struct Node {
	struct Data grocery_item;
	struct Node *next; 
} Node;


int getDataAndBuildList(Node **head, char *file_name);
int getUserOption(Node **head,char *file_name);
float revenue(Node *head);
float wholesaleCost(Node* head);
float itemInvestment(Node* head);
float profit(Node *head);
float itemsSold(Node *head);
float profitPerItem(Node *head);
float itemsInStock(Node *head);
float itemsOutOfStock(Node *head);
float itemToInventory(Node *head);
int insertNode(Node **head,Node* newNodePtr);
