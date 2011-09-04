//Author : santhanakrishnan
//Algorithm : brute force O(k^2)

main()
{
	int a,b,c,x,max,i,j,q,k,tc,t1,t2;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&k,&x);
		max=0;
		for(i=1;i<k;++i)
		{
			for(j=1;j<=k-i;++j)
			{
				q=k-i-j;
				if(q<=0)
					continue;
				t1=i-j-x;
				if(t1<0)
					t1=-t1;
				t2=j-q;
				if(t2<0)
					t2=-t2;
				t1*=t2;
				if(t1>max)
				{
					max=t1;
				}
				//printf("%d %d %d %d\n",i,j,q,t1);
			}
			//printf("%d\n",max);
		}
		printf("%d\n",max);
	}
	return 0;
	
}