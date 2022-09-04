#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}n;
n *head = NULL;

void add_front();
void del_front();
void display();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.PUSH\t2.POP\t3.DISPLAY\n\t4.EXIT");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            add_front();
            break;
        case 2:
            del_front();
            break;
        case 3 :
            display();
            break;
        case 4 :
            exit(0);
        default :
            printf("inavlid choice ");
        }
    }
    return 0;
}

void add_front()
{
    int value;
    printf("\nEnter a value to be added : ");
    scanf("%d",&value);
    n *new_node ;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    if(head==NULL)
        new_node->link = NULL;
    else
        new_node->link=head;
    head = new_node;
}

void del_front()
{
    n *h=head;
    if(head==NULL)
        printf("\tNO DELETION , EMPTY LIST");
    else
    {
        printf("\n\t%d POPPED ",head->data);
        head = head->link;
        free(h);
    }
}
void display()
{
    n *h=head;
    if(h==NULL)
        printf("\n\tlist is empty");
    else
    {
        printf("list values are :-");
        while(h->link!=NULL)
        {
            printf("\n%d",h->data);
            h=h->link;
        }
        printf("\n%d",h->data);
    }
}
