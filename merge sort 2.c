#include<stdio.h>
int merge_sort(int *arr,int n)
{
	int i=0,j=n/2,x=0;
	int static res[100];
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
	}
	while(x<n)
	{
		res[x++]=arr[j];	
		j++;
	}
	while(x<n)
	{
		res[x++]=arr[i];
		i++;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i,*res;
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	res=merge_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",res[i]);
	}
}
