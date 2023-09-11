//Queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
	int info; //to store value
	struct node *next; //to store address
}; 

struct node *getnode()
{
	
	return ((struct node*)malloc(sizeof(struct node))); //returns memory address allocated
};

void freenode(struct node *p)
{
	free(p); //deletes node
}

struct node *list=NULL;

void enqueue();
void dequeue();
void display();
void search();

int main()
{
	while(1)
	{
		int choice;
		printf("\nStack ADT functions");
		printf("\n1.Enqueue	\n2.Dequeue 	\n3.Display		\n4.Search		\n5.Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: enqueue();
				break;
			
			case 2: dequeue();
				break;
		
			case 3: display();
				break;
		
			case 4: search();
				break;
		
			case 5: return 0;
			
			default: printf("Invalid input");	
				 break;	
		}
	}
		
}

void enqueue(){
    int n;
    printf("\nEnter element to be inserted : ");
    scanf("%d", &n);
    struct node *newnode, *temp;
    newnode = getnode();
    newnode->info = n;
    temp=list;
    newnode->next = NULL;
    if (list == NULL)
    {
        list = newnode;
    } else {
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;        
    }
    
}

void dequeue(){
    if (list == NULL)
    {
        printf("Queue is empty\n");
    } else {
        struct node *temp;
        temp= list;
        list = temp->next;
        freenode(temp);

    }    
}

void display()
{
	if(list==NULL) //checks if stack is empty
	{
		printf("\nQueue is empty");
	}		
	else
	{
		struct node *newnode;
		newnode=getnode();
		newnode=list;
		while(newnode!=NULL)
		{
			printf("\n%d", newnode->info); //prints info 
			newnode=newnode->next; //changes the newnode pointer to next node
		}
	}
}

void search(){
    if (list == NULL)
    {
        printf("Queue is empty\n");
    } else {
        struct node *temp;
        int count=0, n;
        temp = list;
        printf("\nEnter element to be searched : ");
        scanf("%d", &n);
        while(temp != NULL){
            if(n == temp->info){
                count++;
                break;
            }
            temp = temp->next;
        }
        if (count>0)
        {
            printf("Element was found\n");
        } else {
            printf("Element is not in the Queue\n");
        }
         
    }    
}