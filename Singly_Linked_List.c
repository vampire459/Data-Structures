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
void add_middle();
void add_any_point();
void del_front();
void del_end();
void del_any_point();
void display();
int length();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.add_front\t2.add_end\t3.add_middle\t4.add_any-point\n\t5.display\n\t6.del_front\t7.del_end\t8.del_any_position\n\t9.exit");
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
            add_middle();
            break;
        case 4 :
            add_any_point();
            break;
        case 5 :
            display();
            break;
        case 6:
            del_front();
            break;
        case 7:
            del_end();
            break;
        case 8:
            del_any_point();
            break;
        case 9 :
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

void add_middle()
{
    int pos=((length()-1)/2),value,i;
    printf("\nEnter the value to be added : ");
    scanf("%d",&value);
    n *new_node ,*h;
    h = head;
    new_node = (n *)malloc(sizeof(n));
    new_node->data=value;
    new_node->link=NULL;
    if(pos>=1 && pos<=length())
    {
            for(i=1;i<pos;i++)
                h = h->link;
            new_node->link = h->link;
            h->link = new_node;
    }
    else
        printf("\nWRONG POSITION");
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
    if(pos>=1 && pos<=length())
    {
        if(pos==1)
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
    else
        printf("\nWRONG POSITION");
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
    if(head == NULL)
        printf("\tNO DELETION , EMPTY LIST");
    else if(h->link == NULL)
    {
        head = NULL;
        printf("\n\t%d deleted ",h->data);
        free(h);
    }
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
        if(head==NULL)
            printf("\tNO DELETION , EMPTY LIST");
        else if(pos>=1 && pos<length())
        {
            if(pos==1)
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
        else
            printf("\nWRONG POSITION");
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

int length()
{
    n *h = head;
    int count = 0;
    if(h == NULL)
        count = 0;
    else if(h->link == NULL)
        count = 1;
    else
        while(h!=NULL)
        {
            h = h->link;
            count++;
        }
    count++;
    return count;
}
