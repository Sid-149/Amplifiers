#include<stdio.h>
#include<conio.h>

void main()
{
float Rf,R,R1,c,f,pi;
clrscr();
pi=3.14;
c=(0.1)/1000000;
printf("Enter the cut-off frequency(Hertz):");
scanf("%f",&f);
printf("Enter R1(Ohms):");
scanf("%f",&R1);
R=1/(2*pi*f*c);
Rf=0.586*(R1);
printf("R:%f Ohms & Rf:%f Ohms",R,Rf);
getch();
}