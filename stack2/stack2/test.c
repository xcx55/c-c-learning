#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "stack.h"
#include<assert.h>
//int main() {
//	sl peer;
//	init(&peer);
//	stackpush(&peer,2);
//	stackpush(&peer, 3);
//	stackpush(&peer, 4);
//	stackpush(&peer, 5);
//	print(&peer);
//	stackpop(&peer);
//	stackpop(&peer);
//	stackpop(&peer);
//	print(&peer);
//	stackdestroy(&peer);
//	return 0;
//}
typedef struct stack {
	char* arr;
	int top;
	int capacity;
}stack;

void stackpush(stack* pa, char x) {
	if (pa->top == pa->capacity) {
		int newcapacity = pa->capacity == 0 ? 4 : 2 * pa->capacity;
		pa->arr = (char*)realloc(pa->arr, newcapacity * sizeof(char));
		pa->capacity = newcapacity;
	}
	pa->arr[pa->top++] = x;

}
void stackpop(stack* pa) {
	assert(pa->top);
	pa->top--;
}
void init(stack* pa) {
	pa->top = pa->capacity = 0;
	pa->arr = NULL;
}
char ccer(char x) {
	if (x==')') {
		return '(';
	}
	else if (x==']') {
		return '[';
	}
	else if (x=='}') {
		return '{';
	}
}
bool isValid(char* s) {
	stack* pa = (stack*)malloc(sizeof(stack));
	init(pa);
	while (*s) {
		if (*s == '(' || *s == '[' || *s == '{') {
			stackpush(pa, *s);
		}
		else if (*s == ')' || *s == ']' || *s == '}') {
			if (pa->top == 0) {
				return false;
			}
			if (pa->arr[pa->top-1] == ccer(*s)) {
				stackpop(pa);
			}
		}
		else {
			return false;
		}
		s++;
	}
	if (pa->top == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	char arr[4] = { '(',')','}','\0' };
	bool a = isValid(arr);
}