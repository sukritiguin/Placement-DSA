#include <stdio.h>
#include <stdlib.h>

void beginInsert();
void lastInsert();
void randomInsert();
void display();
void beginDelete();
void lastDelete();
void randomDelete();


struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head;

int main(){
	int choice;
	while(1){
		printf("********************************************************************\n");
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
	    printf("\n********************************************************************\n");
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
	    if(choice==25)
	    	display();
	}

	return 0;
}

//insert at begin
void beginInsert(){
	int item;
	printf("Enter the data : ");
	scanf("%d",&item);
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr==NULL) //new node not created
		printf("Overflow\n");
	else{
		if(head==NULL){ //no node available
			ptr->next=NULL; //circular linked list
			ptr->prev=NULL;
			ptr->data=item;
			head=ptr;
		}
		else{ //more than one node available
			ptr->data=item;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
		printf("New node inserted at begin.\n");
	}
}

//insert at last
void lastInsert(){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)//node not created
		printf("Overflow\n");
	else{
		int item;
		printf("Enter the data : ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL){ //if no node is available
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
		}
		else{
			struct node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
		}
		printf("New node inserted at last.\n");
	}
}

//insert at random position
void randomInsert(){
	int loc;
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
		printf("Overflow\n");
	else{
		int item;
		printf("Enter the data : ");
		scanf("%d",&item);
		ptr->data=item;
		printf("Enter the location : ");
	  	scanf("%d",&loc);
	  	if(head==NULL){
	  		ptr->next=NULL;
	  		ptr->prev=NULL;
	  		head=ptr;
	  		printf("Inserted at 1st location.\n");
	  		return;
	  	}
	  	struct node *temp=head;
	  	for(int i=1;i<loc;i++){
	  		temp=temp->next;
	  		if(temp==NULL){
	  			printf("Can't insert.\n"); //position is greater than number of nodes
	  			return;
	  		}
	  	}
	  	
	  	ptr->next=temp; //next of ptr will contain k-th node address
	  	temp->prev->next=ptr; //(k-1)-th node's next will contain address of ptr
	  	ptr->prev=temp->prev; //prev of ptr will contain (k-1)th node address
	  	temp->prev=ptr; //temp->prev will contain ptr

	  	printf("Data insert at %d-th location.\n",loc);
	}
}

//delete at begin
void beginDelete(){
	struct node *ptr;
	if(head==NULL){ // when no node is available
		printf("No node is available to be deleted.\n");
	}
	else if(head->next==NULL){ //when only one node is available
		head=NULL;
		free(head);
		printf("Node deleted at begin.\n");
	}
	else{ //when more than one node is available
		ptr=head; //ptr contains the addresso head to free the head at last
		head=head->next; //head will go to next node
		head->prev=NULL; //prev part of next node will be NULL
		free(ptr); //finally free begin node
		printf("Node deleted at begin.\n");
	}
}

//delete at last
void lastDelete(){
	struct node *ptr;
	struct node *temp;//to treverse all the nodes
	if(head==NULL){ //when no node is there
		printf("No node available to be deleted.\n");
	}
	else if(head->next==NULL){ //only one node is there
		head=NULL;
		free(head);
		printf("Node deleted at last.\n");
	}
	else{ //more than one node is there
		temp=head;
		while(temp->next!=NULL){ // find the last node
			temp=temp->next;
		}
		ptr=temp; //copy the last node
		temp=temp->prev; //go to 2nd last node
		temp->next=NULL; //next part of 2nd last node will be NULL
		free(ptr); //free last node
		printf("Node deleted at last.\n");
	}
}

//delete node at random posoition
void randomDelete(){
	int pos;
	printf("Enter the position : ");
	scanf("%d",&pos);
	if(head==NULL){ //no node available
		printf("No node available to deleted.\n");
	}
	else if(head->next==NULL){ //one node available
		head=NULL;
		free(head);
		printf("1st node deleted.\n");
	}
	else{ //more than one node available
		struct node *ptr;
		struct node *temp=head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
			if(temp==NULL){
				printf("Less node available.\n");
				return;
			}
		}
		if(pos==1){ //for 1st node delete
			beginDelete();
		}
		else if(temp->next==NULL){ //for last node delete
			temp->prev->next=NULL;
			free(temp);
			printf("Node deleted at %d-th position.\n",pos);
		}
		else{ //for other node delete
			ptr=temp;
			temp=temp->prev;`
			temp->next=ptr->next;
			ptr->next->prev=temp;
			free(ptr);
			printf("Node deleted at %d-th position.\n",pos);	
		}
	}
}


//display all node data
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
