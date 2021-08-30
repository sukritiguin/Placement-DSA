#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertion_beginning();  
void insertion_last();  
void deletion_beginning();  
void deletion_last();  
void display();  
void search(); 
void splitList();
void displayList(struct node *head);
void sortedInsert();
void exchangeNodes();
void deleteAllOccurOfX();
void deleteNode(struct node *head_ref, struct node *del);
void largestNodeElement();
void rotateLinkedList();
void reverseByGivenGroupSize();
struct node* reverseByN(struct node *head, int k);
void insertEnd(struct node *head, struct node *new_node);
struct node *reverse(struct node *head);
void sumOfAllNodeExceptItself();


int main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        //printf("\n*********Main Menu*********\n");  
        //printf("\nChoose one option from the following list ...\n");  
        printf("===============================================");  
        printf("\n0.Exit\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n");
        printf("4.Delete from last\n5.Search\n6.Show\n7.Split Circular Linked List\n");
        printf("8.Node inserted in sorted ordered.\n9.Exchane 1st and last node.\n");
        printf("10.Delete occurance of any key element.\n11.Largest element in Linked List.\n");
        printf("12.Rotate linked list.\n13.Reverse by group.\n14.Sum of all node except itself.\n");
        printf("\nEnter your choice : ");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 0:  
                exit(0);  
                break; 
            case 1:  
                insertion_beginning();  
                break;  
            case 2:  
                insertion_last();  
                break;  
            case 3:  
                deletion_beginning();  
                break;  
            case 4:  
                deletion_last();  
                break;  
            case 5:  
                search();  
                break;  
            case 6:  
                display();  
                break;   
            case 7:
                splitList();
                break;
            case 8:
                sortedInsert();
                break;
            case 9:
                exchangeNodes();
                break;
            case 10:
                deleteAllOccurOfX();
                break;
            case 11:
                largestNodeElement();
                break;
            case 12:
                rotateLinkedList();
                break;
            case 13:
                reverseByGivenGroupSize();
                break;
            case 14:
                sumOfAllNodeExceptItself();
                break;
            default:  
            printf("Please enter valid choice..");  
        } 
    }  
}  
void insertion_beginning()  
{  
   struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value : ");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(head==NULL)  //no node available
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   //more than one node is avaiable
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  //next of last node will contains address of new node
    ptr -> prev = temp;  //prev part of new node will contain address of last node
    head -> prev = ptr;  //prev part of 1st node contains address of new node
    ptr -> next = head;  //next part of new node will contains address of 1st node(head)
    head = ptr;  //now head will points to new node
   }  
   printf("\nNode inserted at begin.\n");  
}  
     
}  
void insertion_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  //if no new node created
   {  
       printf("\nOVERFLOW");  
   }  
   else  //if new node created
   {  
       printf("\nEnter value : ");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  //if no node is available
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  //node available previously
       {  
          temp = head;  //temp=head for traversing
          while(temp->next !=head)  //we will go upto temp->next!=head to get last node address
          {  
              temp = temp->next;  //traversing
          }  
          temp->next = ptr;  //next of last node = address of new node
          ptr ->prev=temp;  //prev of new node = address of last node
          head -> prev = ptr;  //prev of 1st node = address of new node
          ptr -> next = head;  //next of new node = 1st node address(head)
        }  
   }  
     printf("\nnode inserted at last\n");  
}  
  
void deletion_beginning()  
{  
    struct node *temp;  
    if(head == NULL)  //if no node available
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  //if only one node available
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted at first\n");  
    }  
    else  //if more than one node available
    {  
        temp = head;   //temp = head to traverse
        while(temp -> next != head)  //we will go upto last node
        {  
            temp = temp -> next;  //traversing
        }  
        temp -> next = head -> next;  //next of last node = 2nd node (head->next)
        head -> next -> prev = temp;  //prev of 2nd node (head->next->prev) = last node address
        free(head);  //free 1st node
        head = temp -> next;  //head will points to next node
        printf("Node deleted at first.\n");
    }  
  
}  
void deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  //if no node available
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  //only one node available
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted at last\n");  
    }  
    else   //more than one node available
    {  
        ptr = head;   //to traverse
        if(ptr->next != head)  //traverse upto last node to get address of last node
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = head;  //next of 2nd last node (ptr->prev->next)
                                     // = address of 1st node (head)
        head -> prev = ptr -> prev;  //prev of 1st node = address of 2nd last node
        free(ptr);  //free last node
        printf("\nnode deleted at last\n");  
    }  
}  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\nprinting values : ");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d<->", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d<->\n", ptr -> data);  
    }  
              
}  
  
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search : ");   
        scanf("%d",&item);  
        if(head ->data == item)  
        {  
        printf("Item found at location %d\n",i+1);  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == item)  
            {  
                printf("Item found at location %d\n",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("Item not found\n");  
        }  
    }     
          
}  


