#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define exp_size 100

struct stack_node{
    char data;
    struct stack_node* next;
};

struct stack_node* head=NULL;

void reverse(char str[]);
void push(char data);
void pop();
char top();
int precedence_order(char operato);
void infix_to_prefix(char exp[]);

int main(){
    char exp[exp_size];
    printf("Enter the infix exp : ");
    gets(exp);
    reverse(exp);
    infix_to_prefix(exp);
    reverse(exp);
}

void reverse(char str[]){
    int n = strlen(str);
    //printf("len : %d\n",n);
    n = n-1;
    int i = 0;
    while(i<=n){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]==')' || str[i]=='}' || str[i]==']'){
            if(str[i]=='(')
                str[i]=')';
            else if(str[i]=='{')
                str[i]== '}';
            else if(str[i]=='[')
                str[i]==']';
            else if(str[i]==')')
                str[i]=='(';
            else if(str[i]=='}')
                str[i]=='{';
            else if(str[i]==']')
                str[i]=='[';
        }
        if(str[n]=='(' || str[n]=='{' || str[n]=='[' || str[n]==')' || str[n]=='}' || str[n]==']'){
            if(str[n]=='(')
                str[n]=')';
            else if(str[n]=='{')
                str[n]== '}';
            else if(str[n]=='[')
                str[n]==']';
            else if(str[n]==')')
                str[n]=='(';
            else if(str[n]=='}')
                str[n]=='{';
            else if(str[n]==']')
                str[n]=='[';
        }
        //////
        char temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        i++;
        n--;
    }
}

void push(char data){
    struct stack_node* new_stack_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(head==NULL){
        new_stack_node->data = data;
        new_stack_node->next = NULL;
        head = new_stack_node;
    }
    else{
        new_stack_node->data = data;
        new_stack_node->next = head;
        head = new_stack_node;
    }
}

void pop(){
    struct stack_node* temp = head;
    head = head ->next;
    free(temp);
}

char top(){
    return head->data;
}

int precedence_order(char operato){
    if(operato=='^')
        return 3;
    else if(operato=='*' || operato=='/' || operato=='%')
        return 2;
    else if(operato=='+' || operato=='-')
        return 1;
    else
        return -1;
}

void infix_to_prefix(char exp[]){
    char result[exp_size]={NULL};
    int index = 0; //index is the index of result array
    int i = 0;
    while(exp[i]!='\0'){
        // if any opening brackets is found then that will be stored in stack
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else{
            // if closing brackets are found
            if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                while(top()!='('){
                    result[index]=top(); //push the exp[i] in the result array
                    pop();
                    index++;
                }
                pop();
            }
            //if any operator found
            else if(exp[i]=='^' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%' || exp[i]=='+' || exp[i]=='-'){
                while(head!=NULL && precedence_order(top()) >= precedence_order(exp[i]) && top()!='(' && top()!=')' && top()!='{' && top()!='}' && top()!='[' && top()!=']'){
                    result[index]=top();
                    pop();
                    index++;
                }
                push(exp[i]);
            }
            else{
                result[index]=exp[i];
                index++;
            }
        }
        i++;
    }
    while(head!=NULL)
	{
		if(top()=='(' || top()==')')
		{
			pop();
		}
		else
		{
			result[index]=top();
			index++;
			pop();
		}
	}
	index--;
    reverse(result);
    printf("Prefix exp : ");
    puts(result);
}
