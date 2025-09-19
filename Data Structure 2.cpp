#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using namespace std;

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 删除指针 s 所指结点的前驱结点
int deletePredecessor(Node* s) {
    if (s == NULL || s->next == s) {
        return 0;
    }

    Node* prev = s;
    Node* prevPrev = NULL;

    // 找到 s 的前驱结点的前驱结点
    while (prev->next != s) {
        prevPrev = prev;
        prev = prev->next;
    }

    // 如果 s 的前驱结点的前驱结点存在
    if (prevPrev != NULL) {
        prevPrev->next = s;
        free(prev);
    }
    else {
        // 如果 s 的前驱结点的前驱结点不存在，说明链表只有两个节点
        Node* temp = s->next;
        s->next = s;
        free(temp);
    }
}

// 打印链表
//传入链表节点，从节点的下一节点开始打印节点到节点本身
void printList(Node* s) {
    Node* temp = s->next;
    while (temp != s)
    {
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

//查找值为m的链表节点
//返回一个data值为m的Node*节点
Node* findNode(Node* list, int m) {
    while (list->data != m)
    {
        list = list->next;
    }
    return list;
}
//创建单向循环链表，头指针仅用于创建链表，实际使用为无头指针链表
//返回创建链表的头节点
Node* createCircularList() {
    Node* head = NULL;
    Node* tail = NULL;
    int num;

    printf("请输入链表节点的值（输入 -1 结束输入）：\n");
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
        tail->next = head; // 使链表成为循环链表
    }

    return head;
}

int main() {
   
    Node* list = createCircularList();                   // 创建一个简单的单向循环链表
    printf("创建的链表为: "); printList(list);           //链表打印
    int m;cin >> m;                                     //获取要删除前驱节点的节点的data值
    deletePredecessor(findNode(list, m));               //查找节点并删除节点的前驱节点
    printf("After deletion: ");printList(list);         //链表打印

    return 0;
}