#include <stdio.h>
#include <stdlib.h>

void create();
void insert();
void delete();
void display();

struct node{
	int data;
	struct node *next;		
};
struct node *head, *newnode, *temp, *a, *nextnode, *prevnode;
int ch = 1, pos, c = 1;

void main(){
	int op;
	while (1){
		printf ("menu card...\n1. creation\n2. insertion\n3. deletion\n4. display\n5. exit\nenter your option : \n");
		scanf ("%d", &op);
		switch (op){
			case 1 : create(); break;
			case 2 : insert(); break;
			case 3 : delete(); break;
			case 4 : display(); break;
			case 5 : exit(0);
		}
	}
}

void create(){
	head = NULL;
	while (ch){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf ("enter data : ");
		scanf ("%d", &newnode->data);
		newnode -> next = NULL;
		if (head == NULL){
			head = newnode;
			temp = newnode;
		}
		else{
			temp -> next = newnode;
			temp = temp -> next;
		}
		printf ("want to continue?(0 / 1) : ");
		scanf ("%d", &ch);
	}
	temp = head;
	printf ("\nlist elements are : ");
	while (temp -> next != NULL){
		c++;
		printf ("\n%d", temp -> data);
		temp = temp -> next;
	}
	a = temp -> next;
	printf ("\n%d", temp -> data);
	printf ("\n\n");
}

void insert(){
	int i = 1;
	printf ("\n1. insertion at first\n2. insertion at middle\n3. insertion at end\nwhere do you want to insert? : ");
	scanf ("%d", &pos);
	newnode = (struct node *)malloc(sizeof(struct node));
	printf ("enter data : ");
	scanf ("%d", &newnode->data);
	temp = head;
	switch (pos){
		case 1 :
			newnode -> next = temp;
			head = newnode;
			c++;
			break;
			
		case 2 :
			printf ("\nenter position of data to be inserted : ");
			scanf ("%d", &ch);
			if (ch > c){
				printf ("enter valid position...");
			}
			else{
				while (i < ch-1){
				temp = temp -> next;
				i++;
				}
				newnode -> next = temp -> next;
				temp -> next = newnode;
				c++;
			}
			break;
			
		case 3 :
			newnode -> next = NULL;
			while (temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = newnode;
			c++;
			break;	
	}
	printf ("\ndata inserted successfully :)");
	printf ("\n\n");
}

void delete(){
	int i = 1;
	if (head == NULL){
		printf ("list is empty :(");
	}
	else{
		printf ("\n1. deletion at first\n2. deletion at middle\n3. deletion at end\nwhere do you want to delete? : ");
		scanf ("%d", &pos);
		temp = head;
		switch (pos){
			case 1 : 
				head = temp -> next;
				free (temp);
				break;
			
			case 2 :
				printf ("enter position of data to be deleted : ");
				scanf ("%d", &ch);
				while (i < ch-1){
					temp = temp -> next;
					i++;
				}
				nextnode = temp -> next;
				temp -> next = nextnode -> next;
				free (nextnode);
				break;
				
			case 3 : 
				while (temp -> next != NULL){
					prevnode = temp;
					temp = temp -> next;
				}
				prevnode -> next = NULL;
				free (temp);
				break;
		}
		printf ("\ndata deleted successfully :)");
	}
	printf ("\n\n");
}

void display(){
	if (head == NULL){
		printf ("list is empty :(");
	}
	else{
		printf ("\nlist elements are : ");
		temp = head;
		while (temp -> next != NULL){
			printf ("\n%d", temp -> data);
			temp = temp -> next;
		}
		a = temp -> next;
		printf ("\n%d", temp -> data);
		temp = head;
	}
	printf ("\n\n");
}
