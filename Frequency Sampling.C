#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>

void draw_axis()
{
    cleardevice();

    line(50,300,500,300);
    line(100,200,100,400);

    outtextxy(60,310,"(0,0)");
}
void main()
{
    int gdriver = DETECT, gmode, errorcode;
    int ch2,a,f,ch,t1,flag,Ts,b,cnt;
    float x,y,t,i,j,Tsf;

    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

    do
    {
	cleardevice();
	printf("\n\n****Menu****\n\n1.Sine Wave\n2.Cosine Wave"
	"\n3.Expo Wave\n4.Random Signal\n5.Square Wave\n6.Exit"
	"\n\nEnter Your Choice : ");
	scanf("%d",&ch);

	switch(ch)
	{
	    case 1:
		printf("\n\nEnter Amplitude : ");
		scanf("%d",&a);

		printf("\n\nEnter Frequency : ");
		scanf("%d",&f);

		do
		{

		draw_axis();

		for(t=0;t<400;t++)
		{
		    y=(a)*sin(6.28*f*t);
		    delay(1);
		    putpixel(t+100,y+300,WHITE);
		}

		outtextxy(50,50,"Enter Ts : ");
		scanf("%d",&Ts);

		for(t=0;t<400;t+=Ts)
		{
		    y=(a)*sin(6.28*f*t);
		    delay(1);
		    line(t+100,300,t+100,y+300);
		}

		outtextxy(50,60,"Do You Want To Change Ts(1/0) : ");
		scanf("%d",&ch2);
		}while(ch2==1);

		break;

	    case 2:
		printf("\n\nEnter Amplitude : ");
		scanf("%d",&a);

		printf("\n\nEnter Frequency : ");
		scanf("%d",&f);

		do
		{

		draw_axis();

		for(t=0;t<400;t++)
		{
		    y=(-a)*cos(6.28*f*t);
		    delay(1);
		    putpixel(t+100,y+300,WHITE);
		}

		outtextxy(50,50,"Enter Ts : ");
		scanf("%d",&Ts);

		for(t=0;t<400;t+=Ts)
		{
		    y=(-a)*cos(6.28*f*t);
		    delay(1);
		    line(t+100,300,t+100,y+300);
		}

		outtextxy(50,60,"Do You Want To Change Ts(1/0) : ");
		scanf("%d",&ch2);

		}while(ch2==1);

		break;

	    case 3:
		printf("\n\nEnter a : ");
		scanf("%d",&a);

		printf("\n\nEnter b : ");
		scanf("%d",&b);

		do
		{

		draw_axis();

		//a * e ^ ( b * t )
		for(t=0,x=0;t<10;t+=.01,x=x+.5)
		    putpixel(t+100+x,a*exp(b*t)+300,WHITE);

		outtextxy(50,50,"Enter Ts : ");
		scanf("%f",&Tsf);

		for(t=0,x=0;t<10;t+=Tsf,x=x+(50*Tsf))
		    line(t+100+x,300,t+100+x,a*exp(b*t)+300);

		outtextxy(50,60,"Do You Want To Change Ts(1/0) : ");
		scanf("%d",&ch2);
		}while(ch2==1);

		break;

	    case 4:

		draw_axis();
		randomize();

		for(t=0,a=random(40);t<400;t=t+3,a=a+1)
		{
		    f=random(25);
		    if(a%2==0)
		    {
			y=(a)*sin(6.28*f*t);
			putpixel(t+100,y+300,WHITE);
		    }
		    else
		    {
			y=(a)*cos(3.14*f*t);
			putpixel(t+100,y+300,RED);
		    }
		    delay(10);
		}
		break;

	    case 5:
		printf("\n\nEnter Amplitude : ");
		scanf("%d",&a);

		do
		{

		draw_axis();
		x=100;
		y=300;
		for(t1=0;t1<4;t1++)
		{
		    line(x,y+a,x,y-a);
		    delay(100);
		    line(x,y-a,x+50,y-a);
		    delay(100);
		    x=x+50;

		    line(x,y-a,x,y+a);
		    delay(100);
		    line(x,y+a,x+50,y+a);
		    delay(100);
		    x=x+50;
		}

		outtextxy(50,50,"Enter Ts : ");
		scanf("%d",&Ts);
		b=50/Ts;
		cnt=0,flag=0;

		for(t1=Ts;t1<400;t1=t1+Ts)
		{
		 //   if(t1%50 !=0)
		    {
		    if(flag==0)
		    {
			line(t1+100,y,t1+100,y-a);
			cnt++;
			if(cnt==b)
			{
			    flag=1;
			    cnt=0;
			    goto l1;
			}
		    }

		    if(flag==1)
		    {
			line(t1+100,y,t1+100,y+a);
			cnt++;
			if(cnt==b)
			{
			    flag=0;
			    cnt= 0;
			}
		    }
		    l1:
		    }
		}

		outtextxy(50,60,"Do You Want To Change Ts(1/0) : ");
		scanf("%d",&ch2);
		}while(ch2==1);

		break;

	    case 6: exit(0);
	}
	outtextxy(50,450,"Press 1 To Continue...");
	scanf("%d",&flag);
    }while(flag==1);

    getch();
    closegraph();
}