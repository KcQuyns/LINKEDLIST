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
	Node* node = (Node*)malloc(MAX * sizeof(Node));
	node->data = data;
	node->next = NULL;
}

void insertHead(int data, LinkedList* list) {
	Node* newNode = makeNode(data);
	newNode->next = list->head;
	list->head = newNode;
}

void insertTail(int data, LinkedList* list) {
	Node* newNode = makeNode(data);
	Node* node = list->head;
	while (node->next != NULL)
		node = node->next;

	node->next = newNode;
	newNode->next = NULL;
}

void deleteHead(LinkedList* list) {
	Node* node = list->head;
	list->head = node->next;
	node->next = NULL;

	free(node);
}

void deleteTail(LinkedList* list) {
	Node* node = list->head;
	//tìm node tail:
	while (node->next != NULL)
		node = node->next;

	Node* tail = node;
	Node* node2 = list->head;
	while (node2->next != tail) {
		node2 = node2->next;
	}

	node2->next = NULL;
	free(tail);
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

	int arr[8] = { 2, 12, 9 , 0, 11, 3, 4, 8 };

	insertHead(arr[0], &list);
	for (int i = 1; i < 8; i++)
		insertTail(arr[i], &list);

	printf("\nLIST SAU KHI CHEN 2, 12, 9 , 0, 11, 3, 4, 8: \n");
	printList(&list);

	int x = 19;
	int y = -3;
	printf("\nCHEN 19 VAO DAU DANH SACH:\n");
	insertHead(x, &list);

	printf("\nLIST SAU KHI CHEN 19: \n");
	printList(&list);

	printf("\nCHEN -3 VAO CUOI DANH SACH:\n");
	insertTail(y, &list);

	printf("\nLIST SAU KHI CHEN -3: \n");
	printList(&list);

	printf("\nXOA 19 KHOI DAU DANH SACH:\n");
	deleteHead(&list);

	printf("\nLIST SAU KHI XOA 19: \n");
	printList(&list);

	printf("\nXOA -3 VAO CUOI DANH SACH:\n");
	deleteTail(&list);

	printf("\nLIST SAU KHI XOA -3: \n");
	printList(&list);

	return 0;
}