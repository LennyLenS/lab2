#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string.h>
#include <conio.h>
#include "vector_array.hpp"
#include "vector_list.hpp"

int show_main_menu(int position, int count_list_menu) {
	system("cls");
	char list_menu[4][60] = { {"Sum Vector"}, {"Mult vector on number"}, {"Mult vector on vector"},
		{"Close app"} };
	for (int i = 0; i < count_list_menu; ++i) {
		if (i != position) {
			printf("%s\n", list_menu[i]);
		}
		else {
			printf("%s <=\n", list_menu[i]);
		}
	}
	return 0;
}

int sum_vectors(int mod, int mod2) {
	system("cls");
	int size = 0;
	printf("Enter size of vectors: ");
	scanf("%d", &size);
	if (mod == 0) {
		if (mod2 == 0) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ArrayVector<int>* arr1 = new ArrayVector<int>(arr, size);

			int* arr22 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr22 + i, &a, sizeof(int));
			}
			ArrayVector<int>* arr2 = new ArrayVector<int>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr2->Get(i));
			}

			arr1->Sum(arr2);
			printf("\nSum:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}


			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
		if (mod2 == 1) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ListVector<int>* arr1 = new ListVector<int>(arr, size);

			int* arr22 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr22 + i, &a, sizeof(int));
			}
			ListVector<int>* arr2 = new ListVector<int>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr2->Get(i));
			}

			arr1->Sum(arr2);
			printf("\nSum:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
	}
	else {
		if (mod2 == 0) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ArrayVector<float>* arr1 = new ArrayVector<float>(arr, size);

			float* arr22 = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr22 + i, &a, sizeof(float));
			}
			ArrayVector<float>* arr2 = new ArrayVector<float>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr2->Get(i));
			}

			arr1->Sum(arr2);
			printf("\nSum:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			delete arr1;
			delete arr2;
		}
		if (mod2 == 1) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ListVector<float>* arr1 = new ListVector<float>(arr, size);

			float* arr22 = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr22 + i, &a, sizeof(float));
			}
			ListVector<float>* arr2 = new ListVector<float>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr2->Get(i));
			}

			arr1->Sum(arr2);
			printf("\nSum:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}

int mult_vectorN(int mod, int mod2) {
	system("cls");
	int size = 0;
	printf("Enter size of vector: ");
	scanf("%d", &size);
	if (mod == 0) {
		if (mod2 == 0) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ArrayVector<int>* arr1 = new ArrayVector<int>(arr, size);
			
			int a;
			printf("Enter alfa: ");
			scanf("%d", &a);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}

			arr1->Multiplication(a);
			printf("\nmult:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			delete arr1;
			free(arr);
		}
		if (mod2 == 1) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ListVector<int>* arr1 = new ListVector<int>(arr, size);

		
			int a;
			printf("Enter alfa: ");
			scanf("%d", &a);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}


			arr1->Multiplication(a);
			printf("\nmult:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			delete arr1;
			free(arr);
		}
	}
	else {
		if (mod2 == 0) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ArrayVector<float>* arr1 = new ArrayVector<float>(arr, size);

			float a;
			printf("Enter alfa: ");
			scanf("%f", &a);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}

			arr1->Multiplication(a);
			printf("\nmult:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			delete arr1;
			free(arr);
		}
		if (mod2 == 1) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ListVector<float>* arr1 = new ListVector<float>(arr, size);

			float a;
			printf("Enter alfa: ");
			scanf("%f", &a);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}

			arr1->Multiplication(a);
			printf("\nmult:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			delete arr1;
			free(arr);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

int mult_vectorV(int mod, int mod2) {
	system("cls");
	int size = 0;
	printf("Enter size of vectors: ");
	scanf("%d", &size);
	if (mod == 0) {
		if (mod2 == 0) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ArrayVector<int>* arr1 = new ArrayVector<int>(arr, size);

			int* arr22 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr22 + i, &a, sizeof(int));
			}
			ArrayVector<int>* arr2 = new ArrayVector<int>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr2->Get(i));
			}

			int mult = arr1->Multiplication(arr2);
			printf("\nmult: %d", mult);
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
		if (mod2 == 1) {
			int* arr = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr + i, &a, sizeof(int));
			}
			ListVector<int>* arr1 = new ListVector<int>(arr, size);

			int* arr22 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%d", &a);
				memcpy(arr22 + i, &a, sizeof(int));
			}
			ListVector<int>* arr2 = new ListVector<int>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%d ", arr2->Get(i));
			}

			int mult = arr1->Multiplication(arr2);
			printf("\nmult: %d", mult);
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
	}
	else {
		if (mod2 == 0) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ArrayVector<float>* arr1 = new ArrayVector<float>(arr, size);

			float* arr22 = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr22 + i, &a, sizeof(int));
			}
			ArrayVector<float>* arr2 = new ArrayVector<float>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr2->Get(i));
			}

			float mult = arr1->Multiplication(arr2);
			printf("\nmult: %f", mult);
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
		if (mod2 == 1) {
			float* arr = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector1[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr + i, &a, sizeof(float));
			}
			ListVector<float>* arr1 = new ListVector<float>(arr, size);

			float* arr22 = (float*)malloc(size * sizeof(float));
			for (int i = 0; i < size; ++i) {
				printf("Enter vector2[%d]: ", i);
				int a;
				scanf("%f", &a);
				memcpy(arr22 + i, &a, sizeof(float));
			}
			ListVector<float>* arr2 = new ListVector<float>(arr22, size);

			printf("Vector 1:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr1->Get(i));
			}
			printf("\nVector 2:");
			for (int i = 0; i < size; ++i) {
				printf("%f ", arr2->Get(i));
			}

			float mult = arr1->Multiplication(arr2);
			printf("\nmult: %f", mult);
			delete arr1;
			delete arr2;
			free(arr);
			free(arr22);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

int control_menu(int count_list_menu, int mod, int mod2) {
	int position = 0, exit = 0;
	show_main_menu(position, count_list_menu);
	do {
		int key = 0;
		key = _getch();
		switch (key) {
		case(72): //up
		{
			position -= 1;
			if (position == -1) {
				position = count_list_menu - 1;
			}
			show_main_menu(position, count_list_menu);
			break;
		}
		case(80): //down
		{
			position += 1;
			if (position == count_list_menu) {
				position = 0;
			}
			show_main_menu(position, count_list_menu);
			break;
		}
		case(13):
		{
			if (position == 0) {
				sum_vectors(mod, mod2);
			}
			if (position == 1) {
				mult_vectorN(mod, mod2);
			}
			if (position == 2) {
				mult_vectorV(mod, mod2);
				printf("2!\n");
			}
			if (position == 3) {
				exit = 1;
				system("cls");
				printf("Good bye!\n");
				break;
			}
			show_main_menu(position, count_list_menu);
			break;
		}
		}
	} while (exit == 0);
	return 0;
}
#endif 