#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *head;
	Node *tail;
} Queue;

Node *createNode(int value);
Node *dequeue(Queue *queue);
void enqueue(Queue *queue, int value);
void printQueue(Queue *queue);

int main() {
	Queue *queue = malloc(sizeof(Queue));
	
	enqueue(queue, 10);
	enqueue(queue, 20);

	for(int i = 0; i < 30; i++) {
		enqueue(queue, i * 10);
	}

	printQueue(queue);

	Node *node = dequeue(queue);

	while(node) {
		printf("val: %d\n", node->value);
		free(node);
		node = dequeue(queue);
	}

	printQueue(queue);

	printf("Hello, world\n");
	return 1;
}

void printQueue(Queue *queue) {
	Node *node = queue->head;

	if (node == NULL) {
		printf("Queue is empty!\n");
		return;
	}

	while(node) {
		printf("%d, ", node->value);
		node = node->next;
	}
	printf("\n");
}	

Node *createNode(int value) {

	Node *new = malloc(sizeof(Node));
	new->value = value;

	return new;
}

Node *dequeue(Queue *queue) {

	
	if (queue->head == NULL) {
		return NULL;
	}
	
	Node *dequeuedNode = queue->head;
	queue->head = dequeuedNode->next;
	dequeuedNode->next = NULL;

	if (queue->head == NULL) {
		queue->tail = NULL;
	}

	return dequeuedNode;
}


void enqueue(Queue *queue, int value) {
	
	Node *newNode = createNode(value);

	if (queue->head == NULL) {
		queue->head = newNode;
		queue->tail = newNode;
	} else {
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
}
