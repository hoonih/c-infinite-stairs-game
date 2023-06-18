#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h> 

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    printf("가나다라마바사");
    gotoxy(1, 0);

    printf("마");

}