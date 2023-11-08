#include<stdio.h>
#include<conio.h>
#define max 100
int st[max];
int top=-1;
void push();
int pop();

void push(int value)
{
      top++;
      st[top]=value;

}
int pop()
{ int a;
      a=st[top];
      top--;
      return a;
}
 int is_operand(char ch)
 {
      if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
      return 1;
      else
      return 0;
 }
  int main()
  {
      char pf[max];
      int op1,op2,ch,i=0,m,result;
      printf("Enter the postfix expression \n");
      gets(pf);
      while (pf[i]!='\0')
      {
            ch=pf[i];
            if (is_operand(ch)==1)
            {
                  printf("enter the value of %c ",ch);
                  scanf("%d",&m);
                  push(m);
              }
              else
              {
                  op2=pop();
                  op1=pop();
                  switch (ch)
                  {
                        case '+': result=op1+op2; push(result); break;
                        case '-': result=op1-op2; push(result); break;
                        case '*': result=op1*op2; push(result); break;
                        case '/': result=op1/op2; push(result); break;
                        
                    }
              }
              i++;
        }
        result=pop();
        printf("\n The result is %d",result);
        getch();
        return 0;
  }


