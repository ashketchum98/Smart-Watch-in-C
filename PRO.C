#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include"project.h"

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 cleardevice();
 frame();
 logo();
 selection();
 getch();
 closegraph();
}

