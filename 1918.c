#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. 대문자 알파벳 > 바로 출력
2. ( > 스택에 push
3. ) > ( 를 만날 때까지 스택에서 pop 하면서 출력
4. op > !is_empty / ( 만나지 않을 때까지 우선순위 높은 걸 출력 후 기존 것을 push
예를 들어, + 혹은 - 일 경우 * 와 / 를 스택에서 pop 하면서 출력 후 + 와 - 를 push
*/

char stack[100];
int idx = -1;  //이름 index 로 하면 안됨 ...<string.h> 에서 이미 매크로 정의되어 있기 때문에

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
	//gpt 왈: 모든 가능한 경로에 대한 반환문이 없기 때문에 에러 발생 따라서 아래와 같이 작성해라
	return idx < 0;
}

char peek() {
	if (is_empty() < 0) return -1;
	else return stack[idx];
}

int order(char op) {
	//0은 안된다길래 아무 숫자나 크기 비교만 되도록 값 넣어줌
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