#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 

#define COLOR_RESET	"\033[0m" // 리셋
#define COLOR_WHITE	"\033[48;2;255;255;255m" // 흰색
#define COLOR_GRAY	"\033[48;2;186;195;198m" // 회색
#define COLOR_BLACK	"\033[48;2;0;0;0m" // 검색
#define COLOR_APRICOT	"\033[48;2;252;221;199m"       // 살구색
#define COLOR_DARK_SKIN "\033[48;2;191;144;120m"      // 피부 명암
#define COLOR_ORANGE "\033[48;2;255;139;51m"            // 주황색


#define COLOR_BLOACK1	"\033[48;2;100;100;100m" // 회색1
#define COLOR_BLOACK2	"\033[48;2;141;141;141m" // 회색2
#define COLOR_BLOACK3	"\033[48;2;153;153;153m" // 회색3
#define COLOR_BLOACK4	"\033[48;2;172;172;172m" // 회색4

#define SCR_HEIGHT 60
#define SCR_WIDTH 100

char main_background[SCR_HEIGHT][SCR_WIDTH] = { '0', };

char front_buffer[SCR_HEIGHT][SCR_WIDTH];
char back_buffer[SCR_HEIGHT][SCR_WIDTH];


char mainstair[6][11] = {
	{"44444444444"},
	{"46676666674"},
	{"46746666664"},
	{"46666774654"},
	{"47766667764"},
	{"44444444444"},
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



void InputKey();
void backgroundreset();
void setColor(int color, int bgcolor);
void hidecursor();
void gotoxy(int x, int y);
//void background();
void print_bloack();
void test();
void drawAll();
void print_character(int scene);
void moveCursorTo(const int x, const int y);
int key;

void drawToBackBuffer(const int i, const int j, char image)
{
		back_buffer[i][j] = image;
}

void render()
{	
	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		int a = 0;
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			if (back_buffer[i][j] != front_buffer[i][j])
			{
				moveCursorTo(a, i);
				if (back_buffer[i][j] == '0')
				{ 
					setColor(11, 11); printf("  %s", COLOR_RESET);
				}
				else if (back_buffer[i][j] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				else if (back_buffer[i][j] == '3')
				{
					setColor(0, 15); printf("  ");
					//setColor(0, 15); printf("  ");
				}
				else if (back_buffer[i][j] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}
				else if (back_buffer[i][j] == '4')
				{
					printf("%s  %s", COLOR_BLOACK1, COLOR_RESET);
				}
				else if (back_buffer[i][j] == '5')
				{
					printf("%s  %s", COLOR_BLOACK2, COLOR_RESET);
				}
				else if (back_buffer[i][j] == '6')
				{
					printf("%s  %s", COLOR_BLOACK3, COLOR_RESET);
				}
				else if (back_buffer[i][j] == '7')
				{
					printf("%s  %s", COLOR_BLOACK4, COLOR_RESET);
				}
				
			}
			a += 2;
		}
	}

	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			front_buffer[i][j] = back_buffer[i][j];
			back_buffer[i][j] = '0';
		}
	}
}


void characterrender()
{
	for (int i = 0; i < 16; i++)
	{
		int a = 0;
		for (int j = 0; j < 16; j++)
		{


			if (back_buffer[22 + i][42 + j] != front_buffer[22 + i][42 + j])
			{
				moveCursorTo(84 + a, 22 + i);
				if (back_buffer[22 + i][42 +  j] == '0')
				{
					setColor(11, 11); printf("  %s", COLOR_RESET);
				}
				else if (back_buffer[22 + i][42 + j] == '1')
				{
					setColor(0, 0); printf("  ");
				}
				else if (back_buffer[22 + i][42 + j] == '3')
				{
					setColor(0, 15); printf("  ");
					//setColor(0, 15); printf("  ");
				}
				else if (back_buffer[22 + i][42 + j] == '2')
				{
					printf("%s  %s", COLOR_GRAY, COLOR_RESET);
				}

			}
			a += 2;
		}
	}
	for (int i = 0; i < SCR_HEIGHT; i++)
	{
		for (int j = 0; j < SCR_WIDTH; j++)
		{
			front_buffer[i][j] = back_buffer[i][j];
			back_buffer[i][j] = '0';
		}
	}
}

int main()
{
	for (int j = 0; j < SCR_HEIGHT; j++)
	{
		for (int i = 0; i < SCR_WIDTH; i++)
		{
			front_buffer[j][i] = '1';
			back_buffer[j][i] = '0';
		}
	}
	hidecursor();
	system("mode con:cols=200 lines=60");
	print_character(1);
	while (1)
	{
		InputKey();
		print_bloack();
		print_character(1);
		render();
	}
		
	
}

void drawAll()
{

}


void print_bloack()
{
	for (int h = 0; h < 6; h++)
	{
		for (int w = 0; w < 11; w++)
		{
			drawToBackBuffer(h + 38, 44 + w, mainstair[h][w]);
		}
	}
}


void moveCursorTo(const int x, const int y)
{
	const COORD pos = { x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void InputKey() {

	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 32: // space
			print_character(1);
			characterrender();
			Sleep(100);
			print_character(2);
			characterrender();
			Sleep(100);
			print_character(3);
			characterrender();
			Sleep(100);
			print_character(4);
			characterrender();
			Sleep(100);
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

void backgroundreset() {
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			main_background[i][j] = '0';
		}
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

void gotoxy(int x, int y)

{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void test()
{
	for (int h = 0; h < 60; h++)
	{
		for (int w = 0; w < 100; w++)
		{
			printf("%d", back_buffer[h][w]);
		}
		printf("\n");
	}
}

void print_character(int scene)
{
	if (scene == 1)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{
				drawToBackBuffer(22 + h, 42 + w, mainchar_1[h][w]);
			}
		}
	}
	else if (scene == 2)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{

				drawToBackBuffer(22 + h, 42 + w, mainchar_2[h][w]);
			}
		}
	}
	else if (scene == 3)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{

				drawToBackBuffer(22 + h, 42 + w, mainchar_3[h][w]);
			}
		}
	}
	else if (scene == 4)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{
				drawToBackBuffer(22 + h, 42 + w, mainchar_4[h][w]);
			}
		}
	}

}