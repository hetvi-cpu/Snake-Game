#include<stdio.h>
#include<conio.h>

void main()
{
int xCord=60;
int yCord=12;
int snakeXcord=30;
int snakeYcord=12;
char key;
int diffX,diffY;
int score=0;
int life=3;
int level=1;
int i=0;
char a[50];
textbackground(7);
textcolor(0);
clrscr();
gotoxy(32,3);
cprintf("HUNGRY SNAKE\n");
gotoxy(32,12);
textbackground(BLACK);
textcolor(WHITE);
cprintf("  \t\t\ START \t\t  ");
key=getch();
 if(key==13||key==32)
 {
 start:
 clrscr();
 textbackground(GREEN);
 textcolor(RED);
 gotoxy(30,1);
 printf("score=%d",score);
 gotoxy(38,1);
 printf("level=%d",level);
 gotoxy(48,1);
 printf("life=%d",life);
 gotoxy(xCord,yCord);
 printf("*");
  for(i=0;i<=score;i++)
   {
    a[i]='o';
    if(key==72||key==80)
    {
    gotoxy(snakeXcord,snakeYcord+i);
    printf("%c",a[i]);
    }
    else
    {
    gotoxy(snakeXcord+i,snakeYcord);
    printf("%c",a[i]);
    }
   }
  kbhit:
  if(kbhit())
  {
   key=getch();
   if(key==72)
   {
    snakeYcord--;
   }
   else if(key==80)
   {
    snakeYcord++;
   }
   else if(key==75&&snakeXcord>=2)
   {
    snakeXcord--;
   }
   else if(key==77&&snakeXcord<=78)
   {
    snakeXcord++;
   }
   else if(key=='x'||key=='X')
   {
    exit(0);
   }
  }
  diffX=(snakeXcord-xCord)+score;
  diffY=(snakeYcord-yCord)+score;
  if(snakeXcord<=2 ||snakeXcord>=79)
  {
   life--;
   score=0;
   if(life==0)
   {
   clrscr();
   gotoxy(35,12);
   printf("GAMEOVER");
   delay(500);
   getch();
   exit(0);
   }
   else
   {
   snakeXcord=30;
   snakeYcord=12;
   goto start;
   }
  }
  if((diffX==0||diffX==score) && (diffY==0||diffY==score))
  {
   xCord=rand()%80;
   yCord=rand()%25;
   delay(50);
   score++;
   goto start;
  }
   else
  {
  delay(60);
  goto start;
  }
  }
getch();
}




