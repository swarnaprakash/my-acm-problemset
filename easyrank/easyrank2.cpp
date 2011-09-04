//author : santhanakrishnan
//Algorithm : sorting O(n lg n)


#include<cstdio>
#include<string>
#include<algorithm>
#define N 10009
using namespace std;
struct team
{
	char name[12];
	int pts;
};
bool operator < (team a,team b)
{
	if(a.pts < b.pts)
		return 1;
	string s1,s2;
	if(a.pts==b.pts)
	{
		s1=a.name;
		s2=b.name;
		return s1>s2;
	}
	return 0;
}
main()
{
	int tc,i,n,crank,lrank;
	char contest_name[20];
	team a[N];
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",contest_name);
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%s %d",a[i].name,&a[i].pts);
		sort(a,a+n);
		crank=2;lrank=1;
		printf("%s RESULTS\n",contest_name);
		printf("%d %s\n",1,a[n-1].name);
		for(i=n-2;i>=0;--i)
		{
			if(a[i].pts==a[i+1].pts)
				printf("%d %s\n",lrank,a[i].name);
			else
			{
				printf("%d %s\n",crank,a[i].name);
				lrank=crank;
			}
			++crank;
			
		}
	}
	return 0;
}
