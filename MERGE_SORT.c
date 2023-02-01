#include<stdio.h>
#include<conio.h>

void merge(int arr[],int lb,int mid,int ub)
{
	int b[50];
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
	{
		arr[k]=b[k];
	}
}
void mergesort(int arr[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
void main()
{
	int arr[50],n,i;
	printf("No. of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        printf("\n Enter element no. %d : ", i+1);
        scanf("%d",&arr[i]);
    }
	mergesort(arr,0,n-1);
	printf("Sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}
