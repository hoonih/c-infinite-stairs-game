#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 

#include <stdlib.h> // rand() 함수 포함 라이브러리

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

#define COLOR_BLOACKTACK	"\033[48;2;228;255;0m" // 노란색

#define SCR_HEIGHT 60
#define SCR_WIDTH 100

#define PLAYER_LOACATION 5

char main_background[SCR_HEIGHT][SCR_WIDTH] = { '0', };

char front_buffer[SCR_HEIGHT][SCR_WIDTH];
char back_buffer[SCR_HEIGHT][SCR_WIDTH];

int stair[16] = {0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};

int player_dir = 1;

char mainstair[4][9] = {
	{"444444444"},
	{"466766654"},
	{"467466764"},
	{"444444444"},
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
	{"0000133333110000"},
	{"0001333333331000"},
	{"0013332111111000"},
	{"0001111000000000"},
	{"0080000000000000"},
	{"0888000000000000"},
	{"0080000000000000"},
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
	{"0080000001100000"},
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

void print_character_left(int scene);
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
				else if (back_buffer[i][j] == '8')
				{
					printf("%s  %s", COLOR_BLOACKTACK, COLOR_RESET);
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
				else if (back_buffer[22+i][42+j] == '4')
				{
					printf("%s  %s", COLOR_BLOACK1, COLOR_RESET);
				}
				else if (back_buffer[22 + i][42 + j] == '5')
				{
					printf("%s  %s", COLOR_BLOACK2, COLOR_RESET);
				}
				else if (back_buffer[22 + i][42 + j] == '6')
				{
					printf("%s  %s", COLOR_BLOACK3, COLOR_RESET);
				}
				else if (back_buffer[22+i][42 + j] == '7')
				{
					printf("%s  %s", COLOR_BLOACK4, COLOR_RESET);
				}
				else if (back_buffer[22 + i][42 + j] == '8')
				{
					printf("%s  %s", COLOR_BLOACKTACK, COLOR_RESET);
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
		if (player_dir == 1)
		{
			print_character(1);
		}
		if (player_dir == 2)
		{
			print_character_left(1);
		}
		render();
	}
		
	
}

void up()
{
	int random_block;
	for (int i = 0; i < 15; i++)
	{
		stair[i] = stair[i + 1];

	}

	srand(time(NULL));
	random_block = rand() % 2 + 1; // 난수 생성
	stair[15] = random_block;
}


void print_bloack()
{
	int n = 38;
	int m = 45;
	for (int i = 5; i < 17; i++)
	{
		if (stair[i] != 0)
		{
			for (int h = 0; h < 4; h++)
			{
				for (int w = 0; w < 9; w++)
				{
					if (m+w < 100 && m + w > 0)
					{
						drawToBackBuffer(h + n, m + w, mainstair[h][w]);
					}

				}
			}
			n -= 4;
			if (stair[i] == 1)
			{
				m += 9;

			}
			else if (stair[i] == 2)
			{
				m -= 9;
			}
		}
		
	}
	n = 38;
	m = 45;
	for (int i = 4; i >= 0; i--)
	{
		if (stair[i] != 0)
		{
			if (stair[i] == 1)
			{
				m -= 9;

			}

			if (stair[i] == 2)
			{
				m += 9;

			}
			n += 4;
			for (int h = 0; h < 4; h++)
			{
				for (int w = 0; w < 9; w++)
				{
					drawToBackBuffer(h + n, m + w, mainstair[h][w]);
				}
			}
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

			
			break;
		case 75: // left
			if (stair[PLAYER_LOACATION] == 2)
			{
				player_dir = 2;
				print_bloack();
				print_character_left(1);
				characterrender();

				Sleep(10);

				print_bloack();
				print_character_left(2);
				characterrender();
				Sleep(10);

				up();

				print_bloack();
				print_character_left(3);
				render(); 
				Sleep(10);

				print_bloack();
				print_character_left(4);
				characterrender();
				Sleep(10);
			}
			
			break;
		case 77: // right
			if (stair[PLAYER_LOACATION] == 1)
			{

				player_dir = 1;
				print_bloack();
				print_character(1);
				characterrender();
				Sleep(10);

				print_bloack();
				print_character(2);
				characterrender();
				Sleep(10);
				up();

				print_bloack();
				print_character(3);
				render();
				Sleep(10);

				print_bloack();
				print_character(4);
				characterrender();
				Sleep(10);
			}
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
				if (mainchar_1[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 42 + w, mainchar_1[h][w]);
				}
			}
		}
	}
	else if (scene == 2)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{
				if (mainchar_2[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 42 + w, mainchar_2[h][w]);
				}
			}
		}
	}
	else if (scene == 3)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{

				if (mainchar_3[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 42 + w, mainchar_3[h][w]);
				}
			}
		}
	}
	else if (scene == 4)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 16; w++)
			{

				if (mainchar_4[h][w] != '0')
				{

					drawToBackBuffer(22 + h, 42 + w, mainchar_4[h][w]);
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
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_1[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 56 - w, mainchar_1[h][w]);
				}
			}
		}
	}
	else if (scene == 2)
	{

		for (int h = 15; h >= 0; h--)
		{
			for (int w = 15; w >= 0; w--)
			{
				if (mainchar_2[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 56 - w, mainchar_2[h][w]);
				}
			}
		}
	}
	else if (scene == 3)
	{

		for (int h = 15; h >= 0; h--)
		{
			for (int w = 15; w >= 0; w--)
			{

				if (mainchar_3[h][w] != '0')
				{
					drawToBackBuffer(22 + h, 56 - w, mainchar_3[h][w]);
				}
			}
		}
	}
	else if (scene == 4)
	{

		for (int h = 15; h >= 0; h--)
		{
			for (int w = 15; w >= 0; w--)
			{

				if (mainchar_4[h][w] != '0')
				{

					drawToBackBuffer(22 + h, 56 - w, mainchar_4[h][w]);
				}
			}
		}
	}

}
