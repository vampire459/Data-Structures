#include<stdio.h>
#include<stdlib.h>
int q[100],f,r,m,ch,x,i;
void ins(void);
void del(void);
void dis(void);
int main()
{
    f=-1,r=-1;
    printf("enter the size of QUEUE(max:100) : ");
    scanf("%d",&m);
    for(;;)
    {
        printf("\n 1.insertion\t 2.deletion\t 3.display\t 4.exit ");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :
            {
                ins();  break;
            }
        case 2 :
            {
                del();  break;
            }
        case 3:
            {
                dis();  break;
            }
        case 4:
            {
                printf("\n\tBYE BYE");  exit(0);
            }
        default :
            {
                printf("\n\tPLEASE ENTER A VALID CHOICE(1/2/3/4)");
            }
        }
    }
    return 0;
}
void ins()
{
    if(r>=m-1)
        printf("\n\tOVERFLOW");
    else
    {
        r+=1;
        printf("\nEnter a value to be instered : ");
        scanf("%d",&q[r]);
        if(f==-1)
            f=0;
    }
}
void del()
{
    if(f==-1&&r==-1)
        printf("\n\tUNDERFLOW");
    else
    {
        printf("%d",q[f]);
        if(f==r)
        {
            f=-1;   r=-1;
        }
        else
            f+=1;
    }
}
void dis()
{
    if(f==-1&&r==-1)
        printf("\n\tNO DISPLAY_QUEUE UNDERFLOW");
    else
        for(i=f;i<=r;i++)
            printf("\n\t%d",q[i]);
}
