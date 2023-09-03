
#include<stdio.h>
#include<stdlib.h>

/* defining 6 as size */
#define size 6

/* Queue initialization */
int queue[size];
int f = -1;
int r = -1;

/* function prototypes */
void enqueue(int);
void dequeue();
void isEmpty();
void show();

/* main function */
int main()
{
	// declaration of variables //
	int ch, n;
	/* while loop */
	while(1)
	{
		// Choice Display //
		printf("\n----Queue Menu----");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Check Empty");
		printf("\n4. Display Queue");
		printf("\n5. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		
		// switch case // 
		switch(ch)
		{
			case 1:
				printf("\nEnter a Integer value : ");
				scanf("%d", &n);
				enqueue(n); break;
			case 2:
				dequeue();break;
			case 3:
				isEmpty();break;
			case 4:
				show();break;
			case 5:
				exit(0);break;
			default:
				printf("\nInvalid Choice! Try Again!");
		}
		// switch case ends here //

	}
	/* while loop ends here */
	return 0;
}
/* main function ends here */

/* enqueue() : adds element to queue*/
void enqueue(int n)
{
	if(f == -1 && r == -1)
	{
		f++;
		queue[++r] = n;
	} 
	else
	{
		if()
		{
			printf("\nqueue is full!");
		}	
		else
		{
			queue[++r] = n;
		}
	}
}
/* enqueue() function ends here */

/* dequeue() : deletes element from front end of queue*/
void dequeue()
{
	if(f == -1 && r == -1)
	{
		printf("\nQueue is Empty!");
	}
	else if(f == r)
	{
		f = -1;
		r = -1;
	}
	else
	{
		f++;
	}
}
/* dequeue ends here */

/* isEmpty() : check is the queue is empty or not */
void isEmpty()
{
	if(f == -1 && r == -1)
	{
		printf("\nQueue is Empty!");
	}
	else
	{
		printf("\nQueue is not Empty!");
	}
}
/* isEmpty func ends here */

/* show() : displays queue with front and rear pointers */
void show()
{
	int i;
	if(f == -1 && r == -1)
	{
		printf("\nQueue is Empty!");
	} 
	else
	{
		printf("\n------------");
		for(i = f; i <= r; i++)
		{
			if(i == f && i == r)
			{
				printf("\n%d <- front and rear", queue[i]);
			}
			else if(i == f)
			{
				printf("\n%d <- front", queue[i]);
			}
			else if(i == r)
			{
				printf("\n%d <- rear", queue[i]);
			}
			else
			{
				printf("\n%d", queue[i]);
			}
		}
		printf("\n------------");
	}
}
/* show function ends here */
