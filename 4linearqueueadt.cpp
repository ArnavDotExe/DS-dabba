#include <stdio.h>
#include <conio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert();
int delete_element();
int peek();
void display();
int main()
{
 int option, val;
 
 do
 {
 printf("\n1.Insert an element");
 printf("\n2.Delete an element");
 printf("\n3.Peek");
 printf("\n4.Display the queue");
 printf("\n5.EXIT");
 printf("\nEnter your option : ");
 scanf("%d",&option);
 switch(option)
 {
 case 1:
 insert();
 printf("-------------------------------------------------\n");
 display();printf("\n");
 printf("-------------------------------------------------\n");
 break;
 case 2:
 val = delete_element();
 if (val != -1)
 printf("\nThe number deleted is : %d",val);
 break;
 case 3:
 val = peek();
 if (val != -1)
 printf("\nThe first value in queue is : %d",val);
 break;
 case 4:
 printf("-------------------------------------------------\n");
 display();printf("\n");
 printf("-------------------------------------------------\n");
 break;
 } 
 }while(option != 5);
 
 getch();
 return 0;
}
void insert()
{
 int num;
 printf("\nEnter the number to be inserted in the queue : ");
 scanf("%d",&num);
 if(rear == MAX-1)
 {
 printf("\nOVERFLOW");
 return;
 }
 else if(front == -1 && rear == -1)
 {
 front = rear = 0; 
 }
 else
 {
rear++;
 } 
 queue[rear] = num;
 
}
int delete_element()
{
 int val;
 if(front == -1 || front>rear)
 {
 printf("\nUNDERFLOW");
 return -1;
 }
 else
 {
 val = queue[front];
 front++;
 if(front > rear)
 front = rear = -1;
 return val;
 
 }
}
int peek() 
{
 if(front==-1 || front>rear)
 {
 printf("\nQUEUE IS EMPTY");
 return -1;
 }
 else
 {
 return queue[front];
 
 } 
}
void display()
{
 int i;
 printf("\n");
 if(front == -1 || front > rear)
 printf("\nQUEUE IS EMPTY");
 else
 {
 for(i = front;i <= rear;i++)
 printf("%d\t",queue[i]);
 }
}
