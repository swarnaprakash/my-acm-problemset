// submission by https://www.spoj.pl/KOPC09/users/venkateshb/ during contest
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define INF int(1e9)

typedef long long LL;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef vector<string> VS;

const int mn=100005;
int m,n,ans;
int seen[5][mn];

bool visited(int i,int j){
	if((i==1 || i==m) && (j==1 || j==n))	return 1;
	if(i==1)	return seen[1][j];
	if(i==m)	return seen[3][j];
	if(j==1)	return seen[4][i];
	if(j==n)	return seen[2][i];
}

void visit(int i,int j){
	if(i==1)	seen[1][j]=1;
	if(i==m)	seen[3][j]=1;
	if(j==1)	seen[4][i]=1;
	if(j==n)	seen[2][i]=1;
}

int go(int i,int j,int dir){
	int ret=-1;
	do{
		visit(i,j);
		if(dir==1){
			int r=min(i-1,n-j);
			if(i-1<=n-j){
				i-=r;
				j+=r;
				dir=2;
			}
			else{
				j+=r;
				i-=r;
				dir=4;
			}		
		}
		else	if(dir==2){
			int r=min(m-i,n-j);
			if(m-i<=n-j){
				i+=r;
				j+=r;
				dir=1;
			}
			else{
				j+=r;
				i+=r;
				dir=3;
			}	
		}
		else	if(dir==3){
			int r=min(m-i,j-1);
			if(m-i<=j-1){
				i+=r;
				j-=r;
				dir=4;
			}
			else{
				j-=r;
				i+=r;
				dir=2;
			}	
		}
		else	if(dir==4){
			int r=min(i-1,j-1);
			if(i-1<=j-1){
				i-=r;
				j-=r;
				dir=3;
			}
			else{
				j-=r;
				i-=r;
				dir=1;
			}	
		}
		ret++;
	}while(!visited(i,j));
	return ret;
}

int main(){
	
	while(cin>>m>>n,m){
		m++;n++;
		int z=max(m,n);
		FOR(i,1,5)	FOR(j,1,z+1)	seen[i][j]=0;
		ans=go(1,1,2);
		FOR(i,1,5)	FOR(j,1,z+1)	seen[i][j]=0;
		ans+=go(1,n,3);
		FOR(i,1,5)	FOR(j,1,z+1)	seen[i][j]=0;
		ans+=go(m,1,1);
		FOR(i,1,5)	FOR(j,1,z+1)	seen[i][j]=0;
		ans+=go(m,n,4);
		cout<<ans<<endl;
	}
		
	//GI;
	return 0;
}
