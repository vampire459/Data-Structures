#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[],int n,int data)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(data==arr[mid])
			return mid;
		else if(data<=arr[mid])
			r=mid-1;
		else if(data>=arr[mid])
			l=mid+1;
	}
	if(l>r)
		printf("Element not found:");
		exit(0);
}
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
void main ()
{
	int arr[50],n,i,x,data,rslt;
	printf("No. of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        printf("\n Enter element no. %d : ", i+1);
		scanf("%d",&arr[i]);
	}
	Quicksort(arr,0,n-1);
    printf(" Elements in the array are:\t");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n Item to search: ");
	scanf("%d",&x);
	rslt = binarysearch(arr,n-1,x);
	printf("Element found at position no. : %d",rslt+1);
}
