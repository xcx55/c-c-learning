#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void ssap(int* aa, int i, int j) {
    while (i < j) {
        swap(aa + i, aa + j);
        i++;
        j--;
    }
}
void  fun(int* w, int  p, int  n)
{
    p %= n;
    ssap(w, 0, p - 1);
    ssap(w, p, n - 1);
    ssap(w, 0, n - 1);


}

int main(){
    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
    fun(arr,4,10);
    for (int i = 0; i < 10;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}