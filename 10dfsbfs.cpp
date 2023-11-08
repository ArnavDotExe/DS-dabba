#include<stdio.h>
#include<stdlib.h>
int a[20][20], n , visited[20];
char name[20]; 
int stack[20], top=-1;
int queue[20], r=-1, f=-1;
void DFS(int v)
{
int j;
stack[++top]=v;
visited[v]=1;
while(top!=-1)
{
v=stack[top--];
printf("%c->",name[v]);
for(j=1; j<=n; j++)
{
if(a[v][j]!=0 && visited[j]==0)
{
stack[++top]=j;
visited[j]=1;
}
}
}
}
void enqueue(int v)
{
queue[++r]=v;
if(f==-1)
f=0;
}
void BFS(int v) {

int j;
enqueue(v);
visited[v]=1;
while(f<=r)
{
v=queue[f++]; 
printf("%c->",name[v]);
for(j=1; j<=n; j++)
{
if(a[v][j]!=0 && visited[j]==0)
{
enqueue(j);
visited[j]=1;
}
}
}
}
int main()
{
int i,j, ch;
printf("\n Enter number of vertices:");
scanf("%d",&n);
printf("\n Enter name of vertex:");
for(i=1;i<=n;i++)
scanf(" %c",&name[i]);
printf("\n Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
while(1) 
{
printf("\n-- Graph Traversal Operation ----");
printf("\n1.DFS Traversal \n2.BFS Traversal \n3.Exit");
printf("\n Please Enter your choice ");
scanf("%d",&ch);
switch(ch)
{
case 1:
for(i=1; i<=n; i++) 
visited[i]=0;
for(i=1; i<=n; i++) 
if(visited[i]==0)
DFS(i);
break;
case 2:
for(i=1; i<=n; i++) 
visited[i]=0;
for(i=1; i<=n; i++) 
if(visited[i]==0)
BFS(i);
break;
case 3: exit(0);
}
}
return 0;
}

