// submission by https://www.spoj.pl/KOPC09/users/rem during contest
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cassert>
#include <cctype>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int) (v).size())

typedef long long int64;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;

template<class T> T abs(T x) { return (x>0) ? x : -x; }
template<class T> T sqr(T x) { return x*x;            }

int n;
int a[131072];
int gr[262144];
int le[262144];

void build(int x, int l0, int r0) {
	if (l0 == r0) {
		gr[x] = a[l0];
		le[x] = -1;
	}
	else {
		int m = (l0 + r0) / 2;
		build(2 * x + 1, l0, m);
		build(2 * x + 2, m + 1, r0);
		gr[x] = max(gr[2 * x + 1], gr[2 * x + 2]);
		le[x] = max(max(le[2 * x + 1], le[2 * x + 2]), gr[2 * x + 1] + gr[2 * x + 2] - gr[x]);
	}
}

void up(int x, int l0, int r0, int k, int q) {
	if (k < l0 || k > r0) return;
	if (l0 == r0) {
		gr[x] = q;
		le[x] = -1;
	}
	else {
		int m = (l0 + r0) / 2;
		up(2 * x + 1, l0, m, k, q);
		up(2 * x + 2, m + 1, r0, k, q);
		gr[x] = max(gr[2 * x + 1], gr[2 * x + 2]);
		le[x] = max(max(le[2 * x + 1], le[2 * x + 2]), gr[2 * x + 1] + gr[2 * x + 2] - gr[x]);
	}
}

ii get(int x, int l0, int r0, int l, int r) {
	if (l > r0 || r < l0) return mp(-1, -1);
	if (l <= l0 && r >= r0) return mp(gr[x], le[x]);
	int m = (l0 + r0) / 2;
	ii r1 = get(2 * x + 1, l0, m, l, r);
	ii r2 = get(2 * x + 2, m + 1, r0, l, r);
	int u = max(r1.first, r2.first);
	int v = max(max(r1.second, r2.second), r1.first + r2.first - u);
	return mp(u, v);
}

int main() {
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	build(0, 0, 131071);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		char cmd[5];
		int a, b;
		scanf("%s%d%d", cmd, &a, &b);
		if (cmd[0] == 'U') {
			up(0, 0, 131071, a - 1, b);
		}
		else {
			ii res = get(0, 0, 131071, a - 1, b - 1);
			printf("%d\n", res.first + res.second);
		}
	}
	return 0;
}

