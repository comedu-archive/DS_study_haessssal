#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. �빮�� ���ĺ� > �ٷ� ���
2. ( > ���ÿ� push
3. ) > ( �� ���� ������ ���ÿ��� pop �ϸ鼭 ���
4. op > !is_empty / ( ������ ���� ������ �켱���� ���� �� ��� �� ���� ���� push
���� ���, + Ȥ�� - �� ��� * �� / �� ���ÿ��� pop �ϸ鼭 ��� �� + �� - �� push
*/

char stack[100];
int idx = -1;  //�̸� index �� �ϸ� �ȵ� ...<string.h> ���� �̹� ��ũ�� ���ǵǾ� �ֱ� ������

void push(char value) {
	stack[++idx] = value;
}

char pop() {
	if (idx < 0) return -1;
	else return stack[idx--];
}

int is_empty() {
	//if (idx < 0) return 1;
	//else return 0;
	//gpt ��: ��� ������ ��ο� ���� ��ȯ���� ���� ������ ���� �߻� ���� �Ʒ��� ���� �ۼ��ض�
	return idx < 0;
}

char peek() {
	if (is_empty() < 0) return -1;
	else return stack[idx];
}

int order(char op) {
	//0�� �ȵȴٱ淡 �ƹ� ���ڳ� ũ�� �񱳸� �ǵ��� �� �־���
	if (op == '(') return -1;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
}

int main() {
	char str[100]; 
	int i = 0;
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i]);
		}

		else if (str[i] == '(') {
			push(str[i]);
		}

		else if (str[i] == ')') {
			while (peek() != '(') {
				printf("%c", pop());
			}
			pop();
		}

		else {
			while (!is_empty() && order(peek()) >= order(str[i])) {
				printf("%c", pop());
			}
			push(str[i]);
		}
	}

	while (!is_empty()) {
		printf("%c", pop());
	}

	return 0;
}