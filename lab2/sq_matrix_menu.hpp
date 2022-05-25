#ifndef MENU_MATRIX_HPP
#define MENU_MATRIX_HPP

#include <iostream>
#include <string.h>
#include <conio.h>
#include "sq_matrix_array.hpp"
#include "sq_matrix_list.hpp"

int show_main_menu_matrix(int position, int count_list_menu) {
	system("cls");
	char list_menu[5][60] = { {"Sum matrix"}, {"Mult matrix on number"}, {"Change matrix"},
		{"Find norm"},  {"Close app"} };
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

int sum_matrix(int mod, int mod2) {
	system("cls");
	int row = 0, column = 0;
	printf("Enter size of matrix: ");
	scanf("%d", &row);
	column = row;
	if (mod == 0) {
		if (mod2 == 0) {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row1 = new int[row];
				for (int j = 0; j < row; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row1[j] = a;
				}
				arr11[i] = row1;
			}

			ArrayMatrix<int>* arr1 = new ArrayMatrix<int>(arr11, row);

			int** arr22 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row1 = new int[row];
				for (int j = 0; j < row; ++j) {
					printf("Enter matrix2[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row1[j] = a;
				}
				arr22[i] = row1;
			}
			ArrayMatrix<int>* arr2 = new ArrayMatrix<int>(arr22, row);

			printf("Matrix 1:\n");
			std::cout << arr1;
			printf("Matrix 2:\n");
			std::cout << arr2;

			arr1->Sum(arr2);
			printf("Sum:\n");
			std::cout << arr1;


			delete arr1;
			delete arr2;
			free(arr11);
			free(arr22);
		}
		else {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row1 = new int[row];
				for (int j = 0; j < row; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row1[j] = a;
				}
				arr11[i] = row1;
			}

			ListMatrix<int>* arr1 = new ListMatrix<int>(arr11, row);

			int** arr22 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row = new int[column];
				for (int j = 0; j < column; ++j) {
					printf("Enter matrix2[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row[j] = a;
				}
				arr22[i] = row;
			}
			ListMatrix<int>* arr2 = new ListMatrix<int>(arr22, row);

			printf("Matrix 1:\n");
			std::cout << arr1;

			printf("Matrix 2:\n");
			std::cout << arr2;

			arr1->Sum(arr2);
			std::cout << arr1;


			delete arr1;
			delete arr2;
			free(arr11);
			free(arr22);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}

int mult_matrixN(int mod, int mod2) {
	system("cls");
	int row = 0, column = 0;
	printf("Enter size of matrix: ");
	scanf("%d", &row);
	column = row;
	if (mod == 0) {
		if (mod2 == 1) {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row = new int[column];
				for (int j = 0; j < column; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row[j] = a;
				}
				arr11[i] = row;
			}
			ListMatrix<int>* arr1 = new ListMatrix<int>(arr11, row);

			int a;
			printf("Enter alfa: ");
			scanf("%d", &a);

			printf("Matrix 1:\n");
			std::cout << arr1;
			arr1->Mult(a);
			printf("Mult:\n");
			std::cout << arr1;

			delete arr1;
			free(arr11);
		}
		else {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row = new int[column];
				for (int j = 0; j < column; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row[j] = a;
				}
				arr11[i] = row;
			}
			ArrayMatrix<int>* arr1 = new ArrayMatrix<int>(arr11, row);

			int a;
			printf("Enter alfa: ");
			scanf("%d", &a);

			printf("Matrix 1:\n");
			std::cout << arr1;
			arr1->Mult(a);
			printf("Mult:\n");
			std::cout << arr1;

			delete arr1;
			free(arr11);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

int find_norm(int mod, int mod2) {
	system("cls");
	int row = 0, column = 0;
	printf("Enter size of matrix: ");
	scanf("%d", &row);
	column = row;
	if (mod == 0) {
		if (mod2 == 1) {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row = new int[column];
				for (int j = 0; j < column; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row[j] = a;
				}
				arr11[i] = row;
			}
			ListMatrix<int>* arr1 = new ListMatrix<int>(arr11, row);

			printf("Matrix 1:\n");
			std::cout << arr1;
			float norm = arr1->GetNorm();
			printf("norm = %f", norm);
			delete arr1;
			free(arr11);
		}
		else {
			int** arr11 = (int**)malloc(row * sizeof(int*));
			for (int i = 0; i < row; ++i) {
				int* row = new int[column];
				for (int j = 0; j < column; ++j) {
					printf("Enter matrix1[%d][%d]: ", i, j);
					int a;
					scanf("%d", &a);
					row[j] = a;
				}
				arr11[i] = row;
			}
			ArrayMatrix<int>* arr1 = new ArrayMatrix<int>(arr11, row);


			printf("Matrix 1:\n");
			std::cout << arr1;


			float norm = arr1->GetNorm();
			printf("norm = %f", norm);

			delete arr1;
			free(arr11);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}

int change_matrix(int mod, int mod2) {
	system("cls");

	int row = 0, column = 0;
	printf("Enter size of matrix: ");
	scanf("%d", &row);
	column = row;

	printf("Enter quantity of operations: ");
	int cnt = 0;
	scanf("%d", &cnt);
	if (mod2 == 0) {
		int** arr11 = (int**)malloc(row * sizeof(int*));
		for (int i = 0; i < row; ++i) {
			int* row = new int[column];
			for (int j = 0; j < column; ++j) {
				printf("Enter matrix1[%d][%d]: ", i, j);
				int a;
				scanf("%d", &a);
				row[j] = a;
			}
			arr11[i] = row;
		}
		ArrayMatrix<int>* arr1 = new ArrayMatrix<int>(arr11, row);

		printf("Matrix1:\n");
		std::cout << arr1;
		for (int i = 0; i < cnt; ++i) {
			int ind1, ind2;
			printf("1 - sum rows\n2 - sum columns\n");
			int mod3;
			scanf("%d", &mod3);
			printf("Enter numbers of lines: ");
			scanf("%d %d", &ind1, &ind2);
			if (mod3 == 1) {
				arr1->SumRow(ind1, ind2);
			}
			else {
				arr1->SumColumn(ind1, ind2);
			}
			printf("Matrix:\n");
			std::cout << arr1;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}


int control_menu(int count_list_menu, int mod, int mod2) {
	int position = 0, exit = 0;
	count_list_menu = 5;
	show_main_menu_matrix(position, count_list_menu);
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
			show_main_menu_matrix(position, count_list_menu);
			break;
		}
		case(80): //down
		{
			position += 1;
			if (position == count_list_menu) {
				position = 0;
			}
			show_main_menu_matrix(position, count_list_menu);
			break;
		}
		case(13):
		{
			if (position == 0) {
				sum_matrix(mod, mod2);
			}
			if (position == 1) {
				mult_matrixN(mod, mod2);
			}
			if (position == 2) {
				change_matrix(mod, mod2);
			}
			if (position == 3) {
				find_norm(mod, mod2);
			}
			if (position == 4) {
				exit = 1;
				system("cls");
				printf("Good bye!\n");
				break;
			}
			show_main_menu_matrix(position, count_list_menu);
			break;
		}
		}
	} while (exit == 0);
	return 0;
}
#endif