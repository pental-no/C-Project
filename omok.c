////#include <stdio.h>
////#include <conio.h>
////#include <windows.h>
////#include <time.h>
////#define LEFT 75
////#define RIGHT 77
////#define UP 72
////#define DOWN 80
////
////void keyboard(int x, int y);
////
////void main(void)
////{
////    
////	SetConsoleTitle(TEXT("c.keyboard"));
////
////	char key = 0;
////	int x = 0;
////	int y = 0;
////	printf("====================================");
////	while(1)
////	{
////		keyboard(x,y);
////		printf("¡Ú");
////			if(kbhit())
////			{
////				key = _getch();
////				switch(key)
////				{
////					case UP:
////					y--;
////					break;
////					
////					case DOWN :
////					y++;
////					break;
////					
////					case LEFT:
////					x--;
////					break;
////					
////					case RIGHT:
////					x++;
////					break;
////					}
////		Sleep(10);
////		system("cls");
////		}
////	}
////}
////
////void keyboard(int x,int y)
////
////{ 
////
//// COORD pos={x,y};
//// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
////
////}
////
//



#include <stdio.h>
#include <windows.h>

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 30
#define MAP_Y 20

int badukdol[30][30] = { 0 };
int dol = 1;
char key;
int x=20, y= 10;
void draw_badukpan();
void gotoxy(int x, int y);
void draw_dol();
void erase_dol(int x, int y);
void insert_key(char key,int *x, int *y);
void put_spacebar(int badukdol[][30], int x, int y);
void draw_badukdol(int badukdol[][30]);
int winner(int badukdol[][30]);
void play();




typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c){
     CONSOLE_CURSOR_INFO CurInfo;
 
     switch (c) {
     case NOCURSOR:
          CurInfo.dwSize=1;
           CurInfo.bVisible=FALSE;
          break;
     case SOLIDCURSOR:
          CurInfo.dwSize=100;
          CurInfo.bVisible=TRUE;
          break;
     case NORMALCURSOR:
          CurInfo.dwSize=20;
          CurInfo.bVisible=TRUE;
          break;
     }
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}




void main(){
	
	printf("½ÃÀÛÇÏ·Á¸é ENTERÀ» ´©¸£¼¼¿ä\n");
	
        
	SetConsoleTitle(TEXT("¿À¸ñ"));
	char ch = getch();
	
	if (ch == 13){ 
		system("cls");
		play();
		
	}

}

void play(){

	draw_badukpan();
	gotoxy(x, y);
	draw_dol();

	do{
		key = getch();
		erase_dol(x,y);
		insert_key(key,&x, &y);
		draw_badukdol(badukdol);
		if (winner(badukdol))
		{
           return;
		}
		gotoxy(x, y);
		draw_dol();
	} while (key != 27);

};

void draw_badukpan(){
	int i, j;
	printf("¦£");
	for (i = 0; i < 20; i++)
	{
		printf("¦¨");
	}
	printf("¦¤\n");
	for (i = 0; i < 20; i++)
	{
		printf("¦§");
		for (j = 0; j < 20; j++)
		{
			printf("¦«");
		}
		printf("¦©\n");
	}
	printf("¦¦");
	for (i = 0; i < 20; i++)
	{
		printf("¦ª");
	}
	printf("¦¥\n");
}