void splitList(){
    struct node *slow=head;
    struct node *fast=head->next;
    while(fast!=head && (fast->next)!=head){
        slow=slow->next; //slow pointer will contains the address of middle element
        fast=fast->next->next; //fast pointer will go upto end node
    }
    struct node *head1_ref=head;//address of 1st list
    struct node *head2_ref=slow->next;//address of 2nd list
    slow->next=head1_ref;//next of 1st list of last node will points to head of 1st node
    head->prev=slow;//prev of 1st list of 1st node = last node of 1st list(slow)
    struct node *cur=head2_ref; //cur for traversing the 2nd list
    while(cur->next!=head){
        cur=cur->next;//cur will points to last node of the list
    }
    cur->next=head2_ref; //next of last node will points to head of 2nd list(head2_ref)
    head2_ref->prev=cur; //prev of 1st of of 2nd list(head2_ref->prev)
                         // = last node address of 2nd node
    printf("1st List : \n");
    displayList(head1_ref);
    printf("2nd List : \n");
    displayList(head2_ref);
}

void displayList(struct node *head)  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\nprinting values : ");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d<->", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d<->\n", ptr -> data);  
    }  
              
} 

void sortedInsert()
{
    //code here
    struct node* current = head;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    new_node->data=element;
 
  if (current == NULL) //when no node is available
  {
     new_node->next = new_node;
     new_node->prev=new_node;
     head = new_node;
  }
 
  // Case 2 of the above algo
  else if (current->data >= new_node->data) //when element of 1st node is equal
                                            //to the element of new node
  {
    while(current->next != head)
        current = current->next;//current will traverse upto last node and finnaly it will points 
                                //to last node of the linked list
    current->next = new_node; //next of last node = address of 1st node
    new_node->next = head; //next of new node = address of 1st node(to insert at begin)
    new_node->prev=current; //prev of new node = address of last node
    head = new_node; //head will updated to address of new node
  }

  else //when element of new node will be in somewhere in middle of the node
  {
    while (current->next!= head && current->next->data < new_node->data)
        current = current->next; //current will go upto the correct position for the new node
    //current will Locate the node after which new node is to be inserted
 
    new_node->next = current->next; //next of new_node will points to next node of current
    new_node->prev = current; //prev of new_node will points to current node
    current->next->prev=new_node; //prev of next node of current node  will points to new_node
    current->next = new_node; //next of current will points  to new_node
  }
  printf("Node inserted in sorted ordered.\n");
}

void exchangeNodes()
{
    if (head->next->next == head) { //when only two node is available
        head = head->next;          //head will points to 2nd node
    }
  
    else{
        struct node* temp = head; // temp will treverse
        while (temp->next->next != head) //finally temp will points to 2nd last
            temp = temp->next; //node so temp->next->next!=head
        struct node *temp1=temp->next; //copying the address of last node
        struct node *head1=head; //copying the address of 1st node
        temp->next=head1;//now next of 2nd last node will points to 1st node(head)
        head1->prev=temp;//prev of 1st node will points to 2nd last node
        temp1->next=head->next;//next of last node now pointing to address of 2nd node
        temp1->prev=head1;//prev of last node is pointing to 1st node
        head1->next=temp1;//next part of 1st node is pointing to the address of last node
        head=temp1;//now head will point to last node
    }
    printf("1st Node and Last Node are exchanged.\n");
}

//delete all occurance of any key element
void deleteAllOccurOfX()
{
    int key;
    printf("Enter the element : ");
    scanf("%d",&key);
    /* if list is empty */
    if ((head) == NULL)
        return;
 
    struct node* current = head;
    struct node* next;

    //********************************
    if (current->data == key) {
 
            /* save current's next node in the
               pointer 'next' */
            next = current->next;
 
            /* delete the node pointed to by
              'current' */
            deleteNode(head, current);
 
            /* update current */
            current = next;
        }
 
        /* else simply move to the next node */
        else
            current = current->next;
    //********************************
 
    /* traverse the list up to the end */
    while (current != head) {
 
        /* if node found with the value 'x' */
        if (current->data == key) {
 
            /* save current's next node in the
               pointer 'next' */
            next = current->next;
 
            /* delete the node pointed to by
              'current' */
            deleteNode(head, current);
 
            /* update current */
            current = next;
        }
 
        /* else simply move to the next node */
        else
            current = current->next;
    }
    printf("All occurance of %d is deleted.\n",key);
}

