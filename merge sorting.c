#include<stdio.h>
#include<stdlib.h>
int * merge_sort(int *a,int *b,int n1,int n2)
{
	int i=0,j=0,k=0,*res;
	res=(int *)malloc((n1+n2)*sizeof(int));
	while(i<n1 && j<n2)
	{
		if(a[i]>b[j])
		{
			res[k]=b[j];
			j++;
		}
		else
		{
			res[k]=a[i];
			i++;
		}
		k++;
	}
	while(i<n1)
	{
		res[k++]=a[i++];
	}
	while(j<n2)
	{
		res[k++]=b[j++];
	}
	return res;
}
void main()
{
	int n1,n2,*res;
	scanf("%d%d",&n1,&n2);
	int a[n1],i,b[n2];
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d",&b[i]);
	}
	res=merge_sort(a,b,n1,n2);
	for(i=0;i<n1+n2;i++)
	{
		printf("%d ",res[i]);
	}
}

/*
4
6
1 5 6 10
i
2 3 4 20 100 200
j
*/


