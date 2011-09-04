// submission by https://www.spoj.pl/KOPC09/users/rem during contest
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int size(const T& c) { return (int)c.size(); }
template<typename T> inline void remin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void remax(T& a, T b) { if (b > a) a = b; }

int was[100000];
int wasCnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int m, n;
	while (scanf("%d%d", &m, &n) == 2 && m > 0) {
		++wasCnt;
		int x = 0;
		int res = -2;
		while (was[x] != wasCnt) {
			++res;
			was[x] = wasCnt;
			x = (x+m)%n;
		}
		x = 0;
		++wasCnt;
		while (was[x] != wasCnt) {
			++res;
			was[x] = wasCnt;
			x = (x+n)%m;
		}
		printf("%d\n", 4*res);
	}

	exit(0);
}
