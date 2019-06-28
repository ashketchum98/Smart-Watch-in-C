#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include"tone1.h"

#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\n\n\n\t\t\tJanuary",
	"\n\n\n\n\n\t\t\tFebruary",
	"\n\n\n\n\n\t\t\tMarch",
	"\n\n\n\n\n\t\t\tApril",
	"\n\n\n\n\n\t\t\tMay",
	"\n\n\n\n\n\t\t\tJune",
	"\n\n\n\n\n\t\t\tJuly",
	"\n\n\n\n\n\t\t\tAugust",
	"\n\n\n\n\n\t\t\tSeptember",
	"\n\n\n\n\n\t\t\tOctober",
	"\n\n\n\n\n\t\t\tNovember",
	"\n\n\n\n\n\t\t\tDecember"
};




void calender(void);
int determineleapyear(int);
void calendar(int, int ,int);
int determinedaycode(int);
void dc(void);
void frame(void);
void sw(void);
void logo(void);
void initial(void);
void timer(void);
void ac(void);
void design(void);
void world(void);

void selection()
{
 int a=0;
 char c;
 setcolor(RED);
 rectangle(0+a,40,100+a,80);
 while(1)
 {
 go:
 c=getch();
 if(c==100)
 {
 if(a==500)
  {

  }
  else if(a==400)
  {
   a=a+100;
   cleardevice();
   frame();
   logo();
   setcolor(RED);
   rectangle(0+a,40,620,80);
  }
  else
  {
	cleardevice();
	frame();
	logo();
	a=a+100;
	setcolor(RED);
	rectangle(0+a,40,100+a,80);
  }
 }
 else if(c==97)
 {
  if(a==0)
  {

  }
  else
  {
   cleardevice();
   frame();
   logo();
   a=a-100;
   setcolor(RED);
   rectangle(0+a,40,100+a,80);
  }
 }
 else if(c==119)
 {
  if(a==0)
  {
   ac();
  }
  else if(a==100)
  {
   dc();
  }
  else if(a==200)
  {
   sw();
   setcolor(RED);
   rectangle(0+a,40,100+a,80);
   goto go;
  }
  else if(a==300)
  {
   timer();
  }
  else if(a==400)
  {
   calender();
  }
  else if(a==500)
  {
   world();
  }
 }
 else if(c==27)
 {
  exit(1);
 }
 }
}

void frame()
{
 int z;
 setcolor(WHITE);
 rectangle(0,0,620,480);
 line(0,40,620,40);
 settextstyle(1,HORIZ_DIR,3);
 setcolor(RED);
 floodfill(180,6,WHITE);
 outtextxy(180,6,"**** Smart Watch ****");
 setcolor(WHITE);
 line(0,80,620,80);
 line(100,40,100,80);
 line(200,40,200,80);
 line(300,40,300,80);
 line(400,40,400,80);
 line(500,40,500,80);
 settextstyle(2,HORIZ_DIR,6);
 outtextxy(20,45,"Analog");
 outtextxy(120,45,"Digital");
 outtextxy(210,45,"StopWatch");
 outtextxy(320,45,"Timer");
 outtextxy(410,45,"Calender");
 outtextxy(510,45,"World Clock");

}


void dc()
{
	long t;
	char date[250];
	setcolor(RED);
	while(!kbhit())
{
	cleardevice();
	frame();
	t=time(NULL);
	setcolor(RED);
	strcpy(date,ctime(&t));
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(60,200,"***** DIGITAL CLOCK *****");
	setcolor(WHITE);
	outtextxy(25,300,date);
	delay(1000);
}
}


void sw()
{
	int i=0,j=0,k=0;
	int midx,midy;
	char number[100],a,b;
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	fflush(stdin);
	while(1)
{
	if(kbhit())
{
	a=getch();
	if(a=='e')
		return;
	if(a=='s')
{
	i=0;
	j=0;
	k=0;
}
}


	cleardevice();
	frame();
	settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
	setcolor(RED);
	outtextxy(midx-220,midy+140," S : To start again ");
	outtextxy(midx-220,midy+170," E : To Exit Stopwatch ");
	outtextxy(midx-220,midy+110," P : To Pause the Output ");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(100,100,"**** STOPWATCH ****");
	moveto(midx-110,midy);
	setcolor(WHITE);
	sprintf(number,"%d :: %d :: %d",k,j,i);
	outtext(number);
	setcolor(RED);
	delay(1000);
	if(a=='p')
{
	while(!kbhit())
{
	if(kbhit())
	b=kbhit();
	if(b=='e')
		return;
}
}
	cleardevice();
	frame();
	i++;
	fflush(stdin);
	if(i>59)
{
	i=0;
	j++;
}
	if(j>59)
{
	j=0;
	k++;
}
}
}

