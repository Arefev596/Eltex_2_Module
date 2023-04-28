#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>
#include <locale.h>
#include "Header.h"

// вид - двусвязный список, тип данных - int

int main() {
    int select, id, quantity, data, N;
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    struct Node* head = NULL;
    struct Node* tail = NULL;
    while (1) {
        printf("1. Создание нового узла с головы;\n2. Создание нового узла с хвоста;\n");
        printf("3. Создание нового узла в указанной позиции;\n4. Удаление существующего узла с головы;\n");
        printf("5. Удаление существующего узла с хвоста;\n6. Удаление существующего узла в указанной позиции;\n");
        printf("7. Редактирование существующего узла с головы;\n8. Редактирование существующего узла с хвоста;\n");
        printf("9. Редактирование существующего узла в указанной позиции;\n10. Вывод списка в консоль с головы;\n");
        printf("11. Вывод списка в консоль с хвоста;\n12. Заполнение списка N случайными числами;\n");
        printf("13. Очистка и удаление списка;\n14. Сортировка пузырьком;\n15. Сортировка расческой.\n");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: // РАБОТАЕТ
            printf("Введите данные для нового узла с головы: ");
            scanf("%d", &data);
            pushFront(&head, &tail, data);
            break;
        case 2: // РАБОТАЕТ
            printf("Введите данные для нового узла с хвоста: ");
            scanf("%d", &data);
            pushBack(&head, &tail, data);
            break;
        case 3: // РАБОТАЕТ
            printf("Введите номер позиции для нового узла с головы: ");
            scanf("%d", &id);
            printf("Введите данные для нового узла: ");
            scanf("%d", &data);
            struct Node* current;
            if (id <= sizeList / 2)
            {
                current = head;
                for (int i = 1; i < id && current != NULL; i++)
                {
                    current = current->pNext;
                }
            }
            else {
                current = tail;
                for (int i = 1; i < id && current != NULL; i++)
                {
                    current = current->pPrev;
                }
            }

            if (current == NULL)
            {
                printf("Ошибка ввода!Повторите снова!\n");
            }
            else
            {
                pushBtw(current, data);
            }
            break;
        case 4: //  РАБОТАЕТ
            printf("Удаление головы. \n");
            delNode(&head, &tail, head);
            break;
        case 5: // РАБОТАЕТ
            printf("Удаление хвоста. \n");
            delNode(&head, &tail, tail);
            break;
        case 6: // РАБОТАЕТ
            printf("Введите номер узла для удаления узла: ");
            scanf("%d", &id);
            struct Node* temp;
            if (id <= sizeList / 2)
            {
                temp = head;
                for (int i = 1; i < id && temp != NULL; i++)
                {
                    temp = temp->pNext;
                }
            }
            else {
                temp = tail;
                for (int i = 1; i < id && temp != NULL; i++)
                {
                    temp = temp->pPrev;
                }
            }

            if (temp == NULL)
            {
                printf("Ошибка ввода!Повторите снова!\n");
            }
            else
            {
                delNode(&head, &tail, temp);
                printf("Узел удален!\n");
            }
            break;
        case 7: // РАБОТАЕТ
            printf("Введите новые данные для редактирования головы: ");
            scanf("%d", &data);
            editNode(&head, data);
            break;
        case 8: // РАБОТАЕТ
            printf("Введите новые данные для редактирования хвоста: ");
            scanf("%d", &data);
            editNode(&tail, data);
            break;
        case 9: // РАБОТАЕТ
            printf("Введите номер узла для редактирования данных: ");
            scanf("%d", &id);
            printf("Введите новые данные для редактирования узла %d: ", id);
            scanf("%d", &data);
            struct Node* tmp;
            if (id <= sizeList / 2)
            {
                tmp = head;
                for (int i = 1; i < id && tmp != NULL; i++)
                {
                    tmp = tmp->pNext;
                }
            }
            else {
                tmp = tail;
                for (int i = 1; i < id && tmp != NULL; i++)
                {
                    tmp = tmp->pPrev;
                }
            }

            if (tmp == NULL)
            {
                printf("Ошибка ввода!Повторите снова!\n");
            }
            editNode(&tmp, data);
            break;
        case 10: // РАБОТАЕТ
            printHead(head);
            break;
        case 11: // РАБОТАЕТ
            printTail(tail);
            break;
        case 12: // РАБОТАЕТ
            printf("Введите число N для заполнения списка: \n");
            scanf("%d", &N);
            for (int i = 0; i < N; i++)
            {
                int data = rand() % 100;
                pushFront(&head, &tail, data);
            }
            printf("Список был заполнен!\n");
            break;
        case 13: // РАБОТАЕТ
            printf("Список очищен!\n");
            head = NULL;
            free(head);
            tail = NULL;
            free(tail);
            break;
        case 14: // РАБОТАЕТ
            bubble(&head, sizeList);
            break;
        case 15: // РАБОТАЕТ
            combSort(&head, sizeList);
            break;
        default: // РАБОТАЕТ
            printf("Некорректный ввод. Повторите попытку!\n");
            break;
        }
    }
    free(head);
    free(tail);
    return 0;
}
