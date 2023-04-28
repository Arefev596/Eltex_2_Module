#pragma once

struct Node {
    int data;
    struct Node* pNext;
    struct Node* pPrev;
};
int sizeList;

void pushFront(struct Node** head, struct Node** tail, int new_data);

void pushBack(struct Node** head, struct Node** tail, int data);

void pushBtw(struct Node* prev_node, int data);

void editNode(struct Node** node, int new_data);

void delNode(struct Node** head, struct Node** tail, struct Node* del_node);

void printHead(struct Node* node);

void printTail(struct Node* node);

void bubble(struct Node** head, int size);

void combSort(struct Node** head, int size);
