#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "Header.h"

void pushFront(struct Node** head, struct Node** tail, int new_data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("Ошибка выделения памяти!");
        exit(1);
    }
    tmp->data = new_data;
    tmp->pNext = (*head);
    tmp->pPrev = NULL; // NULL было 
    if ((*head) != NULL)
    {
        (*head)->pPrev = tmp;
    }
    (*head) = tmp;
    while ((*head)->pNext != NULL)
    {
        (*head) = (*head)->pNext;
    }
    *tail = *head;
    *head = tmp;
    sizeList++;
}

void pushBack(struct Node** head, struct Node** tail, int data)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("Ошибка выделения памяти!");
        exit(1);
    }
    tmp->data = data;
    tmp->pNext = NULL;
    struct Node* temp = *head;
    if (*head == NULL)
    {
        tmp->pPrev = NULL;
        *head = tmp;
        return;
    }
    while (temp->pNext != NULL)
    {
        temp = temp->pNext;
    }
    temp->pNext = tmp;
    tmp->pPrev = temp;
    *tail = tmp;
    sizeList++;
}

void pushBtw(struct Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("Ошибка! У вас нет головы/хвоста!\n");
        return;
    }
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("Ошибка выделения памяти!");
        exit(1);
    }
    tmp->data = data;
    tmp->pNext = prev_node->pNext;
    prev_node->pNext = tmp;
    tmp->pPrev = prev_node;
    if (tmp->pNext != NULL)
    {
        tmp->pNext->pPrev = tmp;
    }
    sizeList++;
}

void editNode(struct Node** node, int new_data)
{
    (*node)->data = new_data;
}

void delNode(struct Node** head, struct Node** tail, struct Node* del_node)
{
    if (*head == NULL || del_node == NULL)
    {
        return;
    }
    if (*head == del_node)
    {
        *head = del_node->pNext;
    }
    if (del_node == *tail)
    {
        *tail = del_node->pPrev;
    }
    if (del_node->pNext != NULL)
    {
        del_node->pNext->pPrev = del_node->pPrev;
    }
    if (del_node->pPrev != NULL)
    {
        del_node->pPrev->pNext = del_node->pNext;
    }
    free(del_node);
    del_node = NULL;
    sizeList--;
}

void printHead(struct Node* node)
{
    struct Node* last;
    if (node != NULL) {
        while (node != NULL)
        {
            printf("%d ", node->data);
            last = node;
            node = node->pNext;
        }
    }
    printf("\n");
}

void printTail(struct Node* node)
{
    struct Node* last;
    if (node != NULL)
    {
        while (node != NULL)
        {
            printf("%d ", node->data);
            last = node;
            node = node->pPrev;
        }
    }
    printf("\n");
}

void bubble(struct Node** head, int size)
{
    for (int i = 0; i < size; i ++)
    {
        for (struct Node* j = *head; j->pNext != NULL; j = j->pNext)
        {
            if (j->data > j->pNext->data)
            {
                int temp = j->data;
                j->data = j->pNext->data;
                j->pNext->data = temp;
            }
        }
    }
}

void combSort(struct Node** head, int size) {
    int swapped = 1;
    struct Node* ptr1 = *head;
    struct Node* ptr2 = NULL;
    int gap = size;

    while (swapped == 1 || gap > 1) {
        if (gap > 1)
        {
            gap = (int)(gap / 1.3);
        }
        swapped = 0;

        for (ptr1 = *head; ptr1->pNext != ptr2; ptr1 = ptr1->pNext) {
            if (ptr1->data > ptr1->pNext->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->pNext->data;
                ptr1->pNext->data = temp;
                swapped = 1;
            }
        }

        ptr2 = ptr1;
    }
}