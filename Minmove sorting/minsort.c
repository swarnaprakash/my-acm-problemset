#include<stdio.h>

#define M 105

int lis(int *a,int n)
{
	int list[M];
	int pos=1;
	int i,hi,lo,mid;
	
	list[0]=a[0];
	
	for(i=1;i<n;++i)
	{
		if(a[i]>=list[pos-1])
		{
			list[pos]=a[i];
			++pos;
			continue;
		}
		
		lo=0;hi=pos-1;
		while(lo<hi)
		{
			mid=lo+((hi-lo)>>1);
			if(a[i]<list[mid])
				hi=mid;
			else
				lo=mid+1;
		}
		list[lo]=a[i];
	}
	return pos;
}

int main()
{
	int a[M],n,i;
	
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		
		for(i=0;i<n;++i)
			scanf("%d",a+i);
			
		printf("%d\n",n-lis(a,n));
			
	}
	return 0;
}
