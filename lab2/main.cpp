#include <iostream>
#include <conio.h>
#include "tr_matrix_menu.hpp"
//menu for choose type of vector
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


//menu for choose type of realization
int show_choose_type(int position) {
	system("cls");
	char list_menu[2][60] = { {"Array matrix"}, {"List matrix"} };
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

int choose_type() {
	int position = 0;
	show_choose_type(position);
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
			show_choose_type(position);
			break;
		}
		case(80): //down
		{
			position += 1;
			if (position == 2) {
				position = 0;
			}
			show_choose_type(position);
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
			show_choose_type(position);
			break;
		}
		}
	} while (0 == 0);
}

int main() {
	int mod = control_preview();
	int count_list_menu = 4;
	int mod2 = choose_type();
	control_menu(count_list_menu, mod, mod2);
	return 0;
}