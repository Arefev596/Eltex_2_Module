#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "ru");
    int a, b, c; // размеры емкостей
    int temp1, temp2, temp3;
    int K[3] = { 0, 0, 0 }; //Размер заполненной емкости
    int R; //Объем, необходимый достичь
    int count = 0;
    printf("Введите количество заполненной емкости: ");
    scanf("%d", &K[0]);
    printf("Введите размеры первой, второй и третьей емкости через пробел: ");
    scanf("%d%d%d", &temp1, &temp2, &temp3);
    printf("Введите объем, который необходимо достичь: ");
    scanf("%d", &R);
    /*K[0] = 13; a = 13; b = 11; c = 10; R = 5; - невозможно решить!*/
    /*K[0] = 12; a = 12; b = 5;  c = 8;  R = 6;*/
    /*K[0] = 13; a = 13; b = 11; c = 10; R = 5;*/
    /*K[0] = 8;  a = 8;  b = 3;  c = 5;  R = 4;*/
    /*K[0] = 16; a = 16; b = 11; c = 6;  R = 8;*/
    if (temp1 > temp2 && temp1 > temp3) {
        a = temp1;
        if (temp2>temp3)
        {
            b = temp3;
            c = temp2;
        }
        else {
            b = temp2;
            c = temp3;
        }
    }
    else if (temp2 > temp1 && temp2 > temp3) {
        a = temp2;
        if (temp1 > temp3)
        {
            b = temp3;
            c = temp1;
        }
        else {
            b = temp1;
            c = temp3;
        }
    }
    else {
        a = temp3;
        if (temp1 > temp2)
        {
            b = temp2;
            c = temp1;
        }
        else {
            b = temp1;
            c = temp2;
        }
    }

    while (K[0] != R && K[1] != R && K[2] != R) {
        if (K[2] == 0 && K[0] != 0)                              // 1 3 7 9 13      // 1 5
        {
            while (K[2] != c && K[0] != 0) {
                K[0]--;
                K[2]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else if (K[1] == 0 && K[2] == c)                 // 2                       // 2
        {
            while (K[2] != 0 && K[1] != b)
            {
                K[2]--;
                K[1]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else if (K[1] == 0 && K[2] != 0)             // 6 12                        // 4
        {
            while (K[2] != 0)
            {
                K[2]--;
                K[1]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else if (K[2] == c && K[1] <= c)                         // 4 8             // 6
        {
            while (K[1] != b && K[2] != 0)
            {
                K[2]--;
                K[1]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else if (K[2] == c && K[1] <= b)                         // 10   
        {
            while (K[1] != b)
            {
                K[2]--;
                K[1]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else if (K[1] == b && K[2] != R)                              // 5 11       // 3
        {
            while (K[1] != 0)
            {
                K[1]--;
                K[0]++;
            }
            count++;
            printf("Расчет %d: %d %d %d \n", count, K[0], K[1], K[2]);
        }
        else {
            printf("Расчет для заданных значений невозможен!");
            break;
        }
    }
    printf("Расчет был закончен!");
    return 0;
}
