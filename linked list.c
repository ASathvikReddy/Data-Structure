#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;
NODE *Head=NULL;

void insert_head(int data)
{
	NODE *NN;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		NN->add=Head;
		Head=NN;
	}
}

int delete_head()
{
	int val;
	NODE *NN;
	if(Head==NULL)
	{
		return -1;
	}
	/*else if (Head->add==NULL)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}*/
	else
	{
		val=Head->data;
		NN=Head->add;
		Head->add=NULL;
		Head=NN;
		return val;
		/*
		or
		Head=Head->add;
		*/
	}
}

void insert_end(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		temp=Head;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=NN;
	}
}

/*void delete_end()
{
	NODE *temp;
	temp=Head;
	if(Head==NULL)
	{
		printf("\nNO NODES TO BE DELETED\n");
	}
	else if(temp->add==NULL)
	{
		Head=NULL;
	}
	else
	{
		NODE *temp2;
		while(temp->add!=NULL)
		{
			temp2=temp->add;
			if(temp2->add==NULL)
			{
				break;
			}
			temp=temp->add;
		}
		temp->add=NULL;
	}
}*/

int delete_end()
{
	//3
	int val;
	NODE *temp;
	if(Head==NULL)
	{
		return -1;
	}
	else if (Head->add==NULL)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		temp=Head;
		while(temp->add->add)
		{
			temp=temp->add;
		}
		//printf("%d",temp->data);-->to know that temp is maintained at last but one node....
		val=temp->add->data;
		temp->add=NULL;
		return val;
	}
}

void display()
{
	NODE *temp;
	temp=Head;
	if(Head==NULL)
	{
		printf("\nNO NODES TO DISPLAY\n");
	}
	else
	{
		temp=Head;
		while(temp!=NULL)
		{
			//printf("%d %d %d\n",temp,temp->data,temp->add);
			printf("%d ",temp->data);
			temp=temp->add;
		}
		printf("\n");
	}
}

void main()
{
	int ch,data;
	while (1)
	{
		printf("\n1.insert_end\n2.delete_end\n3.insert at head\n4.delete at head\n5.display\n6.exit\n");
		scanf("%d",&ch);
		if (ch==1)
		{
			//insert data
			scanf("%d",&data);
			insert_end(data);
		}
		else if (ch==2)
		{
			// delete data
			data=delete_end();
			if(data==-1)
			{
				printf("NO NODES TO BE DELETED\n");
			}
			else
			{
				printf("\n %d is deleted\n",data);
			}
		}
		else if(ch==3)
		{
			//insert at head;
			scanf("%d",&data);
			insert_head(data);
		}
		else if (ch==4)
		{
			//delete at head;
			delete_head();
			if(data==-1)
			{
				printf("NO NODES TO BE DELEATED");
			}
			else
			{
				printf("\n %d is DELETED\n",data);
			}
		}
		else if (ch==5)
		{
			//display data;
			display();
		}
		else
		{
			break;
		}
	}
}

