#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        if (fast == slow) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}




int main() {
    struct ListNode* pa = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pb = (struct ListNode*)malloc(sizeof(struct ListNode));
    

    return 0;
}