#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	
	int data;
	struct node *next;
} list;

list *createNode(int data) {
	
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

list *insertAtPos(list *head, int newdata, int pos) {
	
	list *newNode = createNode(newdata);
	
	if(head == NULL) {
		head = newNode;
		return head;
	}
	
	if(pos == 1) {
		newNode->next = head;
		head = newNode;
		return head;
	}
	
	list *curr = head;
	int count = 1;
	while(curr != NULL && count < pos - 1) {
		curr = curr->next;
		count++;
	}
	
	if(curr == NULL) {
		printf("Invalid position!\n");
		return head;
	}
	
	newNode->next = curr->next;
	curr->next = newNode;
	
	return head;
}

list *deletefirst(list *head) {
	
	list *temp = head;
	head = head->next;
	free(temp);
	
	return head;
}

list *deleteEnd(list *head) {
	
	list *end = head;
	list *prev = NULL;
	
	while(end->next) {
		prev = end;
		end = end->next;
	}
	
	prev->next = NULL;
	free(end);
	
	return head;
}

list *deleteN(list *head, int position) {
	
	
	if(head == NULL) {
		printf("List is Empty!");
		return head;
	}
	
	list *temp = head;
	list *prev = NULL;
	
	for(int i = 1; i < position && temp != NULL; i++) {
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL) {
		printf("Cannot be deleted!\n");
		return head;
	}
	
	if(prev == NULL) {
		head = temp->next;
	} else {
		prev->next = temp->next;
	}
	
	free(temp);
	
	return head;
}
void printlist(list *head) {
	
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
int main() {
	
	list *head = NULL;
	char choice, choice2;
	int data;
	int newdata, pos;
	do {
		
		printf("Enter node you want to add: ");
		scanf("%d", &data);
		
		list *newNode = createNode(data);
		
		if(head == NULL) {
			head = newNode;
		} else {
			list *lastnode = head;
	       	while(lastnode->next != NULL) {
			lastnode = lastnode->next;
		}
		lastnode->next = newNode;
		}
		printf("Do you want to add another node? (Y/N): ");
		scanf(" %c", &choice);
	}while(choice == 'y' || choice == 'Y');
	
	printlist(head);
	
	printf("Do you want to add new data with position? (Y/N): ");
	scanf(" %c", &choice2);
	
	if(choice2 == 'y' || choice == 'Y') {
		printf("Enter new data: ");
		scanf("%d", &newdata);
		printf("At what position?: ");
		scanf("%d", &pos);
		head = insertAtPos(head, newdata, pos);
		printlist(head);
	}else {
		printf("Goodbye.!\n");
	}
	
	head = deletefirst(head);
	
	printlist(head);
	
	head = deleteEnd(head);
	
	printlist(head);
	
	int position;
	printf("Enter position you want to delete: ");
	scanf("%d", &position);
	head = deleteN(head, position);
	
	printlist(head);
	return 0;
}
