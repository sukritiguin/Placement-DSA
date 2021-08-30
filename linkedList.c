#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL	;

void display();
void beginInsert();
void lastInsert();
void randomInsert();
void beginDelete();
void lastDelete();
void randomDelete();
void countNode();
void reverseLinkedList();
void searchElement_iterative();
void deleteAllNode();
void nthNode();
void nthNode_fromLast();
void removeDuplicate_sortedLinkedList();
void middleElement();
void MergeSorting(struct node** head);
struct node* MergeBoth(struct node* first,struct node* second);
void FindMiddle(struct node* cur,struct node** first,struct node** second);
struct node* mergeSort(struct node* head);
void rotateList();
void detectLoop();


int main(){
	int choice;
	while(1){
		printf("*********************************\n");
		printf("Exit : 0\n");
	    printf("Insert at begining : 1\n");
	    printf("Insert at last : 2\n");
	    printf("Insert at any position : 3\n");
	    printf("Delete at begining : 4\n");
	    printf("Delete at last : 5\n");
	    printf("Delete at any position : 6\n");
	    printf("Counte node : 7\n");
	    printf("Reverse linked list : 8\n");
	    printf("Search element using iterative solutions : 9\n");
	    printf("Delete all nodes : 10\n");
	    printf("N-th node : 11\n");
	    printf("N-th node from last : 12\n");
	    printf("Remove duplicate elements from sorted linked list : 13\n");
	    printf("Merge Sort : 14\n");
	    printf("Display miiddle element : 15\n");
	    printf("Remove duplicate elements from unsorted linked list : 16\n");
	    printf("Rotate Linked List : 17\n");
	    printf("Display Linked List : 25\n");
	    printf("Enter Your Choice : ");
	    scanf("%d",&choice);
	    printf("\n*********************************\n");
	    if(choice==1)
	    	beginInsert();
	    if(choice==2)
	    	lastInsert();
	    if(choice==3)
	    	randomInsert();
	    if(choice==4)
	    	beginDelete();
	    if(choice==5)
	    	lastDelete();
	    if(choice==6)
	        randomDelete();
	    if(choice==7)
	    	countNode();
	    if(choice==8)
	    	reverseLinkedList();
	    if(choice==9)
	    	searchElement_iterative();
	    if(choice==10)
	    	deleteAllNode();
	    if(choice==11)
	    	nthNode();
	    if(choice==12)
	    	nthNode_fromLast();
	    if(choice==13)
	    	removeDuplicate_sortedLinkedList();
	    if(choice==14){
	    	mergeSort(head);
	    	printf("Linked List sorted using merge sort : \n");
	    }
	    if(choice==15)
	    	middleElement();
	    if(choice==16){
	    	mergeSort(head);
	    	removeDuplicate_sortedLinkedList();
	    }
	    if(choice==17)
	    	rotateList();
	    if(choice==18)
	    	detectLoop();
	    if(choice==25)
	    	display();
	}

	return 0;
}

void beginInsert(){
	struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	if(ptr==NULL){
		printf("Overflow.\n");
	}
	else{
		printf("Enter the value : ");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("Value inserted at begining.\n");
	}
}

void lastInsert(){
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
		printf("Overflow.\n");
	else{
		printf("Enter the value : ");
		scanf("%d",&item);
		if(head==NULL){
			ptr->data=item;
			ptr->next=NULL;
		}
		else{
			struct node *temp;
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			ptr->data=item;
			temp->next=ptr;
			ptr->next=NULL;
		}
		printf("Value inserted at last.\n");
	}
}

void randomInsert(){
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
		printf("Overflow.\n");
	else{
		int pos;
		printf("Enter the position : ");
		scanf("%d",&pos);
		printf("Enter the value : ");
		scanf("%d",&item);
		struct node *temp,*temp1;
		if(head==NULL){
			ptr->next=NULL;
			ptr->data=item;
			head=ptr;
		}
		else{
			temp=head;
			for(int i=1;i<pos;i++){
				temp1=temp;
				temp=temp->next;
				if(temp==NULL){
					printf("Unable to be inserted.\n");
					return;
				}
			}
			ptr->data=item;
			ptr->next=temp;
			temp1->next=ptr;
		}
		printf("Value inserted at %d-th position.\n",pos);
	}
}

void beginDelete(){
	if(head==NULL){
		printf("Unable to delete.\n");
		return;
	}
	struct node *temp;
	temp=head;
	head=temp->next;
	free(temp);
	printf("Value deleted at begining.\n");
}

