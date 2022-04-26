#include <iostream>
#include <conio.h>

int show_main_menu(int position, int count_list_menu) {
	system("cls");
	char list_menu[4][60] = { {"Input matrix"}, {"Output matrix"}, {"Do operations with matrix"},
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

int control_menu(int count_list_menu, int mod, struct matrix** mat, struct matrix** mat2) {
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
			/*
			if (position == 0) {
				int choose = control_choose_matrix_menu();
				if (choose == 0) {
					*mat = input_matrix(mod, *mat);
				}
				if (choose == 1) {
					*mat2 = input_matrix(mod, *mat2);
				}
			}
			if (position == 1) {
				int choose = control_choose_matrix_menu();
				if (choose == 0) {
					output_matrix(mod, *mat);
				}
				if (choose == 1) {
					output_matrix(mod, *mat2);
				}
			}
			if (position == 2) {
				change(mod, mat, mat2);
				printf("2!\n");
			}
			if (position == 3) {
				exit = 1;
				system("cls");
				printf("Good bye!\n");
				break;
			}
			show_main_menu(position, count_list_menu);
			*/
			break;
		}
		}
	} while (exit == 0);
	return 0;
}


//menu for choose type of matrix
int show_preview_menu(int position) {
	system("cls");
	char list_menu[2][60] = { {"Integer matrix"}, {"Float matrix"} };
	for (int i = 0; i < 2; ++i) {
		if (i != position) {
			printf("%s\n", list_menu[i]);
		}
		else {
			printf("%s <=\n", list_menu[i]);
		}
	}
	return 0;
}

int control_preview() {
	int position = 0;
	show_preview_menu(position);
	do {
		int key = 0;
		key = _getch();
		switch (key) {
		case(72): //up
		{
			position -= 1;
			if (position == -1) {
				position = 2 - 1;
			}
			show_preview_menu(position);
			break;
		}
		case(80): //down
		{
			position += 1;
			if (position == 2) {
				position = 0;
			}
			show_preview_menu(position);
			break;
		}
		case(13):
		{
			if (position == 0) {
				return 0;
			}
			if (position == 1) {
				return 1;
			}
			show_preview_menu(position);
			break;
		}
		}
	} while (0 == 0);
}

int main() {
	int mod = control_preview();
	struct matrix* mat;
	struct matrix* mat2;
	if (mod == 0) {
		int* elements = (int*)malloc(2 * sizeof(int));
		elements[0] = 0;
		elements[1] = 1;
	}
	else {
		float* elements = (float*)malloc(2 * sizeof(float));
		elements[0] = 0;
		elements[1] = 1;
	}
	int count_list_menu = 4;
	control_menu(count_list_menu, mod, &mat, &mat2);
}