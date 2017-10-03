#define MAGIC_NUMBER 613243674551.242352

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check(const int count, const double *a, const double el){  // Принимает указатель на массив чисел(множество) и число, которое нужно проверить, не находится ли оно во мн-ве
	for (int i = 0; i < count; i++){
		if (el == a[i] && a[i] != MAGIC_NUMBER){
			// printf("Во множестве не может быть двух повторяющихся чисел\n");
			return 1;
		}
	}
	return 0; // Если такого числа нету 
}


void print(const int count, const double *a){  // Принимает указатель на массив, выводит всё множество по пять элементов в строке
	for (int i = 0; i < count; i++){
		if (i % 5 == 0) printf("\n");
		if (a[i] != MAGIC_NUMBER) printf("%d. %lf\t", i, a[i]);
	}
	printf("\n");
}


int add(int *count, double *a, const double el){  // Добавление элемента в множество, если добавили возвр. 1, если элемент уже есть, то возвращает 0
	if (check(*count, a, el) == 0){
		a[*count] = el;
		*count =  *count + 1;
		return 1;
	}
	return 0;
}


int delete(int count, double *a, const int i){  // Удаляем один элемент из масива, если получилось возвращаем 1
	if (i >= count || i < 0) return 0;
	a[i] = MAGIC_NUMBER;
	return 1;
} 


int main(int argc, char *argv[]){  // Получает эл-ты множества как аргументы командной строки
	system("chcp 65001");
	int exit = 1;  // Переменная, задавая которую мы будем понимать, выходить из цикла или нет
	int count = argc - 1;  // Количество элементов
	double *set = (double*)malloc(sizeof(double)*70);  // Выделяем память под массив с числами
	for (int i = 1; i < argc; i++){  // Заполняем массив начальными данными
		double el = atof(argv[i]);
		if (check(argc-1, set, el) == 0)
			set[i-1] = el;
	}
	while (exit != 0){
		printf("1. Нажмите 1 чтобы вывести элементы множества\n");
                printf("2. Нажмите 2 чтобы добавить элемент во множество\n");
                printf("3. Нажмите 3 чтобы удалить элемент множества\n");
                printf("4. Нажмите 0 для выхода\n");
		
		scanf("%d", &exit);  // Вводим комманду с клавиатуры
		double el = 0.0;
		int i = 0;
		switch (exit){
			case 1:
				print(count, set);
				break;
			case 2:
				printf("Какой элемент добавить?  ");
				scanf("%lf", &el);
				if (!add(&count, set, (double)el)) printf("Такой элемент уже есть во множестве\n");
				break;
			case 3:
				print(count, set);
				printf("Какой элемент удалить?(удаление происходит по индексу)  ");
				scanf("%d", &i);
				if (!delete(count, set, i)) printf("Не удалось удалить элемент(ошибка индексирования)");
				break;
			default:
				exit = 0;
				break;
		}
	}
	free(set);

	return 0;
}
