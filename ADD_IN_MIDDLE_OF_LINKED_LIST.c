#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}n;
n *head = NULL;

void create();
void add_middle();
void display();
int length();

int main()
{
    int ch;
    for(;;)
    {
        printf(" \n\t1.Create_list\t2.add_at_middle\t\t3.display\t4.exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            add_middle();
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

void create()
{
    int num , i ;
    printf("\n no. of nodes in the list : ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
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
