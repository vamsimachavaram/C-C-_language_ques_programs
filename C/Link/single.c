#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct sll{
	int num;
	char name[20];
	struct sll *next;
}SLL; 



int  Add_node(SLL **);
int delete_node(SLL **);
int add_middle(SLL **);
int print_data(SLL **);

SLL *headptr = NULL;
int main()
{
	int number;
	printf("\n #############################################################################################################\n \
		1.Add a node\n \
	    	2.delete a node\n \
		3.add at middle node \n  \
		4.add at beganning \n    \
		5.add at end \n \
	       	6.delete all nodes\n     \
	       	7.Print the list \n      \
	       	8.Search a node  \n      \
		9.Back to Home screen\n #############################################################################################################\n");
		while(1)
		{
			printf("please select the option : ");
			scanf("%d",&number);
			switch(number)
			{
				case 1:
					if( Add_node(&headptr) == -1)
					{
						printf("Fail to Add a node\n");
					}
					break;
				case 2:
					if(delete_node(&headptr) == -1)
					{
						printf("Fail to delete node\n");
					}
					break;	
				case 3:
					if(add_middle(&headptr)== -1)
					{
						printf("Fail to add_middle node\n");
					}
					break;
				case 4:
					if(add_begin_node(&headptr)== -1)
					{
						printf("Fail to add at beginning\n");
					}
					break;
				case 5:
					if(add_node(&headptr)== -1)
					{
						printf("Fail to add at beginning\n");
					}
					break;
				case 6:
					if(delete_allnode(&headptr)== -1)
					{
						printf("Fail to add at beginning\n");
					}
					break;
				case 7:
					if(print_data(&headptr) == -1 )
					{
					
						printf("Fail to print node\n");	
					}
					break;
				case 8:
				case 9:
					main();
				default:
					printf("Invalid option please try with valid option from 1 to 9\n");
					break;
			}	
		}
	
	
	
	
	
	return 0;
}
/**********************************************************************************************
 * ********************************************************************************************/

int Add_node(SLL **ptr)
{
	SLL *temp,*temp1=*ptr;
	temp=(SLL *)malloc(sizeof(SLL));
	printf("enter the data   : ");
	scanf("%d",&temp->num);
	if(*ptr == NULL)
	{
		temp->next = *ptr;
		headptr = temp;
	return 0;
	}
	else
	{
		while(temp1->next != NULL)
			temp1 = temp1->next;

		temp1->next = temp;
		temp->next = NULL;
	return 0;
	}
return -1;
}
/*******************************************************************************************
 * ******************************************************************************************/

int delete_node(SLL **ptr)
{
	SLL *temp1,*temp=*ptr;
	int number;
	printf("Enter number to delete :");
	scanf("%d",&number);
	while(temp->next != NULL)
	{

		if(temp->num == number)
		{
			if(temp == headptr)  
			{
				headptr = temp->next;
				free(temp);
				return 0;
			}
			else
			{
				temp1->next = temp->next;
			        free(temp);
				return 0;	
			}
		}
		temp1=temp;
		temp=temp->next;  
	}
	
return -1;
}
/*************************************************************************************************
 * **************  ADD MIDDLE
 * ***********************************************************************************************/
int add_middle(SLL **ptr)
{

	SLL *temp1,*temp=*ptr;
	int pos_num;
	SLL *number = (SLL *)(malloc(sizeof(SLL)));
	printf("Enter the position number :");
	scanf("%d",&pos_num);
	printf("enter the enumber to add at middle :");
	scanf("%d",&number->num);
	while(temp)
	{
		if(temp->num == pos_num)
		{
			if((headptr == temp))
			{
		       		if(temp->num == number->num)
				{
					printf("the number is already available\n");
					free(number);
					number=NULL;
					return -1;
				}
		       		else if(temp->num > number->num)
		       		{
		       			number->next = temp;
		       			headptr = number;
					return 0;
		       		}
				else
				{
				}
			}
			else if(temp->num != number->num)
			{
				if(temp->num > number->num)
				{
					temp1->next = number;
		   			number->next = temp;
					return 0;
				}
			}
			else
			{
				printf("the number is already available\n");
				free(number);
				number=NULL;	
				return -1;
			}
		}
	temp1 = temp;
	temp = temp->next;
	}
return -1;
}
/***************************************************************************************************
 * *************************************************************************************************/
int print_data(SLL **ptr)
{
	SLL *temp = *ptr;
	while(temp->next != NULL)
	{

		printf("%d  \n",temp->num);
	        temp = temp->next; 
	}
	printf("%d  \n",temp->num);
return 0;	
}

