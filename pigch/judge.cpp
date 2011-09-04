// Author: Swarnaprakash
#include "spoj.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

// #define SPOJ_RV_NEGATIVE -1
// #define SPOJ_RV_NEGATIVE 0
//
// Version 2 of judge:
// Changes:
// Bug fix: 
// SPOJ_RV_NEGATIVE > SPOJ_RV_POSITIVE and vice versa
//

using namespace std;

struct coin {
	int value;
	int weight;

	coin(int value, int weight) {
		this->value = value;
		this->weight = weight;
	}

	bool operator<(const coin &x) const {
		return value * x.weight > weight * x.value;
	}
};

int greedy(int net_weight, vector<coin> &coins) {
	sort(coins.begin(),coins.end());
	int ans = 0;
	for (int i = 0;i < (int) coins.size(); ++i) {
		while (net_weight >= coins[i].weight) {
			net_weight -= coins[i].weight;
			ans += coins[i].value;
		}
	}

	if (net_weight == 0)
		return ans;
	else
		return -1;
}

int dp(int net_weight, vector<coin> &coins) {
	int ans[net_weight + 1];
	memset(ans, 0x3f, sizeof(ans));
	ans[0] = 0;
	for (int i = 1;i <= net_weight; ++i) {
		for (int j = 0; j < (int) coins.size(); ++j) {
			if (coins[j].weight <= i) ans[i] = min(ans[i], ans[i-coins[j].weight] + coins[j].value);
		}
	}
	if (ans[net_weight] == 0x3f3f3f3f)
		return -1;
	else
		return ans[net_weight];
}

int main() {
	spoj_init();
	// FILE* spoj_t_out = stdin;
	for (int t = 0;t < 2; ++t) {
		int e,f;
		if (fscanf(spoj_t_out,"%d %d",&e,&f) != 2) return SPOJ_RV_NEGATIVE;
		if (e < 1 || f < 1 || e > 200 || f > 200 || e >= f) return SPOJ_RV_NEGATIVE;

		int n;
		if (fscanf(spoj_t_out,"%d",&n) != 1) return SPOJ_RV_NEGATIVE;
		if (n < 1 || n > 10) return SPOJ_RV_NEGATIVE;

		vector<coin> coins;
		for (int i = 0; i < n; ++i) {
			int p,w;
			if (fscanf(spoj_t_out,"%d %d",&p,&w) != 2) return SPOJ_RV_NEGATIVE;
			if (p < 1 || w < 1 || p > 200 || w > 200) return SPOJ_RV_NEGATIVE;
			coins.push_back(coin(p,w));
		}
		int greedy_answer = greedy(f-e,coins);
		int dp_answer = dp(f-e,coins);
		if (greedy_answer == dp_answer) return SPOJ_RV_NEGATIVE;

		if (t == 0 && greedy_answer != -1) return SPOJ_RV_NEGATIVE;
		if (t == 1 && greedy_answer == -1) return SPOJ_RV_NEGATIVE;
	}
	return SPOJ_RV_POSITIVE;
}

