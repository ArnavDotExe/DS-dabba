#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<malloc.h>
 
struct node
{
int data;
struct node *next;
};
 
struct node *create(struct node *); 
struct node *start= NULL;
struct node *insert_beg(struct node *); 
struct node *insert_end(struct node *); 
struct node *delete_element(struct node *); 
struct node *display(struct node *);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
 
int main(int argc, char *argv[])
 
{
 
int option; 
do
{
 
printf("\n**MAIN MENU**"); 
printf("\n1.Create the list");
 
printf("\n2.Add the node at the beginning"); 
printf("\n3.Add the node at the end"); 
printf("\n4.Delete the element"); 
printf("\n5.Delete the element at beginning."); 
printf("\n6.Delete the element at end"); 
printf("\n7.Display the list");
printf("\n8.Exit");
printf("\nEnter your option:"); scanf("%d",&option); 
switch(option)
 
{
 
case 1:
start=create(start);
printf("CIRCULAR LINKED LIST CREATED\n");
break; 
 
case 2:
start=insert_beg(start); 
break;
 
case 3:
start=insert_end(start); 
break;
 
case 4:
start=delete_element(start); 
break;
 
case 5:
start=delete_beg(start);
break; 
 
case 6:
start=delete_end(start); 
break;
 
case 7:
start=display(start); 
printf("\n"); 
break;
 
case 8:
exit(0); 
break;
 
default:
printf("invalid choice\n"); break;
 
}
 
}while(option!=8); 
 
getch();
return 0;
 
}
 
struct node *create(struct node *start)
{
struct node *new_node,*ptr; int num;
printf("\nEnter -1 to end\n"); 
printf("Enter the data:"); 
scanf("%d",&num); 
while(num!=-1)
{
new_node=(struct node*)malloc(sizeof(struct node)); 
new_node->data=num;
if(start==NULL)
{
new_node->next=new_node; 
start=new_node;
}
else
{
ptr=start;
 
while(ptr->next!=start) 
ptr=ptr->next;
 
ptr->next=new_node; 
new_node->next=start;
}
printf("\nEnter the data:"); 
scanf("%d",&num);
}
return start;
}
 
struct node *display(struct node *start)
{
struct node *ptr; 
if(start==NULL)
{
printf("LIST IS EMPTY\n");
}
else
{
ptr=start;
while(ptr->next != start)
{
printf("\t%d",ptr->data); ptr = ptr->next;
}
printf("\t%d",ptr->data);
}
return start;
}
 
struct node *insert_beg(struct node *start)
{
struct node *new_node,*ptr; 
int num;
printf("Enter the data:"); 
scanf("%d",&num);
new_node=(struct node *)malloc(sizeof(struct node)); 
new_node->data=num;
 
ptr=start;
while(ptr->next!=start) 
ptr=ptr->next;
 
ptr->next=new_node; 
new_node->next=start; 
start=new_node; 
return start;
}
 
struct node *insert_end(struct node *start)
{
struct node *ptr;
struct node *new_node; 
int num;
printf("Enter the data value for the node:"); 
scanf("%d",&num);
new_node=(struct node *)malloc(sizeof(struct node)); 
new_node->data=num;
 
ptr=start;
while(ptr->next!=start) 
ptr=ptr->next;
 
ptr->next=new_node; 
new_node->next=start; 
return start;
}
 
struct node *delete_beg(struct node *start)
{
struct node *ptr; 
ptr=start;
while(ptr->next!=start) 
ptr=ptr->next;
 
ptr->next=start->next; 
free(start);
start=ptr->next;
return start;
}
 
struct node *delete_element(struct node *start)
{
struct node *ptr, *preptr; 
int val;
printf("Enter the value of the node which has to deleted : "); 
scanf("%d", &val);
ptr = start;
if(ptr->data==val)
{
ptr=start;
while(ptr->next!=start) 
ptr=ptr->next;
 
ptr->next=start->next; 
free(start);
start=ptr->next; 
return start;
}
else
{
while(ptr->data!=val)
{
preptr=ptr; 
ptr=ptr->next;
if(ptr->next==start)
{
printf("ELEMENT NOT FOUND\n");
return start;
}
}
 
preptr->next=ptr->next; 
free(ptr);
return start;
}
 
}
 
struct node *delete_end(struct node *start)
{
struct node *ptr, *preptr; 
ptr = start;
while(ptr -> next != start)
{
preptr = ptr;
ptr = ptr -> next;
}
 
preptr -> next = ptr -> next; 
free(ptr);
return start;
}

