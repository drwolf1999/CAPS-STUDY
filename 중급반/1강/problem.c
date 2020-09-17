#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* NewNode(int data) {
    Node* ret = (Node*)malloc(sizeof(Node));
    ret->data = data;
    ret->link = NULL;
    return ret;
}

typedef struct List {
    int size;
    Node* cur;
    Node* HEAD;
} List;

List* NewList() {
    List* ret = (List*)malloc(sizeof(List));
    ret->size = 0;
    ret->HEAD = ret->cur = NULL;
    return ret;
}

List* list;
int N, M, K;

void erase() {
    Node* deleteNode = list->cur->link;
    list->cur->link = deleteNode->link;
    free(deleteNode);
    list->size--;
}

int main() {
    int i;
    scanf("%d %d %d", &N, &M, &K);
    if (N == 1) return !printf("1");
    // list 생성
    list = NewList();
    for (i = 1; i <= N; i++) {
        Node* newNode = NewNode(i);
        if (list->cur == NULL) { // 초기에 비어있으면 대입
            list->HEAD = list->cur = newNode;
            newNode->link = list->cur;
        }
        else { // 아니면 연결
            list->cur->link = newNode;
            list->cur = newNode;
            newNode->link = list->HEAD;
        }
        list->size++;
    }
    while (list->cur->link->data != M) list->cur = list->cur->link; // M의 전 값으로 이동
    printf("%d", list->cur->link->data); // cur에는 제거하는 item의 전 item이 담겨있음
    erase(); // 다음 노드 제거
    while (list->size > 0) { // list 가 비어있지 않을 때까지
        for (i = 0; i < K - 1; i++) list->cur = list->cur->link; // K - 1 칸 이동 (다음 노드는 제거되어 있기 때문)
        printf(" %d", list->cur->link->data); // cur에는 제거하는 item의 전 item이 담겨있음
        erase(); // 다음 노드 제거
    }
    return 0;
}