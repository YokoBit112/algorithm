#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct pa {
    int num1;
    int num2;
    struct pa* next;
} pa;

void se(pa* head) {
    pa* current = head;
    pa* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
pa* sa(int nums[], int k) {
    pa* head = NULL;
    pa* tail = NULL;
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (nums[i] + nums[j] == k) {
                pa* newPair = (pa*)malloc(sizeof(pa));
                if (newPair == NULL) {
                    printf("�ڴ����ʧ�ܣ�\n");
                    se(head);
                    return NULL;
                }
                newPair->num1 = nums[i];
                newPair->num2 = nums[j];
                newPair->next = NULL;
                if (head == NULL) {
                    head = newPair;
                    tail = newPair;
                }
                else {
                    tail->next = newPair;
                    tail = newPair;
                }
            }
        }
    }
    return head;
}
int main() {
    int nums[10];
    printf("������10��������\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &nums[i]);
    }
    int k;
    printf("������ֵk��\n");
    scanf("%d", &k);

    pa* result = sa(nums, k);
    if (result != NULL) {
        printf("���ں�Ϊ%d����ϣ�����������£�\n", k);
        while (result != NULL) {
            printf("(%d, %d)\n", result->num1, result->num2);
            pa* temp = result;
            result = result->next;
            free(temp);
        }
    }
    else {
        printf("�����в����ں�Ϊ%d�����\n", k);
    }

    return 0;
}