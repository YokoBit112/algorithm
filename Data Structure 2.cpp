#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using namespace std;

// ��������ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ɾ��ָ�� s ��ָ����ǰ�����
int deletePredecessor(Node* s) {
    if (s == NULL || s->next == s) {
        return 0;
    }

    Node* prev = s;
    Node* prevPrev = NULL;

    // �ҵ� s ��ǰ������ǰ�����
    while (prev->next != s) {
        prevPrev = prev;
        prev = prev->next;
    }

    // ��� s ��ǰ������ǰ��������
    if (prevPrev != NULL) {
        prevPrev->next = s;
        free(prev);
    }
    else {
        // ��� s ��ǰ������ǰ����㲻���ڣ�˵������ֻ�������ڵ�
        Node* temp = s->next;
        s->next = s;
        free(temp);
    }
}

// ��ӡ����
//��������ڵ㣬�ӽڵ����һ�ڵ㿪ʼ��ӡ�ڵ㵽�ڵ㱾��
void printList(Node* s) {
    Node* temp = s->next;
    while (temp != s)
    {
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

//����ֵΪm������ڵ�
//����һ��dataֵΪm��Node*�ڵ�
Node* findNode(Node* list, int m) {
    while (list->data != m)
    {
        list = list->next;
    }
    return list;
}
//��������ѭ������ͷָ������ڴ�������ʵ��ʹ��Ϊ��ͷָ������
//���ش��������ͷ�ڵ�
Node* createCircularList() {
    Node* head = NULL;
    Node* tail = NULL;
    int num;

    printf("����������ڵ��ֵ������ -1 �������룩��\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (head != NULL) {
        tail->next = head; // ʹ�����Ϊѭ������
    }

    return head;
}

int main() {
   
    Node* list = createCircularList();                   // ����һ���򵥵ĵ���ѭ������
    printf("����������Ϊ: "); printList(list);           //�����ӡ
    int m;cin >> m;                                     //��ȡҪɾ��ǰ���ڵ�Ľڵ��dataֵ
    deletePredecessor(findNode(list, m));               //���ҽڵ㲢ɾ���ڵ��ǰ���ڵ�
    printf("After deletion: ");printList(list);         //�����ӡ

    return 0;
}