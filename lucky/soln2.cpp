// submission by https://www.spoj.pl/KOPC09/users/acrush/ during contest
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
//	freopen("input.txt","r",stdin);
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		int n;
		scanf("%d",&n);
		int R=0;
		for (int p=5;n>0;n/=2,p*=5)
			if (n%2==1)
				R+=p;
		printf("%d\n",R);
	}
	return 0;
}

