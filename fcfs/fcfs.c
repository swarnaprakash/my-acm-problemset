//Author Swarnaprakash
#include<stdio.h>
#include<assert.h>

int main()
{
	int n,i,ans,p;
	
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
			
		assert(n<=10000);
		
		ans=1;  // Time Quantum should atleast be 1 ms
		
		// answer is the maximum of the first N-1 numers !
		for(i=1;i<n;++i)
		{
			scanf("%d",&p);
			assert(p>=1 && p<=2000000000);
			if(p>ans)
				ans=p;
		}
		scanf("%d",&p);
		assert(p>=1 && p<=2000000000);
		
		
		printf("%d\n",ans);
	}
	return 0;
}
