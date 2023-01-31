#include<stdio.h>
#include<stdlib.h>
int q[100],f,r,m,ch,x,i;
void ins(void);
void dis(void);
int main()
{
    f=-1,r=-1;
    printf("enter the size of QUEUE(max:100) : ");
    scanf("%d",&m);
    for(;;)
    {
        printf("\n 1.insertion\t 2.display\t3.exit ");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                ins();
                break;
            case 2 :
                dis();
                break;
            case 3:
                exit(0);
            default :
                printf("\n\tPLEASE ENTER A VALID CHOICE(1/2/3)");
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

void dis()
{
    if(f==-1&&r==-1)
        printf("\n\tNO DISPLAY_QUEUE UNDERFLOW");
    else
        for(i=f;i<=r;i++)
            printf("\t%d",q[i]);
}
