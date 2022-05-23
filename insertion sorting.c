#include<stdio.h>
int insertion_sort(int *arr,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		j=i-1;
		temp=arr[i];
		while(arr[i]<arr[j])
		{
			temp=arr[i];
			while(temp<arr[j])
			{
				arr[j+1]=arr[j];
				arr[j]=temp;
				j--;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
/*
5
5 4 3 2 1
1 2 3 4 5

10
40 30 20 22 35 46 66 58 99 74
20 22 30 35 40 46 58 66 74 99
*/
