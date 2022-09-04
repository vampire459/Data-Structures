#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}n;
n *head = NULL;

void add_end();
void del_front();
void display();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.INSERT\t2.DELETE\t3.DISPLAY\n\t4.EXIT");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            add_end();
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

void add_end()
{
    int value;
    printf("\nEnter a value to be added : ");
    scanf("%d",&value);
    n *new_node ,*h;
    h = head;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    new_node->link=NULL;
    if(head==NULL)
        head = new_node;
    else
    {
        while(h->link!=NULL)
            h=h->link;
        h->link = new_node;
    }
}

void del_front()
{
    n *h=head;
    if(head==NULL)
        printf("\tNO DELETION , EMPTY LIST");
    else
    {
        printf("\n\t%d DELETED ",head->data);
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
        printf("\tlist values are :-\n");
        while(h->link!=NULL)
        {
            printf("\t%d",h->data);
            h=h->link;
        }
        printf("\t%d",h->data);
    }
}
