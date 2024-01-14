#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* next;
} node;

typedef struct queue {
	node* front;
	node* rear;
	int size;
} queue;

queue* create() {
	queue* que = malloc(sizeof(queue));

	if (que == NULL) {
		printf("Not enough memory");
		exit(EXIT_FAILURE);
	}

	que->size = 0;
	que->front = NULL;
	que->rear = NULL;

	return que;
}

node* new_node(const int data) {
	node* another = malloc(sizeof(node));

	if (another == NULL) {
		printf("Not enough memory");
		exit(EXIT_FAILURE);
	}

	another->data = data;
	another->next = NULL;

	return another;
}

bool is_empty(const queue* que) {
	return que == NULL || que->rear == NULL;
}

void enqueue(queue* que, const int a1) {
	int input = a1 - '0';  // 문자 입력을 정수로 변환
	node* n = new_node(input);

	if (que->size == 0) {
		que->front = n;
		que->rear = n;
	}
	else {
		que->rear->next = n;
		que->rear = n;
	}

	que->size++;
}

void dequeue(queue* que) {
	if (que->size == 0) {
		printf("Queue is empty\n");
		que->front = NULL;
		que->rear = NULL;
	}
	else {
		node* del = que->front;
		int data = del->data;

		que->front = que->front->next;
		// front에 front 다음에 있던 녀석이 오도록

		free(del);
		que->size--;

	}
}

int peek(const queue* que) {
	if (is_empty(que)) return 0;
	return que->front->data;
}

int size(const queue* que) {
	if (is_empty(que)) return 0;
	return que->size;
}

void print(queue* que) {
	node* a2 = que->front;

	if (is_empty(que)) {
		printf("Queue is empty\n");
		return;
	}

	for (int i = 0; i < que->size; i++) {
		printf("%d\n", a2->data);
		a2 = a2->next;
	}
}

bool is_full(const queue* que) {
	return false;
}

// main 함수 GPT에게
int main() {
	queue* myQueue = create();  // 큐 생성

	char input[999];

	while (1) {
		scanf("%s", input);

		int data;
		switch (input[0]) {
		case '+':
			enqueue(myQueue, input[1]);
			break;

		case '-':
			if (!is_empty(myQueue)) {
				printf("Dequeue: %c\n", peek(myQueue));
				dequeue(myQueue);
			}
			else {
				printf("Queue is empty.\n");
			}
			break;

		case 'P':
			if (!is_empty(myQueue)) {
				printf("Peek: %d\n", peek(myQueue));
			}
			else {
				printf("Queue is empty.\n");
			}
			break;

		case 'L':
			print(myQueue);
			break;

		case 'F':
			printf("Is Full: %s\n", is_full(myQueue) ? "true" : "false");
			break;

		case 'E':
			printf("Is Empty: %s\n", is_empty(myQueue) ? "true" : "false");
			break;

		case '0':
			printf("Exiting the program.\n");
			// Additional tasks like memory deallocation can be performed here if needed
			return 0;

		default:
			printf("Invalid choice! Please enter a valid option.\n");
		}
	}

	return 0;
}