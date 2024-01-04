#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct NodeType {
	int data;
	struct Node* next;//Phóng lợn của một node.
}Node;

//Hạt nhân của list - luôn bắt đầu từ vị trí head để bắt đầu thao tác với list.
typedef struct LinkedListType {
	Node* head;
}LinkedList;

void init(LinkedList* list) {
	list->head = NULL;
}

Node* makeNode(int data) {
	Node *node = (Node*)malloc(MAX*sizeof(Node));
	node->data = data;
	node->next = NULL;
}

void insertHead(int data, LinkedList* list) {
	Node *newNode = makeNode(data);
	newNode->next = list->head;
	list->head = newNode;
}

/*void insertTail(int data, LinkedList* list) {
	Node* newNode = makeNode(data);
	Node* node = list->head;
	while (node->next != NULL)
		node = node->next;

	node->next = newNode;
	newNode->next = NULL;
}*/

void deleteHead(LinkedList* list) {
	Node* node = list->head;
	list->head = node->next;
	node->next = NULL;

	free(node);
}

void printList(LinkedList* list) {
	Node* node = list->head;
	while (node != NULL) {
		printf("Node address:: %p | ", &(node->data));
		printf("data: %d | ", node->data);
		printf("next node address = %p\n", node->next);
		node = node->next;
	}
	printf("\n");
}

int main() {
	LinkedList list;
	init(&list);

	for (int i = 0; i < 10; i++)
		insertHead(i, &list);

	printList(&list);
	
	//Xóa head (data = 9)
	deleteHead(&list);

	//Xóa head (data = 8)
	deleteHead(&list);

	printf("LIST SAU KHI XOA: \n");
	printList(&list);

	return 0;
}