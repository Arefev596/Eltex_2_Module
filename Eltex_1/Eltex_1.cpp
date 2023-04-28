#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

double balance;
double conv_balance;
int range1;
int range2 = 0;
int num_attempts;
int bet;
int select;
int select2;
int main_game();
void show_balance();
int check = 1;
int menu();
int game(int);
int yes = 0;
int variant;
double prize;
int res_attempt;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	printf("Будь как дома путник, я ни в чем не откажу. Исключительно для тебя сегодня акция, стартовый баланс = 100 дублей. Курс: 1 дубль=5,73 руб.\n");
	balance = 100;
	conv_balance = balance * 5.73;
	menu();
	return 0;
}

int main_game() {
	printf("Введите минимум диапазона для рандомайзера: \t");
	scanf("%d", &range1);
	if (range1 <= 0) {
		printf("Вы ввели число меньшее, либо равное 0!\n");
		return 0;
		printf("\n");
	}

	printf("Введите максимум диапазона для рандомайзера: \t");
	scanf("%d", &range2);
	if (range2 <= 0) {
		printf("Вы ввели число меньшее, либо равное 0!\n");
		return 0;
		printf("\n");
	}
	else if (range2 < range1) {
		printf("Вы ввели число для максимума меньше минимума...\n");
		return 0;
		printf("\n");
	}

	printf("Введите количество попыток на угадывание: \t");
	scanf("%d", &num_attempts);
	if (num_attempts <= 0) {
		printf("Вы ввели число меньшее, либо равное 0!\n");
		return 0;
	}
	if (num_attempts >=(range2-range1)) {
		printf("Вы ввели слишком большое количество попыток на угадывание!\n");
		return 0;
	}

	printf("Введите размер вашей ставки в дублях: \t");
	scanf("%d", &bet);
	if (bet <= 0) {
		printf("Вы ввели число меньшее, либо равное 0!\n");
		return 0;
	}
	if (bet > balance) {
		printf("Кого вы хотите нагреть? Вы ввели число больше вашего баланса!\n");
		return 0;
	}
	int answer = rand() % (range2 - range1 + 1) + range1;
	game(answer);
	
}

int game(int answer) {
	int attempt = 1;
	system("cls");
	printf("Число было загадано. ");
	for (int i = 1; i <= num_attempts; i++) {
		printf("Ваша % d попытка : ", attempt);
		scanf("%d", &variant);
		attempt += 1;
		res_attempt = num_attempts - i;
		if (answer < variant) {
			printf("У вас осталось %d попыток. Загаданное число меньше!\n", res_attempt);
		}
		else if (answer > variant){
			printf("У вас осталось %d попыток. Загаданное число больше!\n", res_attempt);
		}
		else {
			yes = 1;
			break;
		}

	}

	if (yes == 1) {
		prize = ((range2 - range1) / attempt) * (0.1*bet);
		printf("Вы угадали! Поздравляем! Ваш выигрыш %.3f \n", prize);
		balance += prize;
		printf("Ваш баланс на данный момент: %.3f \n", balance);
		printf("Хотите повторить? 1.Да	2.Нет\n");
		scanf("%d", &select2);
		if (select2 == 1) {
			menu();
		}
		else {
			printf("До свидания!");
			getch();
		}
		yes = 0;
	}
	else {
		printf("Глубоко сожалеем, вы проиграли %d! ", bet);
		printf("Правильный ответ был %d \n", answer);
		balance -= bet;
		if (balance <= 0) {
			printf("Играть заново не предлагаем, вы все проиграли :(		Всего доброго!Приходите еще!\n");
			return 0;
		}
		else {
			printf("Хотите повторить? У вас осталось %.3f дубля(-ей). 1.Да	2.Нет\n", balance);
			scanf("%d", &select2);
			if (select2 == 1) {
				menu();
				select2 = 0;
			}
			else {
				printf("До свидания!");
				getch();
			}
		}
	}
	return 0;
}

void show_balance() {
	printf("На вашем балансе %.3f дублей или %.3f рублей\n\n", balance, conv_balance);
	if (select == 2) {
		menu();
	}
	else {
		main_game();
	}
}


int menu() {
	printf("Выбери пункт меню:\n");
	printf("1.Играть\n");
	printf("2.Узнать остаток баланса\n");
	printf("3.Выход\n");

	scanf("%d", &select);
	switch (select) {
	case 1:
		system("cls");
		show_balance();
		main_game();
		break;
	case 2:
		system("cls");
		show_balance();
		break;
	case 3:
		return 0;
	}
}