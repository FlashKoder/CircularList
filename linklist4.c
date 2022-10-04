#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *create_list(struct node *start)
{
struct node *ptr,*new_node;
int n;
printf("Enter number of elements you insert: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
int num;
printf("Enter data: ");
scanf("%d",&num);
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data=num;
if(start==NULL)
{
new_node->next=new_node;
start=new_node;
}
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=start;
}
return start;
}
void display_list(struct node *start)
{
if(start==NULL)
{
printf("Linked list is empty.\n");
return ;
}
struct node *ptr;
ptr=start;
if(ptr==NULL)
{
printf("Enter linked list is empty\n.");
}
else
{
while (ptr->next!=start)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
printf("%d\n",ptr->data);
}
}
struct node *insert_begin(struct node *start,int val)
{
struct node *ptr;
struct node *new_node;
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data =val;
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=start;
start=new_node;
return start;
}
struct node *insert_end(struct node *start,int val)
{
struct node *ptr;
struct node *new_node;
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data=val;
new_node->next=start;
ptr=start;
while(ptr->next!=start);
{
ptr=ptr->next;
}
ptr->next=new_node; 
return start;
}
struct node *insert_bet(struct node *start,int index,int val)
{
struct node *ptr,*preptr;
struct node *new_node;
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data=val;
int i=0;
ptr=start;
while(i!=index)
{
preptr=ptr;
ptr=ptr->next;
i++;
}
new_node->next=ptr;
preptr->next=new_node;
return start;
}
struct node *insertion(struct node *start,int val)
{
struct node *head;
int index,ch;
printf("********MENU********\n");
printf("1. Insert at the begining.\n");
printf("2. Insert at the end.\n");
printf("3. Insert at the given node.\n");
printf(">>Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
    head = insert_begin(start,val);
    break;
case 2:
    head = insert_end(start,val);
    break;
case 3:
    printf("Enter your index where you insert: ");
    scanf("%d",&index);
    head = insert_bet(start,index,val);
    break;
default:
    printf("Invalid choice.\n");
    break;
}
return head;
}
struct node *delete_beg(struct node *start)
{
struct node *head,*ptr;
head=start;
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=head->next;
start=head->next;
free(head);
return start; 
}
struct node *delete_end(struct node* start)
{
struct node *head,*ptr,*preptr;
ptr=start;
while(ptr->next!=start)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=start;
free(ptr);
return start;
}
struct node *delete_after(struct node *start)
{
struct node *ptr,*preptr;
int index;
printf("Enter index where you delete node: ");
scanf("%d",&index);
int i=0;
ptr=start;
while(i!=index)
{
preptr=ptr;
ptr=ptr->next;
i++;
}
preptr->next=ptr->next;
free(ptr);
return start;
}
struct node *delete_entire(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr->next!=start)
{
delete_end(start);
ptr=ptr->next;
}
free(ptr);
return start;
}
struct node* deletion(struct node *start)
{
int ch;
struct node *head;
if(start==NULL)
{
printf("Linked list is empty.\n");
return start;
}
printf("\n*******MENU*******\n");
printf("1.Delete begining of the list.\n");
printf("2.Delete end of the list.\n");
printf("3.Delete after a node.\n");
printf("4.Delete entire list.\n");
printf(">>Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
    head=delete_beg(start);
    break;
case 2:
    head=delete_end(start);
    break;
case 3:
    head=delete_after(start);
    break;
case 4:
    head=delete_entire(start);
    break;
default:
    printf("Invalid choice.\n");
    break;
}
return head;
}
int main()
{
int ch,val;
printf("*********MENU********\n");
printf("1. For create circular linked list.\n");
printf("2. For display circular linked list.\n");
printf("3. For insertion a new node.\n");
printf("4. For deletion.\n");
printf("5. For Exit.\n");
while(1)
{
printf("Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
    start=create_list(start);
    break;
case 2:
   display_list(start);
   break;
case 3:
    printf("Enter your value to insert: ");
    scanf("%d",&val);
    start=insertion(start,val);
    break;
case 4:
     start=deletion(start);
     break;
case 5:
      return 0;
      break;
default:
    printf("Invalid choice.\n");
    break;
}
}
return 0;
}