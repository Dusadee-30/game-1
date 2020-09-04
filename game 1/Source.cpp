#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y)
{
		gotoxy(x, y);
		printf("          ");
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);
	printf(" [--:0:--]  ");
} 
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);

	do {
			if (_kbhit())
			{
				ch = _getch();
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 'w' && y != 0) 
				{
					draw_ship(x, --y);
					erase_ship(x, ++y);
					y -= 1;
				}
				if (ch == 's')
				{ 
					draw_ship(x, ++y);
					erase_ship(x, --y);
					y += 1;
				}
				if (y <= 0)
				{
					gotoxy(x, 0);
					y = 0;
				}
				if (x <= 0)
				{
					gotoxy(0, y);
					x = 0;
				}
				if (x >= 109)
				{
					gotoxy(109, y);
					x = 109;
				}
				fflush(stdin);

			}
			Sleep(100);
	} while (ch != 'x');
	return 0;
}