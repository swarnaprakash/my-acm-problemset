// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define PB 			push_back
#define SZ(x)		((int)((x).size()))
#define TR(i,x) 	for(int i=0;i<(x).size();++i)
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;
#define INF			0x3f3f3f3f
#define M			20005

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int get(char c) {
	return c - '0';
}

int main() {
	int t;
	scanf("%d",&t);
	char a[M],b[M];
	while(t--) {
		scanf("%s %s",a,b);
		int n = strlen(a);
		int ans = 0;
		for(int i=0;i<n;++i) {
			int asum = 0;
			int bsum = 0;
			for(int j=i;j<n;++j) {
				asum += get(a[j]);
				bsum += get(b[j]);
				if(asum == bsum) ans = max(ans,j-i+1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

