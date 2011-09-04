#include<stdio.h>

#define M 505
#define N 10005

main()
{
	long t,n,p[M],w[M],m[M],e,f,nw,min[N],i,j;

	scanf("%ld",&t);

	for(;t>0;--t)
	{
		scanf("%ld %ld",&e,&f);
		scanf("%ld",&n);

		for(i=0;i<n;++i)
			scanf("%ld %ld",&p[i],&w[i]);

		nw=f-e;


		min[0]=0;

		for(i=1;i<=nw;++i)
		{
			min[i]=100000000;
			for(j=0;j<n;++j)
				if(w[j]<=i && ((min[i-w[j]]+p[j]) < min[i]))
					min[i]=min[i-w[j]]+p[j];
		}


		if(min[nw]!=100000000)
			printf("%ld\n",min[nw]);
		else
			printf("Impossible\n");


	}
	return 0;
}
