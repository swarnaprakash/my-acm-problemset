#include<cstdio>
using namespace std;
bool prime[10000001];
int main()
{
	int cnt=0,i,j,p;
	prime[1]=0;
	for(i=2;i<=10000000;++i)
	{
		prime[i]=1;
	}
	p=2;
	j=0;
	while(p<=10000000)
	{
		++cnt;
		
		if(prime[cnt])
		{
			printf("%d\n",p);
		}
		for(j=2*p;j<=10000000;j+=p)
		{
			prime[j]=0;
		}
		++p;
		while(p<=10000000&&prime[p]==0)
			++p;
	}
	return 0;
}
 