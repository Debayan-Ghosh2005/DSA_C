#include<stdio.h> 
#include<stdlib.h> 
#define maxsize 2 
void insert(); 
void delete(); 
void display(); 
int front = -1, rear = -1; 
int queue[maxsize]; 
void main () 
{ 
 int choice; 
 while(1)  
{ 
printf("\nMenu:\n");
printf("1. Insert\n");
printf("2. Delet\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
 switch(choice) 
 { 
 case 1: 
 insert(); 
 break; 
 case 2: 
 delete(); 
 break; 
 case 3: 
 display(); 
 break; 
 case 4: 
 printf("Exit Point");
 exit(0); 
 break; 
 default: 
 printf("Invalid choice. Please try again.\n"); 
 } 
 } 
} 
void insert() 
{ 
 char item; 
 printf("Enter the element "); 
 scanf(" %c",&item); 
 if(item >= 'A' && item <= 'Z' ||item >= 'a' && item <= 'z')
 {
 
 if(rear == maxsize-1) 
 { 
 printf("overflow"); 
 return; 
 } 
 if(front == -1 && rear == -1) 
 { 
 front = 0; 
 rear = 0; 
 } 
 else 
 { 
 rear = rear+1; 
 } 
 queue[rear] = item; 
 printf("Value inserted "); 
 
}
else
	{
		printf("Wrong input\n");
		fflush(stdin);
	}
 }

void delete() 
{ 
 int item; 
 if (front == -1 || front > rear) 
 { 
 printf("underflow");
return;
 }
 else 
 { 
 item = queue[front]; 
 if(front == rear) 
 { 
 front = -1; 
 rear = -1 ; 
 } 
 else 
 { 
 front = front + 1; 
 } 
 printf("value deleted "); 
 }  
} 
 
void display() 
{ 
 int i; 
 if(rear == -1) 
 { 
 printf("Empty queue\n"); 
 } 
 else 
 { printf("printing values .....\n"); 
 for(i=front;i<=rear;i++) 
 { 
 printf(" %c\n",queue[i]);
}
}
} 