#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* intopo(char* e,char* s,char* r);
int preci(char c);
int main()
{
	int c;
	while(1)
	{
		char e[100];
		char s[100],r[100]={NULL};
		printf("1.Infix to postfix\n2.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the infix expression:");
			        getchar();
			        gets(e);
			        printf("The postfix expression is: %s\n",intopo(e,s,r));
			        break;
			case 2: exit(0);
			default: printf("Wrong choice!\n");
		}
	}
	return 0;
}

char* intopo(char* e,char* s,char* r)
{
    int i=0,p=0,top=-1;
    while(e[i]!='\0')
    {
        if(e[i]=='(')
        {
            top++;
            s[top]=e[i];
        }
        else
        {
            if(e[i]==')')
            {
                while(s[top]!='(')
                {
                    r[p]=s[top];
                    top--;
                    p++;
                }
                top--;
            }
            else if(e[i]=='^' || e[i]=='*' || e[i]=='/' || e[i]=='%' || e[i]=='+' || e[i]=='-')
            {
                while(top>=0 && preci(s[top])>=preci(e[i]) && s[top]!='(' && s[top]!=')')
                {
                    r[p]=s[top];
                    top--;
                    p++;
                }
                top++;
                s[top]=e[i];
            }
            else
            {
                r[p]=e[i];
                p++;
            }
        }
        i++;
        //printf("%c\t%s\t\t%s\n",e[i],s,r);
    }
    while(top>=0)
	{
		if(s[top]=='(' || s[top]==')')
		{
			top--;
		}
		else
		{
			r[p]=s[top];
			p++;
			top--;
		}
	}
	p--;
    return r;
}

int preci(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/' || c=='%')
            return 2;
    else return 1;
}
