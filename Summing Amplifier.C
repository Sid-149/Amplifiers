#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
float R1,Rf,n,v,sum=0,output;
printf("Enter no. of inputs (n):");
scanf("%f",&n);
printf("Enter value of resistors(R1=Rf):");
scanf("%f",&R1);
Rf=R1;
printf("Enter the input voltages:");
for(int i=1;i<=n;i++)
{
printf("Enter V%d:",i);
scanf("%f",&v);
sum=sum+v;
}
output=-(Rf/R1)*(sum);
printf("Output of summing amplifier:\nVout:%f Volts",output);
getch();
}