void lastDelete(){
	if(head==NULL){
		printf("Unable to deleted.\n");
		return;
	}
	struct node *temp,*temp1;
	temp=head;
	while(temp->next!=NULL){
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
	printf("Value deleted at last.\n");
}

void randomDelete(){
	if(head==NULL){
		printf("Unable to deleted.\n");
		return;
	}
	else{
		struct node *temp,*temp1;
		temp=head;
		int pos;
		printf("Enter the position : ");
		scanf("%d",&pos);
		for(int i=1;i<pos;i++){
			temp1=temp;
			temp=temp->next;
			if(temp==NULL){
				printf("Unable to be deleted.\n");
				return;
			}
		}
		temp1->next=temp->next;
		free(temp);
		printf("Value deleted at %d-th position.\n",pos);
	}
}

void countNode(){
	if(head==NULL){
		printf("No node available.\n");
		return;
	}
	else{
		struct node *temp;
		temp=head;
		int counter=1;
		while(temp->next!=NULL){
			counter++;
			temp=temp->next;
		}
		printf("%d node available.\n",counter);
	}
}

void reverseLinkedList(){
	struct node *prevNode,*currentNode,*nextNode;
	prevNode=NULL;
	currentNode=head;
	nextNode=head;
	while(nextNode!=NULL){
		nextNode=currentNode->next;
		currentNode->next=prevNode;
		prevNode=currentNode;
		currentNode=nextNode;
	}
	head=prevNode;
	printf("Linked List reversed.\n");
}

void searchElement_iterative(){
	int key;
	int pos=1,index=-1,indicator=0;
	printf("Ente the element to be searched : ");
	scanf("%d",&key);
	if(head->data==key){
		printf("Element found.Position : 1\n");
		indicator=1;
	}
	struct node *temp=head;
	while(temp->next!=NULL){
		pos++;
		temp=temp->next;
		if(temp->data==key){
			index=1;
			break;
		}
	}
	if(index!=-1){
		printf("Element found. Position : %d\n",pos);
	}
	if(index==-1 && indicator==0){
		printf("Element not found.\n");
	}
}

void deleteAllNode(){
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		head=temp->next;
		free(temp);
		temp=head;
	}
	printf("All nodes are deleted.\n");
}

void nthNode(){
	struct node *temp=head;
	int pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	for(int i=1;i<=pos-1;i++){
		temp=temp->next;
	}
	printf("Value of %d-th position : %d\n",pos,temp->data);
	printf("Address of the node : %d\n",temp);
}

void nthNode_fromLast(){
	int counter=1;
	if(head==NULL){
		printf("No node available.\n");
		return;
	}
	else{
		struct node *temp;
		temp=head;
		while(temp->next!=NULL){
			counter++;
			temp=temp->next;
		}
	}
	struct node *temp1=head;
	int pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	for(int i=1;i<=counter-pos;i++){
		temp1=temp1->next;
	}
	printf("Value of %d-th position : %d\n",pos,temp1->data);
	printf("Address of the node : %d\n",temp1);
}

void removeDuplicate_sortedLinkedList(){
	struct node *temp=head;
	if(head==NULL){
		printf("No node available.\n");
		return;
	}
	if(head->next==NULL){
		printf("Only one node is available.\n");
		return;
	}
	while(head->next!=NULL){
		if(head->data==head->next->data)
			head->next=head->next->next;
		else
			head=head->next;
	}
	printf("Duplicate elements are deleted.\n");
	head=temp;
}

void middleElement(){
	struct node *slow=head;
	struct node *fast=head;
	if(head!=NULL){
		while(fast!=NULL && fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		printf("Middle Element : %d\n",slow->data);
	}
}

//MergeSort in Linked List

void MergeSorting(struct node** head){
        struct node* cur = *head;
        struct node* first;
        struct node* second;
        
        if(!cur || !cur->next)
            return;
        FindMiddle(cur,&first,&second);
        
        MergeSorting(&first);
        MergeSorting(&second);
        *head = MergeBoth(first,second);
    }
    
    struct node* MergeBoth(struct node* first,struct node* second){
        struct node* answer = NULL;
        
        if(!first)
            return second;
        else if(!second)
            return first;
            
        if(first->data <= second->data){
            answer = first;
            answer->next = MergeBoth(first->next,second);
        }
        else{
            answer = second;
            answer->next = MergeBoth(first,second->next);
        }
        return answer;
        
    }
    
    void FindMiddle(struct node* cur,struct node** first,struct node** second){
        struct node* fast;
        struct node* slow;
        slow = cur;
        fast = cur->next;
        
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        
        *first = cur;
        *second = slow->next;
        slow->next = NULL;
    }
    
    struct node* mergeSort(struct node* head){
        MergeSorting(&head);
        return head;
    }


// Rotate Linked List

void rotateList(){
	int key;
	printf("Enter the number  of rotation : ");
	scanf("%d",&key);
	int ind=key;
	if(head==NULL || head->next==NULL)
		return;
	int len=1;
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		len++;
	}
	temp->next=head;
	key=key%len;
	key=len-key;
	while(key!=0){
		temp=temp->next;
		key--;
	}
	head=temp->next;
	temp->next=NULL;
	printf("Linked List rotated by %d\n",ind);
}

// detect Loop

void detectLoop(){
	struct node *slow=head;
	struct node *fast=head;

	while(slow!=NULL && fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			printf("Loop detected.\n");
			return;
		}
	}
	printf("Loop not detected.\n");
}


void display(){
	struct node *ptr;
	ptr=head;
	if(head==NULL)
		printf("Node is empty.");
	else{
		printf("Linked List : ");
		while(ptr!=NULL){
			printf("%d -> ",ptr->data);
			ptr=ptr->next;
		}
	}
	printf("\n");
}