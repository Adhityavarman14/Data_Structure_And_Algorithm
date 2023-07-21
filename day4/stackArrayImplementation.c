#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void push(int);
void display();
void pop();

int stack[MAX] ;
int top = -1;
	
int main(){
	push(23);
	push(22);
	pop();
	push(222);
	pop();
	push(2);
	push(787);
	display();
}

void push(int data){

	if(top == MAX){
		printf("stack overflow");
	}
	stack[++top] = data;
}

void pop(){
	if (top == -1){
		printf("%d","Underflow");
	}
	else{
		top = top-1;
	}
}

void display(){
	for(int i = top ;i >= 0;i--){
		printf("%d ", stack[i]);
	}
}
