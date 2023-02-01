#include<stdio.h>

int Quicksort(int arr[],int start,int end)
{
	int i,j,pivot,temp;
	if(start<end)
	{
		pivot=start;
		i=start;
		j=end;
		while(i<j)
		{
			while(arr[i]<=arr[pivot]&&i<end)
				i++;
			while(arr[j]>arr[pivot]&&j>start)
				j--;
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		Quicksort(arr,start,j-1);
		Quicksort(arr,j+1,end);
	}
}
void main()
{
	int i,n,arr[40];
	printf("No. of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        printf("\n Enter element no. %d : ", i+1);
		scanf("%d",&arr[i]);
	}
	Quicksort(arr,0,n-1);
	printf("Sorted Elements are:\t");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
}
