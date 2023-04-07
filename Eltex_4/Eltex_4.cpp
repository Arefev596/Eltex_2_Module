#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>

// binary search tree, int// вывод дерева, добавление нового узла

int size, check = 1, tabs = 16, count;
struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* init(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    size++;
    printf("Был добавлен ключ: %d\n", temp->key);
    return temp;
}

void printList(struct node* root) {
    if (root==NULL)
    {
        return;
    }
    
    for (int i = 0; i < tabs; i++)
    {
        printf(" ");
    }
    printf("%d \n", root->key);
    tabs -= 4;
    printList(root->left);
    tabs += 5;
    printList(root->right);
    tabs += 4;
    return;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) {
        return init(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else {
        node->right = insert(node->right, key);
    }
    return node;
}


struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        printf("У вас не созданы деревья!\n");
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct node* deleteTree(struct node* root) {
    if (root == NULL) {
        printf("У вас не созданы деревья!\n");
        return root;
    }
    while (root->key != NULL)
    {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(temp);
            temp->key = NULL;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(temp);
            temp->key = NULL;
        }
        if (root->key != NULL)
        {
            free(root);
            root->key = NULL;
        }
    }
    root == NULL;
    printf("Дерево очищено!\n");
    check = 0;
}

int main() {
    setlocale(LC_ALL, "ru");
    struct node* root = NULL;
    srand(time(NULL));
    int whale, key, N, quantity ;
	while (1) {
		printf("\nВыберите нужную функцию:\n1.Добавить новый случайный элемент в бинарное дерево;\n2.Вывод бинарного дерева;\n3.Удалить элемент из бинарного дерева;\n4.Удалить дерево.\n");
        printf("5.Очистить консоль.\n6.Выход.\n\n");
        scanf("%d", &whale);
		switch (whale) {
		case 1:
            printf("Хотите создать несколько элементов? 1.Да\t2.Нет ");
            scanf("%d", &N);
            if (N == 1) {
                printf("Введите количество элементов: ");
                scanf("%d", &quantity);
                for (int i = 0; i < quantity; i++)
                {
                    root = insert(root, rand() % 100);
                }
            }
            if (N == 2) {
                root = insert(root, rand() % 100);
            }
            break;
        case 2:
            printf("У вас %d элемент(-а) \n", size);
            printList(root);
            break;
        case 3:
            printf("Введите ключ из дерева, который хотите удалить: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 4:
            root = deleteTree(root);
            break;
        case 5:
            system("cls");
            break;
        case 6:
            root = deleteTree(root);
            printf("Всего доброго!\n");
            exit(1);
		}
	}
	return 0;
}