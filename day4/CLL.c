#include<stdio.h>
#include<stdlib.h>

void create();
void display();

struct node{
	int data;
	struct node *next;
};
struct node *newnode, *tail, *temp, *prevnode, *nextnode;
int ch, op, c = 0, pos;

void main(){
	while (1){
		printf ("1. Create\n2. Insertion\n3. Deletion\n4. Display\n5. Exit\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch){
			case 1 :
				create();
				break;
			case 2 :
				insertion();
				break;
			case 3 :
				if (tail == NULL){
					printf ("List is empty");
				} else {
					deletion();
					break;	
				}
			case 4 :
				display();
				break;
			case 5 :
				exit(0);
			default :
				printf ("Enter correct choice...");
				break;
		}
	}
}

void create(){
	tail = 0;
	while (ch){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf ("Enter data : ");
		scanf("%d", &newnode -> data);
		if (tail == 0){
			tail = newnode;
			newnode -> next = tail;
		} else {
			newnode -> next = tail -> next;
			tail -> next = newnode;
			tail = newnode;
		}
		c++;
		printf ("Wanna continue (0/1)? : ");
		scanf("%d", &ch);
	}
	printf ("\n");
}

void insertion(){
	printf ("\n1. Insert at first\n2. Insert at middle\n3. Insert at end\nEnter your choice : ");
	scanf ("%d", &op);
	if (op == 1 || op == 2 || op == 3){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf ("Enter data : ");
		scanf ("%d", &newnode -> data);
		
		switch (op){
			case 1 : 
				insert_beg();
				break;
			case 2 :
				printf ("Enter position of data to be inserted : ");
				scanf ("%d", &pos);
				if (pos == 1){
					insert_beg();
					break;
				} else if (pos < 1 && pos > c){
					printf ("Invalid position...");
				} else {
					insert_middle(pos);
					break;
				}
			case 3 :
				insert_end();
				break;
		}
		c++;
		printf ("Data inserted successfully...");
		printf ("\n\n");
	} else {
		printf ("Enter valid choice...");
		printf ("\n\n");
	}
}

void insert_beg(){
	newnode -> next = tail -> next;
	tail -> next = newnode;
}

void insert_middle(int pos){
	int i = 1;
	temp = tail -> next;
	while (i < pos-1){
		temp = temp -> next;
		i++;
	}
	newnode -> next = temp -> next;
	temp -> next = newnode;
}

void insert_end(){
	newnode -> next = tail -> next;
	tail -> next = newnode;
	tail = newnode;
}

void deletion(){
	printf ("\n1. delete at first\n2. delete at middle\n3. delete at end\nEnter your choice : ");
	scanf ("%d", &op);
	if (op == 1 || op == 2 || op == 3){
		switch (op){
			case 1 :
				delete_first();
				break;
			case 2 :
				printf ("Enter position of data to be deleted : ");
				scanf("%d", &pos);
				if (pos < 0 || pos > c){
					printf ("Invalid position...");
					break;
				}else if (pos == 1){
					delete_first();
					break;
				} else if (pos == c){
					delete_end();
					break;
				} else {
					delete_middle(pos);
					break;	
				}
			case 3 :
				delete_end();
				break;
		}
		c--;
		printf ("Data deleted successfully...");
		printf ("\n\n");
	}else {
		printf ("Enter valid choice...");
		printf ("\n\n");
	}
}

void delete_first(){
	temp = tail -> next;
	tail -> next = temp -> next;
	free (temp);
}

void delete_middle(int pos){
	int i = 1;
	temp = tail -> next;
	while (i < pos-1){
		temp = temp -> next;
		i++;
	}
	nextnode = temp -> next;
	temp -> next = nextnode -> next;
	free(nextnode);
}

void delete_end(){
	temp = tail -> next;
	while (temp -> next != tail -> next){
		prevnode = temp;
		temp = temp -> next;
	}
	prevnode -> next = tail -> next;
	tail = prevnode;
	free(temp);
}

void display(){
	if (tail == NULL){
		printf ("List is empty...");
	} else {
		temp = tail -> next;
		printf ("List contents are : \n");
		while (temp -> next != tail -> next){
			printf ("%d\n", temp -> data);
			temp = temp -> next;
		}
		printf ("%d", temp -> data);
	}
	printf ("\n\n");
}
