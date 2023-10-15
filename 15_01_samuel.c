
#include<stdio.h>
void main()
{
int a,b,c,e;
printf("enter a number:");
scanf("%d",&e);
if((e==0)||(e==1))
	printf("\n %d is a fibonacci number",e);
else
{
a=0;
b=1;
c=a+b;
while(c<e)
	{
	a=b;
	b=c;
	c=a+b;
	}
	if(c==e)
	printf("\n %d is fibonacci number",e);
	else
	printf("\n %d is not fibonacci number",e);
}	
}
