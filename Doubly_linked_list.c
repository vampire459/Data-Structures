#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *r_link , *l_link;
}n;

n *head = NULL;

void add_front();
void add_end();
void add_any_point();
void del_front();
void del_end();
void del_any_point();
void display_from_front();
void display_from_end();
int length();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.add_front\t2.add_end\t3.add_any-point\n\t4.display_from_front\t5.display_from_end\n\t6.del_front\t7.del_end\t8.del_any_position\n\t9.exit");
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
            display_from_front();
            break;
        case 5 :
            display_from_end();
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
    new_node->l_link = NULL;
    if(head==NULL)
        new_node->r_link = NULL;
    else
    {
        new_node->r_link = head;
        head->l_link = new_node;
    }
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
    new_node->r_link=NULL;
    if(head==NULL)
    {
        head = new_node;
        new_node->l_link = NULL;
    }
    else
    {
        while(h->r_link!=NULL)
            h=h->r_link;
        h->r_link = new_node;
        new_node->l_link = h;
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
    new_node->data = value;
    new_node->l_link = NULL;
    new_node->r_link = NULL;
    if(pos>=1 && pos<=length())
    {
        if(pos==1)
        {
            new_node->r_link=head;
            head = new_node;
        }
        else
        {
            for(i=1;i<pos-1;i++)
                h = h->r_link;
            if(h->r_link == NULL)
            {
                new_node->r_link = h->r_link;
                new_node->l_link = h;
                h->r_link = new_node;
            }
            else
            {
                new_node->r_link = h->r_link;
                new_node->l_link = h;
                h->r_link = new_node;
                h = new_node->r_link;
                h->l_link = new_node;
            }
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
    else if(head->r_link == NULL)
    {
        printf("\n\t%d deleted ",head->data);
        head = head->r_link;
        free(h);
    }
    else
    {
        printf("\n\t%d deleted ",head->data);
        head = head->r_link;
        head->l_link = NULL;
        free(h);
    }
}

void del_end()
{
    n *h=head ,*k;
    if(head==NULL)
        printf("\tNO DELETION , EMPTY LIST");
    else if(head->r_link == NULL)
    {
        printf("\n\t%d deleted ",head->data);
        head = head->r_link;
        free(h);
    }
    else
    {
        while(h->r_link!=NULL)
        {
            k = h;
            h = h->r_link;
        }
        k->r_link = NULL;
        h->l_link = NULL;
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
            if(head->r_link == NULL)
            {
                printf("\n\t%d deleted ",head->data);
                head = head->r_link;
                free(h);
            }
            else
            {
                printf("\n\t%d deleted ",h->data);
                head = head->r_link;
                head->l_link = NULL;
                free(h);
            }
        }
        else
        {
            for(i=1;i<pos;i++)
            {
                k = h;
                h = h->r_link;
            }
            printf("\n\t%d deleted ",h->data);
            if(h->r_link == NULL)
            {
                k->r_link = h->r_link;
                h->l_link = NULL;
                free(h);
            }
            else
            {
                k->r_link = h->r_link;
                free(h);
                h = k->r_link;
                h->l_link = k;
            }
        }
    }
    else
        printf("\nWRONG POSITION");
}

void display_from_front()
{
    n *h=head;
    if(h==NULL)
        printf("\n\tlist is empty");
    else
    {
        printf("\tlist values are :-\n");
        while(h->r_link!=NULL)
        {
            printf("\t%d",h->data);
            h=h->r_link;
        }
        printf("\t%d",h->data);
    }
}

void display_from_end()
{
    n *h=head;
    if(h==NULL)
        printf("\n\tlist is empty");
    else
    {
        while(h->r_link!=NULL)
            h=h->r_link;
        printf("\tlist values are :-\n");
        while(h->l_link!=NULL)
        {
            printf("\t%d",h->data);
            h=h->l_link;
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
    else if(h->r_link == NULL)
        count = 1;
    else
        while(h!=NULL)
        {
            h = h->r_link;
            count++;
        }
    count++;
    return count;
}
