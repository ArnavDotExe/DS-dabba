#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node*create(struct node*);
struct node*start=NULL;
struct node*insert_beg(struct node*);
struct node*insert_end(struct node*);
struct node*delete_beg(struct node*);
struct node*delete_node(struct node*);
struct node*display(struct node*);
struct node
{
int data;
struct node*next;
};
int main(int argc,char*argv[])
{
int option;
do
{
printf("\n***MAIN MENU***");
printf("\n1. Create the list");
printf("\n2. Add node at the beginning");
printf("\n3. Add node at the end");
printf("\n4. Delete given node");
printf("\n5. Display the list");
printf("\n6. Exit");
printf("\nEnter your option:");
scanf("%d",&option);
switch(option)
{
case 1:
start=create(start);
printf("Linked list created\n");
break;
case 2:
start=insert_beg(start);
break;
case 3:
start=insert_end(start);
break;
case 4:
start=delete_node(start);
break;
case 5:
start=display(start);
printf("\n");
break;
case 6:
exit(0);
break;
default:
printf("Invalid choice\n");
break;
}
}
while(option!=7);
getch();
return 0;
}
struct node*create(struct node*start)
{
struct node*new_node,*ptr;
int num;
printf("\nEnter -1 to end");
printf("\nEnter the data:");
scanf("%d",&num);
while(num!=-1)
{
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
else
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
new_node->next=NULL;
}
printf("\nEnter the data:");
scanf("%d",&num);
}
return start;
}
struct node*display(struct node*start)
{
struct node*ptr;
if(start==NULL)
{
printf("List is empty\n");
}
else
{
ptr=start;
while(ptr!=NULL)
{
printf("\t%d",ptr->data);
ptr=ptr->next;
}
return start;
}
}
struct node*insert_beg(struct node*start)
{
struct node*new_node;
int num;
printf("\nEnter the data:");
scanf("%d",&num);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
new_node->next=start;
start=new_node;
return start;
}
struct node*insert_end(struct node*start)
{
struct node*ptr;
struct node*new_node;
int num;
printf("\nEnter the data:");
scanf("%d",&num);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
new_node->next=NULL;
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
return start;
}
struct node*delete_beg(struct node*start)
{
struct node*ptr;
ptr=start;
start=start->next;
free(ptr);
return start;
}
struct node*delete_node(struct node*start)
{
struct node*ptr,*preptr;
int val;
printf("Enter the value of node to be deleted:");
scanf("%d",&val);
ptr=start;
if(ptr->data==val)
{
//start=delete_beg(start);
ptr=start;
start=start->next;
free(ptr);
return start;
}
else
{
while(ptr->data!=val)
{
preptr=ptr;
ptr=ptr->next;
if(ptr==NULL)
{
printf("Element not found\n");
return start;
}
}
preptr->next=ptr->next;
free(ptr);
return start;
}
}

