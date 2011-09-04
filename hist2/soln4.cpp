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
ll a[15];
ll opt[32768][15];
ll cnt[32768][15];

int main() {
	for (;;) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		memset(opt, 255, sizeof(opt));
		for (int i = 0; i < n; i++) {
			opt[1 << i][i] = 2 * (a[i] + 1);
			cnt[1 << i][i] = 1;
		}
		for (int i = 1; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					for (int k = 0; k < n; k++) {
						if ((i >> k) & 1) continue;
						ll delta = abs(a[j] - a[k]) + a[k] + 2 - a[j];
						if (opt[i][j] + delta == opt[i | (1 << k)][k]) {
							cnt[i | (1 << k)][k] += cnt[i][j];
						}
						if (opt[i][j] + delta > opt[i | (1 << k)][k]) {
							opt[i | (1 << k)][k] = opt[i][j] + delta;
							cnt[i | (1 << k)][k] = cnt[i][j];
						}
					}
				}
			}
		}
		ll best = -1;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (opt[(1 << n) - 1][i] == best) {
				ans += cnt[(1 << n) - 1][i];
			}
			if (opt[(1 << n) - 1][i] > best) {
				best = opt[(1 << n) - 1][i];
				ans = cnt[(1 << n) - 1][i];
			}
		}
		cout << best << " " << ans << "\n";
	}
	return 0;
}

