#include<cstdio>
#include<algorithm>
#include<iostream>


using namespace std;

#define LL long long

LL volume(LL a[3],LL b[3])
{
	LL ans=1;
	int i;
	for(i=0;i<3;++i)
		ans*=b[i]-a[i];
		
	return ans;
}

LL common_volume(LL a[3],LL b[3],LL c[3],LL d[3])
{
	LL p,q;
	int i;
	LL ans=1;
		
	for(i=0;i<3;++i)
	{
		p=max(a[i],c[i]);
		q=min(b[i],d[i]);
		if(p>=q)
			return 0;
		ans*=q-p;
	}
	return ans;
}

main()
{
	int t;
	int i,j;
	LL v1[2][3],v2[2][3];
	LL ans;
	
	scanf("%d",&t);
		
	while(t--)
	{
		for(i=0;i<2;++i)
		{
			for(j=0;j<3;++j)
				cin>>v1[i][j];
			for(j=0;j<3;++j)
				cin>>v2[i][j];
		}
		
		ans=volume(v1[0],v2[0])+volume(v1[1],v2[1])-common_volume(v1[0],v2[0],v1[1],v2[1]);
		
		cout<<ans<<endl;
	}
	return 0;
}