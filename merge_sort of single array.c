#include<stdio.h>
int res[100];
int merge_sort(int *arr,int n)
{
	int i=0,j=n/2,x=0;
	while(i<n/2 && j<n)
	{
		if(arr[i]>arr[j])
		{
			res[x]=arr[j];
			x++;
			j++;
		}
		else
		{
			res[x]=arr[i];
			x++;
			i++;
		}
		if(i==n/2)
		{
			while(x<n)
			{
				res[x++]=arr[j];
				j++;
			}
			break;
		}
		if(j==n)
		{
			while(x<n)
			{
				res[x++]=arr[i];
				i++;
			}
			break;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,res[100];
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	merge_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",res[i]);
	}
}
