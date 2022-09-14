#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}n;

n *last = NULL;

void insrt();
void add_any_point();
void delet();
void del_any_point();
void display();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.insert\t2.add_any_positon\n\t3.display\n\t4.delete\t5.del_any_position\n\t6.exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insrt();
            break;
        case 2:
            add_any_point();
            break;
        case 3 :
            display();
            break;
        case 4 :
            delet();
            break;
        case 5 :
            del_any_point();
            break;
        case 6:
            exit(0);
        default :
            printf("inavlid choice ");
        }
    }
    return 0;
}

void insrt()
{
    int value;
    printf("\nEnter a value to be added : ");
    scanf("%d",&value);
    n *new_node , *h ;
    h = last;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    if(last==NULL)
    {
        new_node->link = new_node;
        last = new_node;
    }
    else if(last->link == last)
    {
        new_node->link = last;
        last->link = new_node;
    }
    else
    {
        while(h->link!=last)
            h = h->link;
        new_node->link = last;
        h->link = new_node;
    }
}

void add_any_point()
{
    int value , pos;
    printf("\nEnter the position to add : ");
    scanf("%d",&pos);
    printf("\nEnter a value to be added : ");
    scanf("%d",&value);
    n *new_node , *h =last;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    if(last == NULL && pos!=1)
        printf(" INVALID CHOICE , LIST DON'T EXIST ");
    else if(pos<1)
        printf("WRONG POSITION");
    else if(pos == 1 && last == NULL)
    {
        new_node->link = NULL;
        last = new_node;
    }
    else if(pos == 1 && last->link == last)
    {
        new_node->link  = last;
        last->link = new_node;
    }
    else if(pos == 1)
    {
        while(h->link!=last)
            h = h->link;
        new_node->link = last;
        h->link = new_node;
        last = new_node;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
            h = h->link;
        new_node->link = h->link;
        h->link = new_node;
    }
}

void delet()
{
    n *h = last , *k;
    if(last == NULL)
        printf("\nNO DELETION, LIST IS EMPTY");
    else if(last->link == last)
    {
        last = NULL;
        printf("\n%d DELETED",h->data);
        free(h);
    }
    else
    {
        while(h->link!=last)
        {
            k = h;
            h = h->link;
        }
        k->link = last;
        printf("\n%d DELETED",h->data);
        free(h);
    }
}

void del_any_point()
{
    int pos;
    printf("\nEnter the position to delete : ");
    scanf("%d",&pos);
    n *h = last ,*k ;
    if(last == NULL)
        printf("\nNO DELETION, LIST IS EMPTY");
    else if(pos == 1 && last->link == last)
    {
        last = NULL;
        printf("\n%d DELETED",h->data);
        free(h);
    }
    else if(pos == 1)
    {
        k = h;
        while(k->link!=last)
            k = k->link;
        k->link = last->link;
        last = last->link;
        printf("\n%d DELETED",h->data);
        free(h);
    }
    else
    {
        for(int i=1;i<pos;i++ )
        {
            k = h;
            h = h->link;
        }
        k->link = h->link;
        printf("\n%d DELETED",h->data);
        free(h);
    }
}

void display()
{
    n *h = last;
    if(h == NULL)
        printf("\nNO DISPLAY,EMPTY LIST");
    else if(h->link == last)
        printf("\t%d",h->data);
    else
    {
        while(h->link!=last)
        {
            printf("\t%d",h->data);
            h = h->link;
        }
        printf("\t%d",h->data);
    }
}
