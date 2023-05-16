#include <graphics.h>
#include <bits/stdc++.h>
#include <easyx.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <thread>
#include <mmsystem.h>

using namespace std;
	
int main()
{
	IMAGE chest;
	IMAGE stone;
	IMAGE stonebrick;
	IMAGE target;
	IMAGE hj;
	loadimage(&chest,"picture\\chest.png",50,50);
	loadimage(&stone,"picture\\stone.png",50,50);
	loadimage(&target,"picture\\target.png",50,50);
	loadimage(&stonebrick,"picture\\stonebrick.png",50,50);	
	loadimage(&hj,"picture\\hj.jpg",50,50);
	initgraph(500,350);
	setbkcolor(WHITE);
	cleardevice();
	 int x=3,y=2;char ch;
	char a[20][20]={
					"##########",
					"##     ###",
					"##0###   #",
					"# i 0  0 #",
					"# **# 0 ##",
					"##**#   ##",
					"##########" };
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=6;j++)
		{
			int xx=i*50,yy=j*50;
			switch(a[j][i])
			{
				case '#':putimage(xx,yy,&stonebrick);break;
				case ' ':putimage(xx,yy,&stone);break;
				case '*':putimage(xx,yy,&target);break;
				case '0':putimage(xx,yy,&chest);break;
				case 'i':putimage(xx,yy,&hj);break;
			}
		}
	}
	while(1)
	{
		ch=getch();
		if(ch=='a')
		{
			if(a[x][y-1]!='#')
			{
				if(a[x][y-1]=='0'&&a[x][y-2]!='#'&&a[x][y-2]!='0')//the player can let the box move.
				{ 
					a[x][y]=' ';y--;a[x][y]='i';//the player move.
					a[x][y-1]='0';
				}
				else
				{
					if(a[x][y-1]!='0'&&a[x][y-1]!='#')//the player can move.
					{
						a[x][y]=' ';y--;a[x][y]='i';//the player move.
					}
				}
			}
		}
		if(ch=='d')
		{
			if(a[x][y+1]!='#')
			{
				if(a[x][y+1]=='0'&&a[x][y+2]!='#'&&a[x][y+2]!='0')//the player can let the box move.
				{
					a[x][y]=' ';y++;a[x][y]='i';//the player move.
					a[x][y+1]='0';
				}
				else
				{
					if(a[x][y+1]!='0'&&a[x][y+1]!='#')//the player can move.
					{
						a[x][y]=' ';y++;a[x][y]='i';//the player move.
					}
				}
			}
		}
		if(ch=='w')
		{
			if(a[x-1][y]!='#')
			{
				if(a[x-1][y]=='0'&&a[x-2][y]!='#'&&a[x-2][y]!='0')//the player can let the box move.
				{
					a[x][y]=' ';x--;a[x][y]='i';//the player move.
					a[x-1][y]='0';
				}
				else
				{
					if(a[x-1][y]!='0'&&a[x-1][y]!='#')//the player can move.
					{
						a[x][y]=' ';x--;a[x][y]='i';//the player move.
					}
				}
			}
		}
		if(ch=='s')
		{
			if(a[x+1][y]!='#')
			{
				if(a[x+1][y]=='0'&&a[x+2][y]!='#'&&a[x+2][y]!='0')//the player can let the box move.
				{
					a[x][y]=' ';x++;a[x][y]='i';//the player move.
					a[x+1][y]='0';
				}
				else
				{
					if(a[x+1][y]!='0'&&a[x+1][y]!='#')//the player can move.
					{
						a[x][y]=' ';x++;a[x][y]='i';//the player move.
					}
				}
			}
		}
	if(a[4][2]!='i'&&a[4][2]!='0')
	{
		a[4][2]='*';
			}
	if(a[4][3]!='i'&&a[4][3]!='0')
	{
		a[4][3]='*';
			}
	if(a[5][3]!='i'&&a[5][3]!='0')
	{
		a[5][3]='*';
			}
	if(a[5][2]!='i'&&a[5][2]!='0')
	{
		a[5][2]='*';
			}		
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=6;j++)
		{
			int xx=i*50,yy=j*50;
			switch(a[j][i])
			{
				case '#':putimage(xx,yy,&stonebrick);break;
				case ' ':putimage(xx,yy,&stone);break;
				case '*':putimage(xx,yy,&target);break;
				case '0':putimage(xx,yy,&chest);break;
				case 'i':putimage(xx,yy,&hj);break;
			}
		}
	}							
	if(a[4][2]=='0'&&a[4][3]=='0'&&a[5][2]=='0'&&a[5][3]=='0') 
	{
		Sleep(500);
		break;
	}
	
	}	
	closegraph();
	cout<<"you win!";
	return 0;
}