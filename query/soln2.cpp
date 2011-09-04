// submission by https://www.spoj.pl/KOPC09/users/john_jones/ during contest
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 150000 + 50;

int max1[maxn*2],max2[maxn*2];
int a[maxn];
int n,m,x,y;
char s[10];

#define address(l,r) (((l)+(r))|((l)!=(r)))

void merge(int l,int r,int p)
{
	if(max1[l]>max1[r])
	{
		max1[p] = max1[l];
		max2[p] = max(max2[l],max1[r]);
	}
	else
	{
		max1[p] = max1[r];
		max2[p] = max(max1[l],max2[r]);
	}
}

void buildtree(int l,int r)
{
	int mid = (l+r)/2;
	int pos = ((l+r)|(l!=r));
	if(l==r)
	{
		max1[pos] = a[l];
		max2[pos] = -1;
		return;
	}
	buildtree(l,mid);
	buildtree(mid+1,r);
	int cl = address(l,mid), cr = address(mid+1,r);
	merge(cl,cr,pos);
}

void query(int l,int r,int L,int R,int &Max1,int &Max2)
{
	int pos = address(L,R);
	int mid = (L+R)/2;
	if(L>R || R<l || L>r) return;
	if(l<=L && R<=r)
	{
		if(max1[pos]>Max1)
		{
			Max2 = Max1;
			Max1 = max1[pos];
			if(max2[pos]>Max2)
			{
				Max2 = max2[pos];
			}
		}
		else if(max1[pos]>Max2)
			Max2 = max1[pos];
		return;
	}
	query(l,r,L,mid,Max1,Max2);
	query(l,r,mid+1,R,Max1,Max2);
}

void change(int p,int x,int L,int R)
{
	int pos = address(L,R);
	int mid = (L+R)/2;
	if(L==R)
	{
		max1[pos] = x;
		max2[pos] = -1;
		return;
	}
	if(p<=mid) change(p,x,L,mid);
	else change(p,x,mid+1,R);
	int cl = address(L,mid), cr = address(mid+1,R);
	merge(cl,cr,pos);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	buildtree(1,n);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s%d%d",&s,&x,&y);
		if(*s=='Q')
		{
			int max1 = -1, max2 = -1;
			query(x,y,1,n,max1,max2);
			printf("%d\n",max1+max2);
		}
		else if(*s=='U')
		{
			change(x,y,1,n);
		}
	}
	return 0;
}

