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
int isEnd = 0;
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

char dead_face[16][16] = {
	{"0000000000000000"},
	{"0000111111100000"},
	{"8001233333210000"},
	{"8012111311121000"},
	{"8013131313131000"},
	{"0013111311131000"},
	{"8013333333331000"},
	{"0013331113331000"},
	{"0001331313311000"},
	{"0000121112110000"},
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

char score_0[16][7] = {
	{"0111110"},
	{"1111111"},
	{"1110111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1110111"},
	{"1111111"},
	{"0111110"},
};
char score_1[16][7] = {
	{"0001100"},
	{"0011100"},
	{"1111100"},
	{"1111100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"0011100"},
	{"1111111"},
	{"1111111"},
};

char score_2[16][7] = {
	{"0011110"},
	{"0111111"},
	{"1111111"},
	{"1110111"},
	{"1100011"},
	{"0000011"},
	{"0000011"},
	{"0000111"},
	{"0001111"},
	{"0011110"},
	{"0111100"},
	{"1111000"},
	{"1110000"},
	{"1100000"},
	{"1111111"},
	{"1111111"},
};


char score_3[16][7] = {
	{"0111110"},
	{"1111111"},
	{"1110111"},
	{"1100011"},
	{"1100011"},
	{"0000011"},
	{"0000011"},
	{"1111111"},
	{"1111111"},
	{"0000011"},
	{"0000011"},
	{"1100011"},
	{"1100011"},
	{"1110111"},
	{"1111111"},
	{"0111110"},
};

char score_4[16][7] = {
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1100110"},
	{"1111111"},
	{"1111111"},
	{"0000110"},
	{"0000110"},
	{"0000110"},
	{"0000110"},
	{"0000110"},
	{"0000110"},
};

char score_5[16][7] = {
	{"1111111"},
	{"1111111"},
	{"1100000"},
	{"1100000"},
	{"1100000"},
	{"1100000"},
	{"1111111"},
	{"1111111"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"1111111"},
	{"1111111"},
};

char score_6[16][7] = {
	{"1111111"},
	{"1111111"},
	{"1100000"},
	{"1100000"},
	{"1100000"},
	{"1100000"},
	{"1111111"},
	{"1111111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1111111"},
	{"1111111"},
};


char score_7[16][7] = {
	{"1111111"},
	{"1111111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
};

char score_8[16][7] = {
	{"1111111"},
	{"1111111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1111111"},
	{"1111111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1111111"},
	{"1111111"},
};

char score_9[16][7] = {
	{"1111111"},
	{"1111111"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1100011"},
	{"1111111"},
	{"1111111"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"0000011"},
	{"1111111"},
	{"1111111"},
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

void score_printf(int score_math);

void print_character_left(int scene);
void moveCursorTo(const int x, const int y);
int key;
int life = 1;
int player_dead_loc = 22;
int keying = 0;
int score = 0;


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


void player_dead()
{
	for (int h = 0; h < 16; h++)
	{
		for (int w = 0; w < 16; w++)
		{
			if (dead_face[h][w] != '0')
			{
				drawToBackBuffer(player_dead_loc + h, 42 + w, dead_face[h][w]);
			}
		}
	}
}


int main()                                                                                                                //메인
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

		
		if (life == 1) {
				InputKey();
			

			score_printf(score);
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
		else {
			print_bloack();
			player_dead();
			render();
			keying = 1;

			if (player_dead_loc == 22)
			{
				Sleep(1000);
			}
			player_dead_loc++;

			if (player_dead_loc > 70)
			{
				int savestair[16] = { 0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
				for (int i = 0; i < 16; i++)
				{
					stair[i] = savestair[i];
				
				}

				Sleep(1000);
				keying = 0;
				player_dead_loc = 22;
				life = 1;
				isEnd = 0;
			}
		}
		
	}
		
	
}


void score_printf(int score_math)
{
	int print_score_index[10001] = { 0, };
	int n;

	n = score_math;
	int count = 0;
	int number = 46;
	while (n != 0)
	{
		print_score_index[count] = n % 10;
		n = n / 10;
		++count;
	}
	if (count == 0)
	{
		count = 1;
	}
	number -= count * 4;
	for (int i = count - 1; i >= 0; i--)
	{
		for (int h = 0; h < 16; h++)
		{
			for (int w = 0; w < 7; w++)
			{
				if (print_score_index[i] == 0)
				{
					if (score_0[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_0[h][w]);
					}
				}
				if (print_score_index[i] == 1)
				{
					if (score_1[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_1[h][w]);
					}
				}
				if (print_score_index[i] == 2)
				{
					if (score_2[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_2[h][w]);
					}
				}
				if (print_score_index[i] == 3)
				{
					if (score_3[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_3[h][w]);
					}
				}
				if (print_score_index[i] == 4)
				{
					if (score_4[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_4[h][w]);
					}
				}
				if (print_score_index[i] == 5)
				{
					if (score_5[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_5[h][w]);
					}
				}
				if (print_score_index[i] == 6)
				{
					if (score_6[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_6[h][w]);
					}
				}
				if (print_score_index[i] == 7)
				{
					if (score_7[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_7[h][w]);
					}
				}
				if (print_score_index[i] == 8)
				{
					if (score_8[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_8[h][w]);
					}
				}
				if (print_score_index[i] == 9)
				{
					if (score_9[h][w] != '0')
					{
						drawToBackBuffer(2 + h, number + w, score_9[h][w]);
					}
				}

			}
		}
		number += 8;
	}
	for (int i = 0; i < 1000; i++)
	{
		print_score_index[i] = 0;
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

				scoreprint(score);
				characterrender();

				Sleep(10);

				print_bloack();
				print_character_left(2);
				scoreprint(score);
				render();
				Sleep(10);

				up();
				score++;

				print_bloack();
				print_character_left(3);
				scoreprint(score);
				render(); 
				Sleep(10);

				print_bloack();
				print_character_left(4);
				scoreprint(score);
				characterrender();
				Sleep(10);
			}

			else {
				player_dir = 2;
				print_bloack();
				print_character_left(1);
				characterrender();

				Sleep(10);

				print_bloack();
				print_character_left(2);
				characterrender();
				Sleep(10);

				print_bloack();
				print_character_left(3);
				render();
				Sleep(10);

				print_bloack();
				print_character_left(4);
				characterrender();
				Sleep(10);

				life = 0;
			}
			
			break;
		case 77: // right
			if (stair[PLAYER_LOACATION] == 1)
			{

				player_dir = 1;
				print_bloack();
				print_character(1);
				scoreprint(score);
				characterrender();
				Sleep(10);

				print_bloack();
				print_character(2);
				scoreprint(score+1);
				
				render();
				Sleep(10);
				up();
				score++;
				scoreprint(score);
				print_bloack();
				print_character(3);
				render();
				Sleep(10);

				print_bloack();
				print_character(4);
				characterrender();
				Sleep(10);
			}
			else {

				player_dir = 1;
				print_bloack();
				print_character(1);
				characterrender();
				Sleep(10);

				print_bloack();
				print_character(2);
				characterrender();
				Sleep(10);

				print_bloack();
				print_character(3);
				render();
				Sleep(10);

				print_bloack();
				print_character(4);
				characterrender();
				Sleep(10);

				life = 0;

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
