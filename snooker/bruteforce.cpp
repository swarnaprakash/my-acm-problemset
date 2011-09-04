// Author : Santhana Krishnan
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<iostream>
#include<vector>
#include<map>

#define LL long long
#define UI unsigned int
#define ULL unsigned long long
#define N 55
#define M 101
#define PB push_back
using namespace std;



int main()
{
	
	//clock_t t1=clock();
	while(1)
	{
		int m,n,sl,c,cx,cy,tx,ty,cons,i,ix,iy,x;
		char d;
		scanf("%d %d",&m,&n);
		
		if(m==0&&n==0)
			break;
		int cnt=0;
		sl=1;
		cons=0;
		d='F';
		cx=0;cy=0;
		c=0;
		
		
		for(i=1;i<m;++i)
		{
			ix=i;iy=0;
			cx=i;cy=0;
			sl=1;
			c=-ix;
			d='F';
			
			
		while(1)
		{
			
			if(sl==1&&d=='F')
			{
				sl=-1;
				ty=m+c;
				tx=n-c;
				if(ty <= n)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=n;
						d='F';
						c=cy+cx;
					}
				}
			}
			else if(sl==1&&d=='R')
			{
				sl=-1;
				ty=0+c;
				tx=0-c;
				if(ty >= 0)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=0;
						d='R';
						c=cy+cx;
					}
				}
			}
			else if(sl==-1&&d=='F')
			{
				sl=1;
				ty=-m+c;
				tx=0+c;
				if(ty >= 0)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy-cx;
				}
				else
				{
					if(tx <= m)//redundant condition
					{
						cx=tx;
						cy=0;
						d='F';
						c=cy-cx;
					}
				}
			}
			else
			{
				sl=1;
				ty=0+c;
				tx=-n+c;
				if(ty <= n)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy-cx;
				}
				else
				{
					if(tx >= 0)//redundant condition
					{
						cx=tx;
						cy=n;
						d='R';
						c=cy-cx;
					}
				}
			}
	
			
			if((cx==0&&cy==0)||(cx==m&&cy==0)||(cx==0&&cy==n)||(cx==m&&cy==n))
			{
				cnt++;
			//	printf("%d %d\n",ix,iy);
				break;
			}
			if(cx==ix&&cy==iy)
				break;
			
			
			//if(cnt>100)
			//break;
			
		}
		
		
			ix=i;iy=0;
			cx=i;cy=0;
			sl=-1;
			c=ix;
			d='R';
		while(1)
		{
			
			
			if(sl==1&&d=='F')
			{
				sl=-1;
				ty=m+c;
				tx=n-c;
				if(ty <= n)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=n;
						d='F';
						c=cy+cx;
					}
				}
			}
			else if(sl==1&&d=='R')
			{
				sl=-1;
				ty=0+c;
				tx=0-c;
				if(ty >= 0)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=0;
						d='R';
						c=cy+cx;
					}
				}
			}
			else if(sl==-1&&d=='F')
			{
				sl=1;
				ty=-m+c;
				tx=0+c;
				if(ty >= 0)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy-cx;
				}
				else
				{
					if(tx <= m)//redundant condition
					{
						cx=tx;
						cy=0;
						d='F';
						c=cy-cx;
					}
				}
			}
			else
			{
				sl=1;
				ty=0+c;
				tx=-n+c;
				if(ty <= n)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy-cx;
				}
				else
				{
					if(tx >= 0)//redundant condition
					{
						cx=tx;
						cy=n;
						d='R';
						c=cy-cx;
					}
				}
			}
	
			
			if((cx==0&&cy==0)||(cx==m&&cy==0)||(cx==0&&cy==n)||(cx==m&&cy==n))
			{
				//printf("%d %d\n",ix,iy);
				cnt++;
				break;
			}
			if(cx==ix&&cy==iy)
				break;
			
			
			//if(cnt>100)
			//break;
			
		}
			
		
		}
		
		for(i=1;i<n;++i)
		{
			
			ix=0;iy=i;
			cx=0;cy=i;
			sl=1;
			c=iy;
			d='F';
			
			
		while(1)
		{
			
			
			if(sl==1&&d=='F')
			{
				
				sl=-1;
				ty=m+c;
				tx=n-c;
				if(ty <= n)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						
						cx=tx;
						cy=n;
						d='F';
						c=cy+cx;
						
					}
				}
			}
			else if(sl==1&&d=='R')
			{
				sl=-1;
				ty=0+c;
				tx=0-c;
				if(ty >= 0)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=0;
						d='R';
						c=cy+cx;
					}
				}
			}
			else if(sl==-1&&d=='F')
			{
				sl=1;
				ty=-m+c;
				tx=0+c;
				if(ty >= 0)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy-cx;
				}
				else
				{
					if(tx <= m)//redundant condition
					{
						cx=tx;
						cy=0;
						d='F';
						c=cy-cx;
					}
				}
			}
			else  if(sl==-1&&d=='R')
			{
				sl=1;
				ty=0+c;
				tx=-n+c;
				if(ty <= n)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy-cx;
				}
				else
				{
					if(tx >= 0)//redundant condition
					{
						cx=tx;
						cy=n;
						d='R';
						c=cy-cx;
					}
				}
			}
			
			if((cx==0&&cy==0)||(cx==m&&cy==0)||(cx==0&&cy==n)||(cx==m&&cy==n))
			{
				//printf("%d %d\n fl",ix,iy);
				cnt++;
				break;
			}
			
			
			if(cx==ix&&cy==iy)
				break;
			
		
			
		}
		
		
			ix=0;iy=i;
			cx=0;cy=i;
			sl=-1;
			c=iy;
			d='F';
		while(1)
		{
			
			if(sl==1&&d=='F')
			{
				sl=-1;
				ty=m+c;
				tx=n-c;
				if(ty <= n)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=n;
						d='F';
						c=cy+cx;
					}
				}
			}
			else if(sl==1&&d=='R')
			{
				sl=-1;
				ty=0+c;
				tx=0-c;
				if(ty >= 0)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy+cx;
				}
				else
				{
					if(tx <= m)//redundant
					{
						cx=tx;
						cy=0;
						d='R';
						c=cy+cx;
					}
				}
			}
			else if(sl==-1&&d=='F')
			{
				sl=1;
				ty=-m+c;
				tx=0+c;
				if(ty >= 0)
				{
					cx=m;
					cy=ty;
					d='R';
					c=cy-cx;
				}
				else
				{
					if(tx <= m)//redundant condition
					{
						cx=tx;
						cy=0;
						d='F';
						c=cy-cx;
					}
				}
			}
			else
			{
				sl=1;
				ty=0+c;
				tx=-n+c;
				if(ty <= n)
				{
					cx=0;
					cy=ty;
					d='F';
					c=cy-cx;
				}
				else
				{
					if(tx >= 0)//redundant condition
					{
						cx=tx;
						cy=n;
						d='R';
						c=cy-cx;
					}
				}
			}

			
			if((cx==0&&cy==0)||(cx==m&&cy==0)||(cx==0&&cy==n)||(cx==m&&cy==n))
			{
				
				cnt++;
				break;
			}
			if(cx==ix&&cy==iy)
				break;
			
			
			//if(cnt>100)
			//break;
			
		}
			
		
		}
		
		printf("%d\n",cnt*2);
		
	}
	//printf("%lf\n",(double)(clock()-t1)/(CLOCKS_PER_SEC));
	return 0;
}
