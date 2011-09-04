//Author - Swarnaprakash.U
#include<stdio.h>
#include<assert.h>

main()
{
	int t;
	int tot,points;
	int x,y;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&tot,&points);
		assert(tot>=0 && tot<=20);
		assert(points>=-1000 && points<=1000);
		
		
		// x is the number of sucessful challenges
		// y is the number of unsucessful challenges
		// solve the set of linear eqn...
		//  x + y = tot
		// 50x -25y = points
		
		y = (50 * tot - points)/ 75;
		x=tot-y;
		
		// negative number of challenges doesnt make sense
		if( (50*x -25*y)!=points || x<0 || y<0)
			puts("INVALID DATA");
		else
			printf("%d\n",x);
		
		
		
	}
}