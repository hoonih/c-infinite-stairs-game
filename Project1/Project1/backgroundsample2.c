#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h> 

#define COLOR_RESET	"\033[0m" // 리셋
#define COLOR_WHITE	"\033[48;2;255;255;255m" // 흰색
#define COLOR_GRAY	"\033[48;2;186;195;198m" // 회색
#define COLOR_BLACK	"\033[48;2;0;0;0m" // 검색
#define COLOR_APRICOT	"\033[48;2;252;221;199m"       // 살구색
#define COLOR_DARK_SKIN "\033[48;2;191;144;120m"      // 피부 명암
#define COLOR_ORANGE "\033[48;2;255;139;51m"            // 주황색

//계단

#define COLOR_BLOACK1	"\033[48;2;100;100;100m" // 회색1
#define COLOR_BLOACK2	"\033[48;2;141;141;141m" // 회색2
#define COLOR_BLOACK3	"\033[48;2;153;153;153m" // 회색3
#define COLOR_BLOACK4	"\033[48;2;172;172;172m" // 회색4

char mainstair[6][10] = {
	{"1111111111"},
	{"1334333331"},
	{"1341333331"},
	{"1333344131"},
	{"1443333441"},
	{"1111111111"},
};
char mainchar_1[16][16] = {
	{"0000000000000000"},
	{"0000111111100000"},
	{"0001233333210000"},
	{"0012333333321000"},
	{"0013333333331000"},
	{"0013331333131000"},
	{"0013331333131000"},
	{"0013333333331000"},
	{"0001333333311000"},
	{"0000123332110000"},
	{"0000133333100000"},
	{"0000133333100000"},
	{"0000133333100000"},
	{"0000132123100000"},
	{"0000121012100000"},
	{"0000110011000000"},
};
char mainchar_2[16][16] = {
	{"0000000000000000"},
	{"0000111111100000"},
	{"0001233333210000"},
	{"0012333333321000"},
	{"0013333333331000"},
	{"0013331333131000"},
	{"0013331333131000"},
	{"0013333333331000"},
	{"0001333333311000"},
	{"0000123332110000"},
	{"0000133333100000"},
	{"0000133333100000"},
	{"0000133333310000"},
	{"0000132111210000"},
	{"0000121000110000"},
	{"0000110000000000"},
};
char mainchar_3[16][16] = {
	{"0000111111100000"},
	{"0001233333210000"},
	{"0012333333321000"},
	{"0013333333331000"},
	{"0013331333131000"},
	{"0013331333131000"},
	{"0013333333331000"},
	{"0001333333311000"},
	{"0000123332110000"},
	{"0000133333100000"},
	{"0000133333110000"},
	{"0001333333331000"},
	{"0013332111111000"},
	{"0001111000000000"},
	{"0000000000000000"},
	{"0000000000000000"},
};
char mainchar_4[16][16] = {
	{"0000000000000000"},
	{"0000000000000000"},
	{"0000111111100000"},
	{"0001233333210000"},
	{"0012333333321000"},
	{"0013333333331000"},
	{"0013331333131000"},
	{"0013331333131000"},
	{"0013333333331000"},
	{"0001333333311000"},
	{"0000123332110000"},
	{"0000133333100000"},
	{"0000133333100000"},
	{"0001331123100000"},
	{"0000110013100000"},
	{"0000000001100000"},
};


void setColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(bgcolor << 4) | color);
}

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y)

{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_bloack()
{
	for (int h = 0; h < 6; h++)
	{
		gotoxy(85, h + 35);
		for (int w = 0; w < 10; w++)
		{
			if (mainstair[h][w] == '0')
			{
				setColor(0, 0); printf("  %s", COLOR_RESET);
			}
			if (mainstair[h][w] == '1')
			{
				printf("%s  %s", COLOR_BLOACK1, COLOR_RESET);
			}
			if (mainstair[h][w] == '2')
			{
				printf("%s  %s", COLOR_BLOACK2, COLOR_RESET);
			}
			if (mainstair[h][w] == '3')
			{
				printf("%s  %s", COLOR_BLOACK3, COLOR_RESET);
			}
			if (mainstair[h][w] == '4')
			{
				printf("%s  %s", COLOR_BLOACK4, COLOR_RESET);
			}
		}
	}
}
void print_character(int scene)
{
	if (scene == 1)
	{
		for (int h = 0; h < 16; h++)
		{
			gotoxy(80, h + 20);
			for (int w = 0; w < 16; w++)
			{
				if (mainchar_1[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_1[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_1[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_1[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 2)
	{
		for (int h = 0; h < 16; h++)
		{
			gotoxy(80, h + 20);
			for (int w = 0; w < 16; w++)
			{
				if (mainchar_2[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_2[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_2[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_2[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 3)
	{
		for (int h = 0; h < 16; h++)
		{
			gotoxy(80, h + 20);
			for (int w = 0; w < 16; w++)
			{
				if (mainchar_3[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_3[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_3[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_3[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 4)
	{
		for (int h = 0; h < 16; h++)
		{
			gotoxy(80, h + 20);
			for (int w = 0; w < 16; w++)
			{
				if (mainchar_4[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_4[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_4[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_4[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}

}


void print_character_left(int scene)
{
	if (scene == 1)
	{
		for (int h = 15; h >= 0; h--)
		{
			gotoxy(80, h + 20);
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_1[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_1[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_1[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_1[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 2)
	{
		for (int h = 15; h >= 0; h--)
		{
			gotoxy(80, h + 20);
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_2[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_2[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_2[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_2[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 3)
	{
		for (int h = 15; h >= 0; h--)
		{
			gotoxy(80, h + 20);
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_3[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_3[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_3[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_3[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}
	else if (scene == 4)
	{
		for (int h = 15; h >= 0; h--)
		{
			gotoxy(80, h + 20);
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_4[h][w] == '0')
				{
					setColor(0, 0); printf("  %s", COLOR_RESET);
				}
				if (mainchar_4[h][w] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				if (mainchar_4[h][w] == '3')
				{
					setColor(0, 15); printf("  ");
				}
				if (mainchar_4[h][w] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
			}
		}
	}

}

int key;

void InputKey() {

	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 32: // space

			break;
		case 75: // left
			system("cls");
			print_character_left(1);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character_left(2);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character_left(3);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character_left(4);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character_left(1);
			print_bloack();
			break;
		case 77: // right
			system("cls");
			print_character(1);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character(2);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character(3);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character(4);
			print_bloack();
			Sleep(50);
			system("cls");
			print_character(1);
			print_bloack();
			break;
		case 80: // down
			break;
		}
	}
}


int main()
{
	hidecursor();
	system("mode con:cols=200 lines=60");
	system("cls");
	print_character(1);
	print_bloack();
	while (1)
	{

		InputKey();
	}

}