void logo()
{
 setcolor(BLUE);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(180,250,"Smart Watch");
}




void timer()
{
 int hh=0,mm=0,ss=0;
 char time[50];
 cleardevice();
 initial();
 frame();
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(60,350,"00");
 outtextxy(260,350,"00");
 outtextxy(460,350,"00");
 scanf("%d",&hh);
 scanf("%d",&mm);
 scanf("%d",&ss);
 if(hh<0 || mm<0 || ss<0)
 {
  cleardevice();
  frame();
  setcolor(WHITE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  outtextxy(200,240,"Wrong Inputs");
 }
 else
 {
 while(!kbhit())
 {
  cleardevice();
  initial();
  frame();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  sprintf(time,"%3d      %3d    %5d",hh,mm,ss);
  outtextxy(50,350,time);
  delay(1000);
  if(hh==0 && mm==0 && ss==0)
  {
	cleardevice();
	frame();
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(200,240,"Times Up...");
	tone1();
	break;
  }
  if(hh>0 && mm==0 && ss==0)
  {
	ss=60;
	mm=59;
	hh--;
  }
  if(hh==0 && mm>0 && ss==0)
  {
	ss=60;
	mm--;
  }
  ss--;

 }
 }
}



void initial()
{
 setcolor(RED);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(130,150,"***** TIMER *****");
 setcolor(WHITE);
 outtextxy(30,250,"Hours");
 outtextxy(210,250,"Minutes");
 outtextxy(430,250,"Seconds");
}


void ac()
{
	struct  time t;
	struct arccoordstype second, minute, hour;
	int i,j;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	do
	{
	frame();
	setcolor(WHITE);
	for(j=0;j<10;j++)
	{
	circle(320,300,150-j);
	}
	for(j=0;j<5;j++)
	{
	circle(320,300,120-j);
	}
	setcolor(WHITE);
	//mark four points
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	moveto(308,195);//top
	outtext("12");
	moveto(315,380);//bottom
	outtext("6");
	moveto(415,285);//left
	outtext("3");
	moveto(215,285);//right
	outtext("9");

		setcolor(0);
		line(320,300, second.xend, second.yend);
		line(320,300, minute.xend, minute.yend);
		line(320,300, hour.xend, hour.yend);
		//Store time into struct t
		gettime(&t);
		//hour
		setcolor(0);
		arc(320,300,270,90-(t.ti_hour*30),60);
		setcolor(WHITE);
		getarccoords(&hour);
		line(320,300, hour.xend, hour.yend);
		//minute
		setcolor(0);
		arc(320,300,270,90-t.ti_min*6,80);
		setcolor(WHITE);
		getarccoords(&minute);
		line(320,300, minute.xend, minute.yend);
		//center circle
		setcolor(WHITE);
		pieslice(320,300,0,360,5);
		//second
		setcolor(0);
		arc(320,300,270,90-t.ti_sec*6,90);
		setcolor(RED);
		getarccoords(&second);
		line(320,300, second.xend, second.yend);
		delay(1000);

		} while(!kbhit());
}




void world()
{

 struct time t;
 int hh,mm,ss,b_hh,b_mm,b_ss;
 int x=0,y=0;
 char ch;
 char mytime[256];
 cleardevice();
 frame();
 setcolor(4);
 design();
 setcolor(RED);
 rectangle(0,240,80,280);

 while(1)
 {
  ch=getch();
  if(ch==100)
  {
   if(y==0)
   {
   if(x==480)
   {
	cleardevice();
	design();
	frame();
	x+=80;
	setcolor(RED);
	rectangle(0+x,240,620,280);
   }
   else if(x<480)
   {
	cleardevice();
	design();
	frame();
	x+=80;
	setcolor(RED);
	rectangle(0+x,240,80+x,280);
   }
   else
   {

   }
   }
   else
   {
    if(x==480)
    {
	cleardevice();
	design();
	frame();
	x+=80;
	setcolor(RED);
	rectangle(0+x,280,620,320);
    }
    else if(x<480)
    {
	cleardevice();
	design();
	frame();
	x+=80;
	setcolor(RED);
	rectangle(0+x,280,80+x,320);
    }
    else
    {

    }
   }
  }
  else if(ch==97)
  {
    if(y==0)
    {
    if(x==0)
    {

    }
    else if(x==560)
    {

	cleardevice();
	design();
	frame();
	x-=80;
	setcolor(RED);
	rectangle(0+x,240,560,280);
    }
    else
    {

	cleardevice();
	design();
	frame();
	x-=80;
	setcolor(RED);
	rectangle(0+x,240,80+x,280);
    }
    }
    else
    {
      if(x==0)
      {

      }
      else if(x==560)
      {
	cleardevice();
	design();
	frame();
	x-=80;
	setcolor(RED);
	rectangle(0+x,280,560,320);
      }
      else
      {
	cleardevice();
	design();
	frame();
	x-=80;
	setcolor(RED);
	rectangle(0+x,280,80+x,320);
      }
    }
  }
  else if(ch==115)
  {
   y=1;
   if(x==560)
   {
	cleardevice();
	design();
	frame();
	setcolor(RED);
	rectangle(0+x,280,620,320);
   }
   else
   {
	cleardevice();
	design();
	frame();
	setcolor(RED);
	rectangle(0+x,280,80+x,320);
   }
  }
  else if(ch==119)
  {
    y=0;
    if(x==560)
   {
	cleardevice();
	design();
	frame();
	setcolor(RED);
	rectangle(0+x,240,620,280);
   }
   else
   {
	cleardevice();
	design();
	frame();
	setcolor(RED);
	rectangle(0+x,240,80+x,280);
   }
  }
  else if(ch==27)
  {
    //	exit(1);
    return;
  }
  else if(ch==13)
  {
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
    switch(x)
    {
	case 0:
	if(y==0)
	{

	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Austin : ");
	  gettime(&t);

	   hh = t.ti_hour;
	   mm = t.ti_min;
	   ss = t.ti_min;

	   b_hh = 10;
	   b_mm = 30;
	   b_ss = 0;


 if(hh>12)
 {
 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

   if( (ss - b_ss) < 0)
  {
   b_ss = ss - b_ss;
   ss = ss + ((-2)*b_ss);
   mm-=1;
  }
  else
  {
   ss-=b_ss;
  }
   hh--;
  }

 else
 {
  hh=hh+1;
  mm=mm+30;
  if(mm>=60)
  {
   hh+=1;
   mm=mm-60;
  }
  hh+=12;
  hh--;
 }


	t.ti_hour=hh;
	t.ti_min=mm;
	settime(&t);
	strcpy(mytime,ctime(&t));
	setcolor(WHITE);
	sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
	outtextxy(50,250,mytime);


	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"London : ");
	   gettime(&t);

	    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 5;
	     b_mm = 30;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);


	}
	break;
	case 80:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Berlin : ");
	  gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 4;
	     b_mm = 30;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Miami : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 9;
	     b_mm = 30;
	     b_ss = 0;

 if(hh>12)
 {
 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   hh--;
   }
   else
   {
    if((hh+2>12))
    {
     hh+=2;
     hh=hh-12;
     mm+=30;
     if(mm>=60)
     {
      mm=mm-60;
      hh++;
     }
    }
    else
    {
    hh=hh+2;
    mm=mm+30;
    if(mm>=60)
    {
     mm=mm-60;
     hh++;
    }
    hh+=12;
    hh--;
    }
   }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 160:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Beijing : ");
	    gettime(&t);
	 hh= t.ti_hour;
	 mm= t.ti_min;
	 hh+=2;
	 mm+=30;
	 if(hh>=24)
	 {
	  hh=hh-24;
	 }
	 if(mm>=60)
	 {
	  mm=mm-60;
	  hh+=1;
	 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);

	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Ottawa : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 9;
	     b_mm = 30;
	     b_ss = 0;
 if(hh>12)
 {
 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
 hh--;
 }
 else
 {
      if((hh+2>12))
    {
     hh+=2;
     hh=hh-12;
     mm+=30;
     if(mm>=60)
     {
      mm=mm-60;
      hh++;
     }
    }
    else
    {
    hh=hh+2;
    mm=mm+30;
    if(mm>=60)
    {
     mm=mm-60;
     hh++;
    }
    hh+=12;
    hh--;
    }
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 240:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Chicago : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 10;
	     b_mm = 30;
	     b_ss = 0;
 if(hh>12)
 {
 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
 hh--;
 }
 else
 {
  hh=hh+1;
  mm=mm+30;
  if(mm>=60)
  {
   hh+=1;
   mm=mm-60;
  }
  hh+=12;
  hh--;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Paris : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 4;
	     b_mm = 30;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 320:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Dakar : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 5;
	     b_mm = 30;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Rome : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 4;
	     b_mm = 30;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 400:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Hanoi : ");
	    gettime(&t);
		 hh= t.ti_hour;
	 mm= t.ti_min;
	 hh+=1;
	 mm+=30;
	 if(hh>=24)
	 {
	  hh=hh-24;
	 }
	 if(mm>=60)
	 {
	  mm=mm-60;
	  hh+=1;
	 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);

	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Sydney : ");
	    gettime(&t);
		 hh= t.ti_hour;
	 mm= t.ti_min;
	 hh+=5;
	 mm+=30;
	 if(hh>=24)
	 {
	  hh=hh-24;
	 }
	 if(mm>=60)
	 {
	  mm=mm-60;
	  hh+=1;
	 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 480:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Kabul : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 1;
	     b_mm = 0;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Tehran : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 2;
	     b_mm = 0;
	     b_ss = 0;

 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	break;
	case 560:
	if(y==0)
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Lima : ");
	    gettime(&t);
		    hh = t.ti_hour;
	    mm = t.ti_min;
	    ss = t.ti_min;

	     b_hh = 10;
	     b_mm = 30;
	     b_ss = 0;
 if(hh>12)
 {
 if( (hh - b_hh) < 0 )
 {
  b_hh = hh - b_hh;
  hh = b_hh + ((-2)*b_hh);
 }
 else
 {
  hh-=b_hh;
 }

 if( (mm - b_mm) < 0 )
 {
  b_mm = mm - b_mm;
  mm = mm + ((-2)*b_mm);
  hh-=1;
 }
 else
 {
  mm-=b_mm;
 }

 if( (ss - b_ss) < 0)
 {
  b_ss = ss - b_ss;
  ss = ss + ((-2)*b_ss);
  mm-=1;
 }
 else
 {
  ss-=b_ss;
 }
 }
 else
 {
  hh=hh+1;
  mm=mm+30;
  if(mm>=60)
  {
   hh+=1;
   mm=mm-60;
  }
  hh+=12;
 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);
	}
	else
	{
	  cleardevice();
	  frame();
	  setcolor(RED);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	  outtextxy(50,180,"Tokyo : ");
	    gettime(&t);

		 hh= t.ti_hour;
	 mm= t.ti_min;
	 hh+=3;
	 mm+=30;
	 if(hh>=24)
	 {
	  hh=hh-24;
	 }
	 if(mm>=60)
	 {
	  mm=mm-60;
	  hh+=1;
	 }
   t.ti_hour=hh;
   t.ti_min=mm;
   settime(&t);
   strcpy(mytime,ctime(&t));
   setcolor(WHITE);
   sprintf(mytime,"%d hh : %d mm : %d ss",t.ti_hour,t.ti_min,t.ti_sec);
   outtextxy(50,250,mytime);

	}
	break;
    }
  }

 }
 }


void design()
{
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 setcolor(RED);
 outtextxy(100,120,"**** World Clock ****");
 setcolor(WHITE);
 line(0,240,620,240);
 line(0,280,620,280);
 line(0,320,620,320);
 line(80,240,80,280);
 line(160,240,160,280);
 line(240,240,240,280);
 line(320,240,320,280);
 line(400,240,400,280);
 line(480,240,480,280);
 line(560,240,560,280);
 line(80,280,80,320);
 line(160,280,160,320);
 line(240,280,240,320);
 line(320,280,320,320);
 line(400,280,400,320);
 line(480,280,480,320);
 line(560,280,560,320);
 settextstyle(2,HORIZ_DIR,6);
 outtextxy(10,245,"Austin");
 outtextxy(90,245,"Berlin");
 outtextxy(170,245,"Beijing");
 outtextxy(250,245,"Chicago");
 outtextxy(330,245,"Dakar");
 outtextxy(410,245,"Hanoi");
 outtextxy(490,245,"Kabul");
 outtextxy(570,245,"Lima");
 outtextxy(10,285,"London");
 outtextxy(90,285,"Miami");
 outtextxy(170,285,"Ottawa");
 outtextxy(250,285,"Paris");
 outtextxy(330,285,"Rome");
 outtextxy(410,285,"Sydney");
 outtextxy(490,285,"Tehran");
 outtextxy(570,285,"Tokyo");
}


void calender()
{
struct date t;
int year, daycode, leapyear,month;

	cleardevice();
	getdate(&t);
	frame();
	month=t.da_mon;
	year = t.da_year;
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode,month);
      //	printf("\n");


}



int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return (daycode);
}



int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}




void calendar(int year, int daycode,int mon)
{
	int day,month;
	textbackground(BLACK);

	for(month=mon;month<=mon;month++)
	{
	       //	clrscr();
		 frame();
		 gotoxy(35,2);
		daycode = ( daycode + days_in_month[month] ) % 7 +1 ;
		fflush(stdin);
		printf("\n\n\n\n\n\n\n\n\t\t\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n\n" );

		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		     printf("\t\t\t");

		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n\n\t\t\t " );


		}

		frame();
	     }
	}
