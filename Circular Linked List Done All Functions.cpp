#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};

void display(struct node*);
void search(struct node*);
int count(struct node*);
void Insert_First(struct node**);
void insert_last(struct node**hptr);
void insert_between(struct node** head);
void Delete_between(struct node **);
void Delete_last(struct node **);
void Delete_first(struct node **);

int main()
{
	struct node* head = NULL;
	
	int choice,ret;
	while(1)
	{
		puts("***SINGLY LINEAR LINKED LIST");
		puts("1 : INSERT FIRST");
		puts("2 : INSERT LAST");
		puts("3 : INSERT BETWEEN");
		puts("4 : DELETE FIRST");
		puts("5 : DELETE LAST");
		puts("6 : DELETE BETWEEN");
		puts("7 : COUNT");
		puts("8 : DISPLAY");
		puts("9 : SEARCH");
		puts("10 :EXIT");
		
		printf("ENTER YOUR CHOICE = ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				Insert_First(&head);
				break;
				
			case 2:
			    insert_last(&head);
			    break;
			
			case 3:
			     insert_between(&head);
				 break;
				 
		    case 4:
			      Delete_first(&head);
			    break;
				  	
		      
				   case 5:
				         Delete_last( &head);
				   break;
				   
				   case 6:
				         Delete_between(&head);
				   break;
				   
				   case 7:
				   	ret=count(head);
				   	printf("\nTOTAL NODES = %d\n",ret);
				   break;
				   
				   case 8:
				   	display(head);
				   break;
				   
				   case 9:
				   	search(head);
				   break;
				   
				   case 10:
				   {
				      printf("PROGRAM CLOSED");
				      return 0;
				    } 
				   break;
				   
				   default:
				   	{
				   		puts("\n INVALID CHOICE \n");
					   }
				   	
		}
	}
return 0;	
}

void display(struct node* head)
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		while(head->next!=temp)                //head->nxt != temp;
		{
			printf("%d->",head->data);          //head->data
			head=head->next;                  
		}
		printf("%d\n",head->data);
	}
	return;
}

int count(struct node* head)
{
	struct node *temp = head;
	int cnt=0;
	
	if(temp!=NULL)
	{
		while(head->next!=temp)
		{
			cnt++;
			head=head->next;
		}
		cnt++;
	}
	return cnt;
}

void search(struct node* head)
{
	struct node *temp=head;
	int value=0,flag=0;
	
	printf("ENTER VALUE TO BE SEARCH= ");
	scanf("%d",&value);
	
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	
	else
	{
		while(temp->next!=head)
		{
			if(value==temp->data)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(value==temp->data)
		{
			flag=1;
		}
		
		if(flag==0)
		{
			printf("VALUE NOT FOUND\n");
		}
		else
		{
			printf("VALUE FOUND\n");
		}
	}
	return;
}

void Insert_First(struct node** hPtr)
{
	struct node* temp = *hPtr;//head
	struct node* ptr = NULL;
	int value = 0;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	
	printf("Enter Value = ");
	scanf("%d",&value);
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(*hPtr==NULL) //List is Empty
	{
		*hPtr = ptr;
		ptr->next = *hPtr;
	}
	else
	{
		while(temp->next!=*hPtr)
		{
			temp = temp->next;
		}
		ptr->next = *hPtr;
		*hPtr = ptr;
		temp->next = *hPtr;
	}
	return;
}

void insert_last(struct node **hptr)
{
	struct node* temp = *hptr;//head
	struct node* ptr = NULL;
	int value = 0;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}
	
	printf("Enter Value = ");
	scanf("%d",&value);
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(*hptr==NULL)
	{                                  //CALL INSERT FIRST
	   *hptr = ptr;
	   ptr->next=*hptr;	
	}
	
	else
	{
		while(temp->next!=*hptr)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
			temp->next=*hptr;
	}
	return;
}

void insert_between(struct node** hptr)
{
	struct node *temp= *hptr;
	struct node* ptr = NULL;
	struct node *temp1= *hptr;
	
	int value,pos=0;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("Memory not allocated\n");
		return;
	}

	printf("ENTER POSITION= ");
	scanf("%d",&pos);
	
	if(pos<1 || pos>count(*hptr)+1)
	{
		printf("%d INVALID POSITION\n",pos);
		return;
	}
		
	printf("Enter Value = ");
	scanf("%d",&value);
	
	ptr->data = value;
	ptr->next = NULL;
	
	if(pos==1)
	{
		if(*hptr==NULL)
		{
		 *hptr=ptr;
		 ptr->next=*hptr;
		}
		
		else
		{
			ptr->next=*hptr;
			*hptr=ptr;
		}
			while(temp->next!=temp1)
			{
				temp=temp->next;
			}
			temp->next=*hptr;
	}
	
	else if(pos==count(*hptr)+1)
	{
		while(temp->next!=*hptr)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=*hptr;
	}
	
	else
	{
		while(pos>2)
		{
			temp=temp->next;
			pos--;
		}
		ptr->next=temp->next;
		temp->next=ptr;
	}
	
		
	return;
}

void Delete_between(struct node **hptr)
{
	struct node *temp=*hptr;
	struct node *temp1=*hptr;
	int pos=0;
	
	printf("ENTER POSITION= ");
	scanf("%d",&pos);
	if(pos<1 || pos>count(*hptr))
	{
		printf("INVALID POSITION");
		return;
	}
	
	if (pos==1)
	{
		if(*hptr==NULL)
		{
			printf("LIST IS EMPTY\n");
		}
		else if((*hptr)->next==*hptr)
		{
			free(temp);
			*hptr=NULL;
		}
		else
		{
			while(temp->next!=*hptr)
			{
				temp=temp->next;
			}
			*hptr=temp1->next;
			free(temp1);
			temp->next=*hptr;
		}
	}
	
	else if(pos==count(*hptr))
	{
		while(temp->next->next!=*hptr)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=*hptr;
	}
	else
      {
      	while(pos>2)
      	{
      		temp=temp->next;
      		pos--;
		 }
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
	}
	return;
}

void Delete_last(struct node **hptr)
{
	struct node *temp=*hptr;
   
  if(*hptr==NULL)
		{
			printf("LIST IS EMPTY\n");
		}
		else if((*hptr)->next==*hptr)
		{
			free(temp);
			*hptr=NULL;
		}
		else
		{
			while(temp->next->next!=*hptr)
			{
				temp=temp->next;
			}
		
			free(temp->next);
			temp->next=*hptr;
		}
		return;
}

void Delete_first(struct node **hptr)
{
	struct node *temp=*hptr;
    struct node *temp1=*hptr;
  if(*hptr==NULL)
		{
			printf("LIST IS EMPTY\n");
		}
		else if((*hptr)->next==*hptr)
		{
			free(temp);
			*hptr=NULL;
		}
		else
		{
			while(temp->next!=*hptr)
			{
				temp=temp->next;
			}
			*hptr=temp1->next;
			free(temp1);
			temp->next=*hptr;
		}
    
return;
}






















