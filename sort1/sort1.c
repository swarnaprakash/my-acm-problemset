//Author - Swarnaprakash.U
#include<stdio.h>
#include<assert.h>
#include<string.h>

#define M 105

struct student
{
	char a[30];
	int age;
	int m[5];
	int total;
}s[M];

void swap(int *x,int *y)
{
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

main()
{
	int t,n,i,j;
	int v[M];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;++i)
		{
			s[i].total=0;
			scanf("%s %d",s[i].a,&s[i].age);
			for(j=0;j<5;++j)
			{
				scanf("%d",&s[i].m[j]);
				s[i].total+=s[i].m[j];
			}
		}
		
		for(i=0;i<n;++i)
			v[i]=i;
			
		//v[i] represents the index positions of sequence so that while
		//sorting we can just swap the index alone 
		
		
		//bubble sort  - use a stable sorting algorithm for this problem
		// selection sort is not stable
		for(i=0;i<n;++i)
			for(j=n-1;j>i;--j)
				{
					if(s[v[j-1]].total>s[v[j]].total)
						swap(&v[j-1],&v[j]);
				}
				
		for(i=0;i<n;++i)
		{
			printf("%s\n%d\n",s[v[i]].a,s[v[i]].age);
			for(j=0;j<5;++j)
			{
				if(j!=0)
					putchar(' ');
				printf("%d",s[v[i]].m[j]);
			}
			puts("");
		}
	}
}