//delete node of the occurance key
void deleteNode(struct node *head, struct node *del)
{
    /* base case */
    if (head == NULL || del == NULL)
        return;
 
    else{
        del->prev->next=del->next;
        del->next->prev=del->prev;
    }
 
    /* Finally, free the memory occupied by del*/
    free(del);
}

//Largest Node of the linked list
void largestNodeElement(){
    struct node *max, *temp;//initialize two pointer temp and max on the head node
    temp = max = head;

    // for first node of linked list and this is  also same for other
    if (temp->data > max->data)
        max = temp;
    temp = temp->next;
 
    // traverse the whole doubly linked list
    while (temp != head) {
        if (temp->data > max->data)
            max = temp;//if the current temp is greater the max address will be updated
        temp = temp->next;
    }
    printf("Max element of the Linked List : %d\n",max->data);
}

//Rotate linked list by N
void rotateLinkedList(){
    int key;
    printf("Number of rotation : ");
    scanf("%d",&key);
    if(key==0){//if no rotation is there
        return;
    }
    else{//if key is not zeo ; more than zero rotation is there
        struct node *current=head;//current is pointing to head
        int count=0;
        //for 1st time
        if(count<=key && current->next!=head && key!=1){
            current=current->next;
            count=2;
        }
        //for others time
        int indicator=0;
        while(count<key && current!=head){
            current=current->next; //finnaly current will point to key-th node
            count++;
            if(current==head)
                indicator=-1;
        }
        if(count==key && current==head && indicator==-1){//if rotation is greater than or equal
                                                        //to number of elements
            displayList(head);
            return;
        }
        struct node *nthNode=current;//nth node points to current
        struct node *temp=current->next;//temp will points to next part of current
        while(current->next!=head)
            current=current->next;//now current is point to last node
        current->next=head;//next of the last node = 1st part of nodes
        head->prev=current;//prev of the 1st node of 1st part list = 
                           //current(last node of whole node)
        head=nthNode->next;//head will points to the (key+1)th node
        head->prev=nthNode;//prev of current node = 
        nthNode->next=temp;
    }
    printf("Node is rotated by %d\n",key);
    displayList(head);
}

//reverse linked list by a given size of group
void reverseByGivenGroupSize()
{
    int key;
    printf("Enter the number of nodes in each group : ");
    scanf("%d",&key);
    struct node *head1,*head2,*temp=head,*temp1;
    int countNode=1;
    while(temp->next!=head){
        temp=temp->next;
        countNode++;
    }
    temp=head;
    for(int k=0;k<countNode/key;k++){
        head1=head;
        for(int i=0;i<key;i++){
            temp=temp->next;
        }
        head2=temp;
        temp1=head1->prev;
        //1st linked list which will be reverse
        temp->prev->next=head1;
        head1->prev=temp->prev;
        //another part of the linked list after split
        temp1->next=temp;
        temp->prev=temp1;
        head1=reverse(head1);
        displayList(head1);
    }
}

//reverse linked list
// Function to insert at the end
void insertEnd(struct node *head, struct node *new_node)
{
    // If the list is empty, create a single node
    // circular and doubly list
    if (head == NULL) {
        new_node->next = new_node->prev = new_node;
        head = new_node;
        return;
    }
 
    // If list is not empty
 
    /* Find last node */
    struct node *last = (head)->prev;
 
    // Start is going to be next of new_node
    new_node->next = head;
 
    // Make new node previous of start
    (head)->prev = new_node;
 
    // Make last preivous of new node
    new_node->prev = last;
 
    // Make new node next of old last
    last->next = new_node;
}
 
// Uitlity function to revesre a
// doubly circular linked list
struct node *reverse(struct node *head)
{
    if (head==NULL)
        return NULL;
 
    // Initialize a new head pointer
    struct node *new_head = NULL;
 
    // get pointer to the the last node
    struct node *last = head->prev;
 
    // set 'curr' to last node
    struct node *curr = last, *prev;
 
    // traverse list in backward direction
    while (curr->prev != last) {
        prev = curr->prev;
 
        // insert 'curr' at the end of the list
        // starting with the 'new_head' pointer
        insertEnd(new_head, curr);
        curr = prev;
    }
    insertEnd(new_head, curr);
 
    // head pointer of the reversed list
    return new_head;
}

void sumOfAllNodeExceptItself(){
    struct node *temp=head;
    int sum=0;
    if(head==NULL)
        return;
    else{
        sum=temp->data;
        temp=temp->next;
        while(temp!=head){
            sum=temp->data+sum;
            temp=temp->next;
        }
    }
    temp=head;
    temp->data=sum-temp->data;\
    temp=temp->next;
    while(temp!=head){
        temp->data=sum-temp->data;
        temp=temp->next;
    }
    displayList(head);
}