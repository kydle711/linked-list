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


struct Node addValue(int new_value, int index, struct LinkedList *myList){
	struct Node newNode;
	newNode.value = new_value;
	if(myList->headNode == NULL){
		newNode.nextNode = NULL;
		newNode.prevNode = NULL;
		myList->headNode = &newNode;
		myList->tailNode = &newNode;
		return newNode;
		}
	struct Node *last_node = myList->headNode;
	struct Node *next_node = last_node->nextNode; 
	int i = 1;
	while(i < index && next_node != NULL){
		*last_node = *next_node;
		next_node = last_node->nextNode;
		i++;
		}
	if(next_node == NULL){
		last_node->nextNode = &newNode;
		myList->tailNode = &newNode;
		return newNode;
		}
	else{
		newNode.nextNode = next_node;
		newNode.prevNode = last_node;
		return newNode;
		}
}
//untested function
void printList(struct LinkedList *a_list){
	struct Node *currentNode = a_list->headNode;
	while(currentNode != NULL){
		printf("%d\n", currentNode->value);
		currentNode = currentNode->nextNode;
		}
}

int main(){
	// unsure if additional assignments are working without debugging
	struct LinkedList my_list;
	struct Node node1 = addValue(10, 3, &my_list);
	struct Node node2 = addValue(12, 1, &my_list);
	struct Node node3 = addValue(48, 1, &my_list);
	struct Node node4 = addValue(30, 1, &my_list);
	struct Node node5 = addValue(29, 2, &my_list);
	struct Node node6 = addValue(52, 1, &my_list);

	//This call had a seg fault
	//printList(&my_list);
	printf("HEAD NODE: %d\n", my_list.headNode->value);
	printf("TAIL NODE: %d\n", my_list.tailNode->value); //<- didnt print correct num
}
