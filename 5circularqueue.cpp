#include <stdio.h>
#include<conio.h>
int isfull();
int isempty();
void enqueue(int);
int dequeue();
void display();
int cq[5]={0};
int rear=-1, front=-1;

int main()
{int ch, elem;
 while (ch!=4)
   {printf("\nPress 1: Insert element into queue\n      2: Delete element from queue\n      3: Display the queue\n      4: Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
      {case 1:
	     if (isfull())
		   {printf("Circular queue is full\n");
		   }
		 else
		   {printf("Enter element to be inserted= ");
		    scanf("%d", &elem);
			enqueue(elem);
		   }
	     break;
 
      case 2:
         if(isempty())
           {printf("\nCircular queue is empty\n");
           }
         else
           {elem= dequeue();
            printf("%d is the deleted element\n",elem); 
           }
         break;
 
      case 3:
         if (isempty())
           {printf("Circular queue is empty\n");
           }
         else
		   {display();
		   }
	  break;
 
      case 4:
         printf("Exiting the program");
         break;
 
      default:
         printf("Enter a valid choice\n");
         break;
     }
  }
 return 0;
}

int isfull()
{if ((front==0 && rear==4) || (rear+1==front))
   return 1;
 else
   return 0;
}

int isempty()
{if (front==-1)
   return 1;
 else
   return 0;
}

void enqueue(int elem)
{if(front==-1)
   {front=rear=0;
   }
 else if(rear==4)
   {rear=0;
   }
 else
   {rear=rear+1;
   }
 cq[rear]=elem;
}

int dequeue()
{int elem;
 elem= cq[front];
 if(front==rear)
   {front=-1;
    rear=-1;
   }
 else if(front==4)
   {front=0;
   }
 else
   {front=front+1;
   }
 return elem;
}

void display()
{int i;
 printf("Front=%d and Rear=%d",front,rear);
 printf("\nElements in the queue are: \n");
 if(rear>front)
   {for(i=front;i<=rear;i++)
     {printf("%d  ",cq[i]);
     }
   }
 else
   {for(i=front;i<=4;i++)
     {printf("%d  ",cq[i]);
     }
    for(i=0; i<=rear; i++)
     {printf("%d  ",cq[i]);
     }
   }
}


