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
	else{
		struct Node* currentNode = myList->headNode;
		while(currentNode->nextNode != NULL){
			currentNode = currentNode->nextNode;
			}
		currentNode->nextNode = newNode;
		myList->tailNode = newNode;
		return;
		}
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
	struct LinkedList my_list;
	struct Node node1 = {10};
	addNode(&node1, &my_list);
	struct Node node2 = {14};
	addNode(&node2, &my_list);
	struct Node node3 = {48};
	addNode(&node3, &my_list);
	struct Node node4 = {30};
	addNode(&node4, &my_list);

	printList(&my_list);
	printf("HEAD NODE: %d\n", my_list.headNode->value);
	printf("TAIL NODE: %d\n", my_list.tailNode->value);
}
