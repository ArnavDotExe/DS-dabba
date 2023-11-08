#include<stdio.h>
#define MAX 5 
int top=-1,stack[MAX];
void push();
void pop();
void display();
void peek();

int main()
{
int ch;
while(ch!=5)
{
printf("\n*** Stack Menu ***");
printf("\n\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit");

scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: peek();
break;

default: printf("\nWrong Choice!!");
}
}
return 0;
}
 
void push()
{
int val;
if(top==MAX-1)
{
printf("\nStack is full!!");
}
else
{
printf("\nEnter element to push:");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}
 
void pop()
{
if(top==-1)
{
printf("\nStack is empty!!");
}
else
{
printf("\nDeleted element is %d",stack[top]);
top=top-1;
}
}
 
void display()
{
int i;
if(top==-1)
{
printf("\nStack is empty!!");
}
else
{
printf("\nStack is...\n");
for(i=top;i>=0;--i)
printf("%d\n",stack[i]);
}
}

void peek()
{
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        printf("the top element of the stack is:%d",stack[top]);
    }
}


