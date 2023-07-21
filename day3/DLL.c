#include<stdio.h>
#include<stdlib.h>

void creation();
void insertion();
void deletion();
void display();

struct node{
	int data;
	struct node *head, *prev, *next;
};
int op = 1, ch = 1, i = 1, pos, c = 0;
struct node *head, *newnode, *tail, *temp;

void main(){
	while (1){
		printf ("***MENU CARD***\n1. Creation\n2. Insertion\n3. Deletion\n4. Displayfication\n5. Exit\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch){
			case 1 :
				creation();
				break;
			case 2 :
				insertion();
				break;
			case 3 :
				deletion();
				break;
			case 4 : 
				display();
				break;
			case 5 :
				exit(0);
			default :
				printf ("enter correct choice...");
				break;
		}
	}
}

void creation(){
	head = 0;
	while (op){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf ("Enter data : ");
		scanf ("%d", &newnode -> data);
		newnode -> next = newnode -> prev = 0;
		if (head == 0){
			head = tail = newnode;
		}
		else{
			tail -> next = newnode;
			newnode -> prev = tail;
			tail = newnode;
		}
		c++;
		printf ("wanna continue? (0 / 1) : ");
		scanf ("%d", &op);
	}
	printf ("\n");
}

void insertion(){
	printf ("\n1. Insertion at first\n2. Insertion at middle\n3. Insertion at end\nEnter your option : ");
	scanf("%d", &op);
	if (op == 1 || op == 2 || op == 3){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf ("Enter data : ");
		scanf ("%d", &newnode -> data);
		switch (op){
			case 1 :
				InsertFirst();
				break;
			case 2 :
				printf ("Enter position of data to be inserted : ");
				scanf ("%d", &pos);
				if (pos < 0 || pos > c+1){
					printf ("\nInvalid position...:(");
				    printf("\n\n"); 
					return;
				}
				else{
					InsertMiddle(pos);
					break;
				}
			case 3 : 
				InsertEnd();
				break;
		}
		c++;
		printf ("\nData inserted successfully :)");
		printf ("\n\n");
	} 
	else {
		printf ("\nEnter correct option...");
		printf ("\n\n");
	}
}

void InsertFirst(){
	newnode -> prev = 0;
	head -> prev = newnode;
	newnode -> next = head;
	head = newnode;
}

void InsertMiddle(int pos){
	if (pos == 1){
		InsertFirst();
	}
	else if (pos == c+1){
		InsertEnd();
	}
	else{
		temp = head;
		while (i < pos-1){
			temp = temp -> next;
			i++;
		}
		newnode -> next = temp -> next;
		newnode -> prev = temp;
		(temp -> next) -> prev = newnode;
		temp -> next = newnode;
	}
}

void InsertEnd(){
	newnode -> next = 0;
	tail -> next = newnode;
	newnode -> prev = tail;
	tail = newnode;
}

void deletion(){
	printf ("\n1. Deletion at first\n2. Deletion at middle\n3. Deletion at end\nEnter your option : ");
	scanf("%d", &op);
	if (op == 1 || op == 2 || op == 3){
		switch(op){
			case 1 :
				DeleteFirst();
				break;
			case 2 :
				printf ("Enter position of data to be deleted : ");
				scanf ("%d", &pos);
				if (pos < 0 || pos > c){
					printf ("\nInvalid position...:(");
				    printf("\n\n");
					return; 
				}
				else {
					DeleteMiddle(pos);
					break;	
				}
			case 3 :
				DeleteEnd();
				break;		
		}
		c--;
		printf ("\nData deleted successfully :)");
		printf ("\n\n");
	}
	else {
		printf ("\nEnter correct option...");
		printf ("\n\n");
	}
}

void DeleteFirst(){
	if (head == 0){
		printf ("list is empty...:(");
	}
	else {
		temp = head;
		head = temp -> next;
		head -> prev = 0;
		free (temp);
	}
}

void DeleteMiddle(int pos){
	if (pos == 1){
		DeleteFirst();
	}
	else if (pos == c){
		DeleteEnd();
	}
	else {
		i = 1;
		temp = head;
		while (i < pos){
			temp = temp -> next;
			i++;
		}
		(temp -> prev) -> next = temp -> next;
		(temp -> next) -> prev = temp -> prev;
		temp -> prev = temp -> next = 0;
		free (temp);
	}
}

void DeleteEnd(){
	if (tail == 0){
		printf ("list is empty...:(");
	}
	else {
		temp = tail;
		tail = tail -> prev;
		tail -> next = 0;
		free (temp);
	}
}

void display(){
	temp = head;
	if (head == 0){
		printf ("\nlist is empty...:(");
	}
	else{
		printf ("\nlist elements are : ");
		while (temp != 0){
			printf ("\n%d", temp -> data);
			temp = temp -> next;
		}
	}
	printf ("\n\n");
}
