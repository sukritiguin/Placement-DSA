#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define exp_size 100

struct stack_node{
    char data;
    struct stack_node* next;
};

struct stack_node* head=NULL;

void push(char data);
void pop();
char top();
int precedence_order(char operato);
void infix_to_prefix(char exp[]);

int main(){
    char exp[exp_size];
    printf("Enter the infix exp : ");
    gets(exp);
    infix_to_prefix(exp);
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
    printf("Postfix exp : %s\n",result);
}
