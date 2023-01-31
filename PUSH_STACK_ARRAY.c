#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void display(void);
int main()
{
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\t 1.PUSH\t 2.DISPLAY\t 3.EXIT");
    for(;;)
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");

        }
    }
    return 0;
}
void push()
{
    if(top>=n-1)
        printf("\n\tover flow");

    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
        printf("\n The STACK is empty");

}
