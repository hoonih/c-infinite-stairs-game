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


char mainchar_4[16][16] = {

void setColor(int color, int bgcolor);
void hidecursor();
void print_bloack();
void print_character(int scene);
void InputKey();

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

void print_bloack()
{
	
}
void print_character(int scene)
{
	
}


int key;

void InputKey() {

	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 32: // space

			break;
		case 75: // left
			
			break;
		case 77: // right
			
			break;
		case 80: // down
			break;
		}
	}
}


