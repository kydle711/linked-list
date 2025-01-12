//TODO

//1. add funtionality to insert node at specific indices
//2. reverse list
//3. one line creation of node while adding to list?





#include <stdio.h>

struct Node{
	int value;
	struct Node *nextNode;
	struct Node *prevNode;
	};

struct LinkedList{
	struct Node *headNode;
	struct Node *tailNode;
	};


void addNode(struct Node *newNode, struct LinkedList *myList){
	if(myList->headNode == NULL){
		newNode->nextNode = NULL;
		newNode->prevNode = NULL;
		myList->headNode = newNode;
		myList->tailNode = newNode;
		return;
	}
	if(myList->headNode == myList->tailNode){
		newNode->prevNode = myList->headNode;
		newNode->nextNode = NULL;
		myList->headNode->nextNode = newNode;
		myList->tailNode = newNode;
		return;
	}
	struct Node* currentNode = myList->headNode;
	while(currentNode->nextNode != NULL){
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = newNode;
	newNode->prevNode = currentNode;
	myList->tailNode = newNode;

}
// Prints the contents of the linked list
void printList(struct LinkedList *a_list){
	struct Node* currentNode = a_list->headNode;
	while(currentNode != NULL){
		printf("%d\n", currentNode->value);
		currentNode = currentNode->nextNode;
	}
}

int main(){
	struct LinkedList my_list = {NULL, NULL};
	
	struct Node node1 = {10};
	addNode(&node1, &my_list);
	
	struct Node node2 = {14};
	addNode(&node2, &my_list);
	
	struct Node node3 = {48};
	addNode(&node3, &my_list);
	
	struct Node node4 = {30};
	addNode(&node4, &my_list);
	
	struct Node node5 = {576};
        addNode(&node5, &my_list);
        
	struct Node node6 = {-23};
        addNode(&node6, &my_list);
        
	struct Node node7 = {777};
        addNode(&node7, &my_list);
        
	struct Node node8 = {12345};
        addNode(&node8, &my_list);
        
	struct Node node9 = {2};
        addNode(&node9, &my_list);
	
	struct Node node10 = {8};
	addNode(&node10, &my_list);


	printf("VALUE CHECK: %i\n", my_list.tailNode->prevNode->prevNode->value);
	printList(&my_list);
	printf("HEAD NODE: %d\n", my_list.headNode->value);
	printf("TAIL NODE: %d\n", my_list.tailNode->value);
}
