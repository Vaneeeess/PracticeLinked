#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
}list;


list *createNode(int data)
{
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void printlist(list *head)
{
	while(head != NULL)
	{
		printf("%d\t", head->data);
		head = head->next;
	}
}

list *insertAtBeginning(list *head, int num)
{
	list *newNode = createNode(num);
	newNode->next = head;
	return newNode;
}

list *insertAtEnd(list *head, int num)
{
	list *newNode = createNode(num);
	
	if(head == NULL)
	{
		head = newNode;
		return head;
	}
	
	list *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

list *deleteNode(list *head, int num)
{
	if(head == NULL)
	{
		return NULL;
	}
	if(head->data == num)
	{
		list *temp = head->next;
		free(head);
		return temp;
	}
	list *curr = head;
	if(curr->next != NULL && curr->next->data !=num)
	{
		curr = curr->next;
	}
	if(curr->next != NULL)
	{
		list *temp = curr->next;
		curr->next = curr->next->next;
		free(temp);
	}
	
	return head;
}

list *reverselist(list *head)
{
	list *curr = head;
	list *next = NULL;
	list *prev = NULL;
	
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

int searchlist(list *head, int num)
{
	int foundya = 0;
	while(head != NULL)
	{
		if(head->data == num)
		{
			printf("Found!\n");
			foundya = 1;
		}
		head = head->next;
	}
	if(foundya == 0)
	{
		printf("Not Found!\n");
	}
}
