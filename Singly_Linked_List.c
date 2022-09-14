#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}n;
n *head = NULL;

void add_front();
void add_end();
void add_any_point();
void del_front();
void del_end();
void del_any_point();
void display();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.add_front\t2.add_end\t3.add_any-point\n\t4.display\n\t5.del_front\t6.del_end\t7.del_any_position\n\t8.exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            add_front();
            break;
        case 2:
            add_end();
            break;
        case 3 :
            add_any_point();
            break;
        case 4 :
            display();
            break;
        case 5:
            del_front();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_any_point();
            break;
        case 8 :
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
void add_any_point()
{
    int pos,value,i;
    printf("\nEnter the postion to add : ");
    scanf("%d",&pos);
    printf("\nEnter the value to be added : ");
    scanf("%d",&value);
    n *new_node ,*h;
    h = head;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    new_node->link=NULL;
    if(head == NULL && pos!=1)
        printf(" INVALID CHOICE , LIST DON'T EXIST ");
    else if(pos<1)
        printf("WRONG POSITION");
    else if(pos==1)
    {
        new_node->link=head;
        head = new_node;
    }
    else
    {
        for(i=1;i<pos-1;i++)
            h = h->link;
        new_node->link = h->link;
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
        printf("\n\t%d deleted ",head->data);
        head = head->link;
        free(h);
    }
}

void del_end()
{
    n *h=head ,*k;
    if(head==NULL)
        printf("\tNO DELETION , EMPTY LIST");
    else
    {
        while(h->link!=NULL)
        {
            k = h;
            h = h->link;
        }
        k->link = NULL;
        printf("\n\t%d deleted ",h->data);
        free(h);
    }
}

void del_any_point()
{
        n *h=head ,*k;
        int i,pos;
        printf("\n enter the postion to be deleted : ");
        scanf("%d",&pos);
        if(head==NULL || pos<1)
            printf("\tNO DELETION , EMPTY LIST");
        else if(pos==1)
        {
            printf("\n\t%d deleted ",h->data);
            head = head->link;
            free(h);
        }
        else
        {
            for(i=1;i<pos;i++)
            {
                k = h;
                h = h->link;
            }
            printf("\n\t%d deleted ",h->data);
            k ->link = h->link;
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
