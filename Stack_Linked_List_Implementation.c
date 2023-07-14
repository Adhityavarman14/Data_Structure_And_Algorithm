#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node{
	int data;
	struct node *next;
};
struct node *head, *newnode;

int  main(){
	int op = 0;
	
	while(op != 4){
		printf("\nenter number of which stack operation to perform");
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nenter your choice : ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exited Successfully");
				return 0;
			default:
				printf("choose number between 1-4 only");
		}
	}
}
//push the data into stack
void push(){
	int data;
	newnode = (struct node*)malloc(sizeof(struct node));
	
	if(newnode == NULL){
		printf("can't insert");
	}
	
	else{
		printf("enter the data to be inserted into stack : ");
		scanf("%d", &data);
		
		if(head == NULL){
			newnode->data = data;
			newnode->next = NULL;
			head = newnode;
		}
		else{
			newnode->data = data;
			newnode->next = head;
			head = newnode;
		}
	}
	
	printf("data is pushed into stack");
}
//pop the element from top of the stack
void pop(){
	if(head == NULL){
		printf("Underflow");
	}
	else{
		printf("popping data %d", head->data);
		newnode = head;
		head = head->next;
		free(newnode);
	}
	printf("data popped");
}
//display the stack elements
void display(){
	printf("\n");
	if(head == NULL){
		printf("stack is empty");
	}
	else{
		newnode = head;
		while(newnode!=NULL){
			printf("%d ", newnode->data);
			newnode = newnode->next;
		}
	}
}
