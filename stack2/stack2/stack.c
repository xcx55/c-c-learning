#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "stack.h"
#include <assert.h>

//void stackpush(sl*pa,datalist x) {
//	assert(pa);
//	if (pa->capacity==pa->top) {
//		int newcapacity = pa->capacity == 0 ? 4 : 2 * pa->capacity;
//		pa->arr = (datalist*)realloc(pa->arr,sizeof(datalist)*newcapacity);
//		assert(pa->arr);
//		pa->capacity = newcapacity;
//	}
//	pa->arr[pa->top] = x;
//	pa->top++;
//}
//void init(sl*pa) {
//	pa->arr = NULL;
//	pa->top = pa->capacity = 0;
//}
//void print(sl*pa) {
//	assert(pa->top&&pa);
//	for (int i = 0; i < pa->top;i++) {
//		printf("%d ",pa->arr[i]);
//	}
//	fprintf(stdout,"\n");
//}
//void stackpop(sl*pa) {
//	assert(pa&&pa->top);
//	(pa->top)--;
//}
//void stackdestroy(sl*pa) {
//	assert(pa);
//	pa->top = 0;
//	pa->capacity = 0;
//	datalist* pq = pa->arr;
//	pa->arr = NULL;
//	pa = NULL;
//	free(pq);
//}