void gotoxy(int x, int y){
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_dol(){
	if (dol == 1)
	{
		printf("¡Ý");
	}
	else{
		printf("¡Ü");
	}
};
void insert_key(char key,int *x, int *y){

	switch (key){
	case 75: if (*x - 2 < 0){
				 break;
	}
			 else{ *x -= 2; }
		
		break;
	case 77: if (*x + 2 > 42)
	{
				 break;
	}
			 else{
				 *x+= 2;
			 }
		
		break;
	case 72: if (*y - 1 < 0)
	{
				 break;
	}
			 else{
				 *y -= 1;
			 }
		break;
	case 80: if (*y + 1 > 21)
	{
				 break;
	}
			 else{
				 *y += 1;
			 }
		break;
	case 32: put_spacebar(badukdol, *x, *y);
		break;

	default:
		break;
	}
}

void put_spacebar(int badukdol[][30], int x, int y){
	if (badukdol[y][x/2] == 0) 
	{
		if (dol == 1)
		{
			badukdol[y][x/2] = 1;
			dol = 2;
		}
		else
		{
			badukdol[y][x/2] = 2;
			dol = 1;
		}
	}
	
	

};

void draw_badukdol(int badukdol[][30])
{
	int i,j;
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (badukdol[j][i] == 1)
			{
				gotoxy(i*2, j);
				printf("¡Ý");
			}
			else if (badukdol[j][i] == 2)
			{
				gotoxy(i*2, j);
				printf("¡Ü");
			}
		}
	}
};
void erase_dol(int x, int y){

	gotoxy(x, y);
	if (x == 0 && y == 0)
	{
		printf("¦£");
	}
	else if (x == 42 && y == 0)
	{
		printf("¦¤");
	}
	else if (x == 0 && y == 21)
	{
		printf("¦¦");
	}
	else if (x == 42 && y == 21)
	{
		printf("¦¥");
	}
	else if (x == 0)
	{
		printf("¦§");
	}
	else if (y == 0)
	{
		printf("¦¨");
	}
	else if (x == 42)
	{
		printf("¦©");
	}
	else if (y == 21)
	{
		printf("¦ª");
	}
	else
	{
		printf("¦«");
	}

};
int winner(int badukdol[][30])
{	
	int i,j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (badukdol[i][j] ==1&& badukdol[i][j + 1] ==1&& badukdol[i][j + 2]==1 && badukdol[i][j + 3] ==1&& badukdol[i][j + 4] ==1)
			{
				gotoxy(20, 10);
					printf("Èæµ¹ ½Â¸®");
					getch();
				return 1;
			}
			else if (badukdol[i][j]==2 && badukdol[i][j + 1] ==2 && badukdol[i][j + 2]==2 && badukdol[i][j + 3] ==2&& badukdol[i][j + 4] ==2)
			{
				gotoxy(20, 10);
				printf("¹éµ¹ ½Â¸®");
				getch();
				return 1;
			}

			else if (badukdol[j][i] ==1&& badukdol[j+1][i]==1 && badukdol[j+2][i] ==1&& badukdol[j+3][i]==1 && badukdol[j+4][i] ==1)
			{
				gotoxy(20, 10);
				printf("Èæµ¹ ½Â¸®");
				getch();
				return 1;
			} 
			else if (badukdol[j][i] ==2 && badukdol[j + 1][i]==2 && badukdol[j + 2][i]==2 && badukdol[j + 3][i] ==2&& badukdol[j + 4][i]==2)
			{
				gotoxy(20, 10);
				printf("¹éµ¹ ½Â¸®");
				getch();
				return 1;
			}

			else if (badukdol[i][j] ==1 && badukdol[i+1][j+1] ==1 && badukdol[i+2][j+2]==1 && badukdol[i+3][j+3] ==1 && badukdol[i+4][j+4] ==1)
			{
				gotoxy(20, 10);
				printf("Èæµ¹ ½Â¸®");
				getch();
				return 1;
			}

			else if (badukdol[i][j] == 2 && badukdol[i + 1][j + 1] == 2 && badukdol[i + 2][j + 2] == 2 && badukdol[i + 3][j + 3] == 2 && badukdol[i + 4][j + 4] == 2)
			{
				gotoxy(20, 10);
				printf("¹éµ¹ ½Â¸®");
				getch();
				return 1;
			}

			else if (badukdol[19-j][i] == 1 && badukdol[18-j][i+1] == 1 && badukdol[17-j][i+2] == 1 && badukdol[16-j][i+3] == 1 && badukdol[15-j][i+4] == 1)
			{
				gotoxy(20, 10);
				printf("Èæµ¹ ½Â¸®");
				getch();
				return 1;
			}
			else if (badukdol[19 - j][i] == 2 && badukdol[18 - j][i + 1] == 2 && badukdol[17 - j][i + 2] == 2 && badukdol[16 - j][i + 3] == 2 && badukdol[15 - j][i + 4] == 2)
			{
				gotoxy(20, 10);
				printf("¹éµ¹ ½Â¸®");
				getch();
				return 1;
			}
		} 
	}
	return 0;
};
