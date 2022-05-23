#include<stdio.h>
int digit(int *arr,int n)
{
	int i,max=0,d;
	for(i=0;i<n;i++)
	{
		int temp;
		temp=arr[i];
		d=0;
		while(temp)
		{
			d++;
			temp/=10;
		}
		if(d>max)
		{
			max=d;
		}
	}
	return max;
}
void sort(int *arr,int max,int n)
{
	int x=1,i,j;
	while(max--)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((arr[i]/x)%10 < (arr[j]/x)%10)
				{
					arr[i]=arr[i]+arr[j];
					arr[j]=arr[i]-arr[j];
					arr[i]=arr[i]-arr[j];
				}
			}
		}
		x*=10;
	}
}
void radix_sort(int *arr,int n)
{
	int max=digit(arr,n);
	sort(arr,max,n);
}
void main()
{
	int i,n;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
/*
5
850 723 2 17 345

850 2 723 345 17

2 17 723 345 850

2 17 345 723 850

*/
