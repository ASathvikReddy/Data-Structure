#include<stdio.h>
int min(int a,int b)
{
	if(a>b)
	return b;
	return a;
}
int fibi_search(int *arr,int n,int s)
{
	int i,fibi[100],l,m,k;
	l=-1,k=n-1;
	fibi[0]=0,fibi[1]=1;
	for(i=2;i<n;i++)
	{
		fibi[i]=fibi[i-1]+fibi[i-2];
	}
	while (fibi[k]!=0)
	{
		m=min(l+fibi[k-2],n-1);
		if(s==arr[m])
		{
			return 1;
		}
		else if(s>arr[m])
		{
			l=m;
			k=k-1;
		}
		else if(s<arr[m])
		{
			k=k-2;
		}
		return fibi_search(arr,n,s);
	}
	return 0;
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
	int s;
	scanf("%d",&s);
	if(fibi_search(arr,n,s))
	{
		printf("True");
	}
	else
	{
		printf("False");
	}
	
}

